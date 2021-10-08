#include "denoiser.h"

Denoiser::Denoiser() : m_useTemportal(false) {}


//联合双边滤波
Buffer2D<Float3> Denoiser::Filter(const FrameInfo &frameInfo) {
    int height = frameInfo.m_beauty.m_height;
    int width = frameInfo.m_beauty.m_width;
    Buffer2D<Float3> filteredImage = CreateBuffer2D<Float3>(width, height);
    int kernelRadius = 16;

//是OpenMP中的一个指令，表示接下来的for循环将被多线程执行，另外每次循环之间不能有关系 collapse(2) 两重循环
#pragma omp parallel for collapse(2)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // TODO: Joint bilateral filter

            int x_start = std::max(0, x - kernelRadius);
            int x_end = std::min(width - 1, x + kernelRadius);
            int y_start = std::max(0, y - kernelRadius);
            int y_end = std::min(height - 1, y + kernelRadius);
            Float3 resColor;
            auto weight_sum = .0f;
            auto &center_postion = frameInfo.m_position(x, y);
            auto &center_normal = frameInfo.m_normal(x, y);
            auto &center_color = frameInfo.m_beauty(x, y);
            for (int m = x_start; m <= x_end; m++) {
                for (int n = y_start; n <= y_end; n++) {
                    if (n == x && y == m) {
                        weight_sum += 1.0f;
                        resColor += center_color;
                        continue;
                    }

                    auto &curr_postion = frameInfo.m_position(m, n);
                    auto &curr_normal = frameInfo.m_normal(m, n);
                    auto &curr_color = frameInfo.m_beauty(m, n);

                    float plane_dis = .0f;
                    auto position_dis =
                        SqrDistance(center_postion, curr_postion) / (2.0f * m_sigmaCoord);
                    auto color_dis =
                        SqrDistance(center_color, curr_color) / (2.0f * m_sigmaColor);
                    auto normal_dis = SafeAcos(Dot(center_normal, curr_normal)) /
                                      (2.0f * m_sigmaNormal);
                    if (position_dis != 0.f) {
                        plane_dis =
                            Dot(center_normal, Normalize(curr_postion - center_postion));
                    }
                    plane_dis = plane_dis * plane_dis / (2.0f * m_sigmaPlane);
                    float weight =
                        std::exp(-(plane_dis + position_dis + color_dis + normal_dis));
                    weight_sum += weight;
                    resColor += curr_color * weight;
                }
            }

            // filteredImage(x, y) = frameInfo.m_beauty(x, y);
            filteredImage(x, y) = resColor / weight_sum;
        }
    }
    return filteredImage;
}



// &frameInfo 当前帧的信息 当前帧每个像素在上一帧的对应点，并将上一帧的结果投影到当前帧
//这帧的world用逆矩阵回到模型空间再乘上上一帧的模型变换到上一帧的世界空间 再投影到屏幕上 
//公式 Screeni?1 = Pi?1Vi?1Mi?1Mi?1Worldi
void Denoiser::Reprojection(const FrameInfo &frameInfo) {
    int height = m_accColor.m_height;
    int width = m_accColor.m_width;
    Matrix4x4 preWorldToScreen =
        m_preFrameInfo.m_matrix[m_preFrameInfo.m_matrix.size() - 1];
    Matrix4x4 preWorldToCamera =
        m_preFrameInfo.m_matrix[m_preFrameInfo.m_matrix.size() - 2];
#pragma omp parallel for collapse(2)
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // TODO: Reproject
            m_valid(x, y) = false;
            m_misc(x, y) = Float3(0.f);
            int id = frameInfo.m_id(x,y);
            if (id == -1) {
                continue;
            }
            Matrix4x4 world_to_local = Inverse(frameInfo.m_matrix[id]);
            const Matrix4x4 &pre_local_to_world = m_preFrameInfo.m_matrix[id];
            auto postion = frameInfo.m_position(x,y);
            auto screen_position = preWorldToScreen(pre_local_to_world(world_to_local(postion, Float3::EType::Point),
                                   Float3::EType::Point),
                Float3::EType::Point);
            if (screen_position.x < 0 || screen_position.x>=width||
                screen_position.y < 0 || screen_position.y >= height) {
                continue;
            } else {
                int pre_x = screen_position.x;
                int pre_y = screen_position.y;
                int pre_id = m_preFrameInfo.m_id(pre_x,pre_y);
                if (pre_id==id) {
                    m_valid(x, y) = true;
                    m_misc(x, y) = m_accColor(pre_x,pre_y);
                }
            }
        }
    }
    std::swap(m_misc, m_accColor);
}


//时间的积累  curFilteredColor降噪过的当前帧图像
void Denoiser::TemporalAccumulation(const Buffer2D<Float3> &curFilteredColor) {
    int height = m_accColor.m_height;
    int width = m_accColor.m_width;
    int kernelRadius = 3;
#pragma omp parallel for
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // TODO: Temporal clamp
            Float3 color = m_accColor(x, y);
            // TODO: Exponential moving average
            float alpha = 1.0f;
            m_misc(x, y) = Lerp(color, curFilteredColor(x, y), alpha);

        }
    }
    std::swap(m_misc, m_accColor);
}



void Denoiser::Init(const FrameInfo &frameInfo, const Buffer2D<Float3> &filteredColor) {
    m_accColor.Copy(filteredColor);
    int height = m_accColor.m_height;
    int width = m_accColor.m_width;
    m_misc = CreateBuffer2D<Float3>(width, height);
    m_valid = CreateBuffer2D<bool>(width, height);
}



void Denoiser::Maintain(const FrameInfo &frameInfo) { m_preFrameInfo = frameInfo; }



Buffer2D<Float3> Denoiser::ProcessFrame(const FrameInfo &frameInfo) {
    // Filter current frame
    Buffer2D<Float3> filteredColor;
    filteredColor = Filter(frameInfo);

    // Reproject previous frame color to current
    if (m_useTemportal) {
        Reprojection(frameInfo);
        TemporalAccumulation(filteredColor);
    } else {
        Init(frameInfo, filteredColor);
    }

    // Maintain
    Maintain(frameInfo);
    if (!m_useTemportal) {
        m_useTemportal = true;
    }
    return m_accColor;
}


