#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <fstream>
#include <random>
#include "vec.h"

#define M_PI 3.14159265358979323846

#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image_write.h"

const int resolution = 128;

typedef struct samplePoints {
    std::vector<Vec3f> directions;
	std::vector<float> PDFs;
}samplePoints;

samplePoints squareToCosineHemisphere(int sample_count){
    samplePoints samlpeList;
    const int sample_side = static_cast<int>(floor(sqrt(sample_count)));

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> rng(0.0, 1.0);
    for (int t = 0; t < sample_side; t++) {
        for (int p = 0; p < sample_side; p++) {
            double samplex = (t + rng(gen)) / sample_side;
            double sampley = (p + rng(gen)) / sample_side;
            
            double theta = 0.5f * acos(1 - 2*samplex);
            double phi =  2 * M_PI * sampley;
            Vec3f wi = Vec3f(sin(theta) * cos(phi), sin(theta) * sin(phi), cos(theta));
            float pdf = wi.z / PI;
            
            samlpeList.directions.push_back(wi);
            samlpeList.PDFs.push_back(pdf);
        }
    }
    return samlpeList;
}

float DistributionGGX(Vec3f N, Vec3f H, float roughness)
{
    float a = roughness*roughness;
    float a2 = a*a;
    float NdotH = std::max(dot(N, H), 0.0f);
    float NdotH2 = NdotH*NdotH;

    float nom   = a2;
    float denom = (NdotH2 * (a2 - 1.0) + 1.0);
    denom = PI * denom * denom;

    return nom / std::max(denom, 0.0001f);
}

float GeometrySchlickGGX(float NdotV, float roughness) {
    float a = roughness;
    float k = (a * a) / 2.0f;

    float nom = NdotV;
    float denom = NdotV * (1.0f - k) + k;

    return nom / denom;
}

float GeometrySmith(float roughness, float NoV, float NoL) {
    float ggx2 = GeometrySchlickGGX(NoV, roughness);
    float ggx1 = GeometrySchlickGGX(NoL, roughness);

    return ggx1 * ggx2;
}

/*
*roughness  粗糙度
* V 视点
*/
Vec3f IntegrateBRDF(Vec3f V, float roughness, float NdotV) {
    float A = 0.0;
    float B = 0.0;
    float C = 0.0;
    const int sample_count = 1024;  //采样数
    Vec3f N = Vec3f(0.0, 0.0, 1.0);
    
    //cos 加权在半球上采样入射光方向 i
    samplePoints sampleList = squareToCosineHemisphere(sample_count);
    for (int i = 0; i < sample_count; i++) {
      // TODO: To calculate (fr * ni) / p_o here
        //L 为光源
        Vec3f L = sampleList.directions[i];
        auto pdf = sampleList.PDFs[i];  //概率分布函数
        //函数D： 法线分布函数(Normal Distribution Function)，其代表了所有微观角度下微小镜面法线的分布情况，
        //粗糙表面法线分布相对均匀，光滑表面法线分布相对集中 (这种解释可能会有些抽象，后面会给出更加直观的物理上的解释)
        auto D = DistributionGGX(N,normalize(V+L),roughness);   
        //函数G：几何函数(Geometry Function)，描述了微平面自遮挡的属性。当一个平面相对比较粗糙的时候，
        //平面表面上的微平面有可能挡住其他的微平面从而减少表面所反射的光线。
        auto G = GeometrySmith(roughness,NdotV,dot(N,L));
        //函数F：菲涅尔方程(Fresnel Rquation)，描述了物体表面在不同入射光角度下反射光线所占的比率
        auto F = D*G/(4.0f*NdotV* pdf);
        A += F;
        B += F;
        C += F;
    }

    return {A / sample_count, B / sample_count, C / sample_count};
}

int main() {
    uint8_t data[resolution * resolution * 3];
    float step = 1.0 / resolution;
    for (int i = 0; i < resolution; i++) {
        for (int j = 0; j < resolution; j++) {
            float roughness = step * (static_cast<float>(i) + 0.5f);
            float NdotV = step * (static_cast<float>(j) + 0.5f);
            Vec3f V = Vec3f(std::sqrt(1.f - NdotV * NdotV), 0.f, NdotV);

            Vec3f irr = IntegrateBRDF(V, roughness, NdotV);

            data[(i * resolution + j) * 3 + 0] = uint8_t(irr.x * 255.0);
            data[(i * resolution + j) * 3 + 1] = uint8_t(irr.y * 255.0);
            data[(i * resolution + j) * 3 + 2] = uint8_t(irr.z * 255.0);
        }
    }
    stbi_flip_vertically_on_write(true);
    stbi_write_png("GGX_E_MC_LUT.png", resolution, resolution, 3, data, resolution * 3);
    
    std::cout << "Finished precomputed!" << std::endl;
    return 0;
}