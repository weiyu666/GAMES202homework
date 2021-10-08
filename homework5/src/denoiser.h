#pragma once

#define NOMINMAX
#include <string>
#include <algorithm>

#include "filesystem/path.h"

#include "util/image.h"
#include "util/mathutil.h"

struct FrameInfo {
  public:
    Buffer2D<Float3> m_beauty;  //代表渲染结果
    Buffer2D<float> m_depth;    //代表每个像素的深度值  
    Buffer2D<Float3> m_normal;  //代表每个像素的法线向量 (模长为 1)
    Buffer2D<Float3> m_position;    //代表每个像素在世界坐标系中的位置
    Buffer2D<float> m_id;           //代表每个像素对应的物体标号，对于没有物体的部分 (背景) 其标号为 - 1
    std::vector<Matrix4x4> m_matrix;        //
};


//维护住历史帧的信息
class Denoiser {
  public:
    Denoiser();

    void Init(const FrameInfo &frameInfo, const Buffer2D<Float3> &filteredColor);
    void Maintain(const FrameInfo &frameInfo);

    //当前帧的信息通过函数 Denoiser::ProcessFrame(FrameInfo) 传入，并得到降噪后的图像
    void Reprojection(const FrameInfo &frameInfo);
    void TemporalAccumulation(const Buffer2D<Float3> &curFilteredColor);
    Buffer2D<Float3> Filter(const FrameInfo &frameInfo);

    Buffer2D<Float3> ProcessFrame(const FrameInfo &frameInfo);

  public:
    FrameInfo m_preFrameInfo;
    Buffer2D<Float3> m_accColor;
    Buffer2D<Float3> m_misc;
    Buffer2D<bool> m_valid;
    bool m_useTemportal;

    float m_alpha = 0.2f;
    float m_sigmaPlane = 0.1f;
    float m_sigmaColor = 0.6f;  //  pink-room 10.6 box 0.6
    float m_sigmaNormal = 0.1f;
    float m_sigmaCoord = 32.0f;
    float m_colorBoxK = 1.0f;
};