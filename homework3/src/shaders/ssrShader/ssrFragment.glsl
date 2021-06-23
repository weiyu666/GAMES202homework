#ifdef GL_ES
precision highp float;
#endif

uniform vec3 uLightDir;
uniform vec3 uCameraPos;
uniform vec3 uLightRadiance;
uniform sampler2D uGDiffuse;
uniform sampler2D uGDepth;
uniform sampler2D uGNormalWorld;
uniform sampler2D uGShadow;
uniform sampler2D uGPosWorld;

varying mat4 vWorldToScreen;
varying highp vec4 vPosWorld;

#define M_PI 3.1415926535897932384626433832795
#define TWO_PI 6.283185307
#define INV_PI 0.31830988618
#define INV_TWO_PI 0.15915494309


float Rand1(inout float p) {
  p = fract(p * .1031);
  p *= p + 33.33;
  p *= p + p;
  return fract(p);
}

vec2 Rand2(inout float p) {
  return vec2(Rand1(p), Rand1(p));
}

//初始化随机数得到随机数的状态 s
float InitRand(vec2 uv) {
	vec3 p3  = fract(vec3(uv.xyx) * .1031);
  p3 += dot(p3, p3.yzx + 33.33);
  return fract((p3.x + p3.y) * p3.z);
}

vec3 SampleHemisphereUniform(inout float s, out float pdf) {
  vec2 uv = Rand2(s);
  float z = uv.x;
  float phi = uv.y * TWO_PI;
  float sinTheta = sqrt(1.0 - z*z);
  vec3 dir = vec3(sinTheta * cos(phi), sinTheta * sin(phi), z);
  pdf = INV_TWO_PI;
  return dir;
}

vec3 SampleHemisphereCos(inout float s, out float pdf) {
  vec2 uv = Rand2(s);
  float z = sqrt(1.0 - uv.x);
  float phi = uv.y * TWO_PI;
  float sinTheta = sqrt(uv.x);
  vec3 dir = vec3(sinTheta * cos(phi), sinTheta * sin(phi), z);
  pdf = z * INV_PI;
  return dir;
}

void LocalBasis(vec3 n, out vec3 b1, out vec3 b2) {
  float sign_ = sign(n.z);
  if (n.z == 0.0) {
    sign_ = 1.0;
  }
  float a = -1.0 / (sign_ + n.z);
  float b = n.x * n.y * a;
  b1 = vec3(1.0 + sign_ * n.x * n.x * a, sign_ * b, -sign_ * n.x);
  b2 = vec3(b, sign_ + n.y * n.y * a, -n.y);
}

vec4 Project(vec4 a) {
  return a / a.w;
}

float GetDepth(vec3 posWorld) {
  float depth = (vWorldToScreen * vec4(posWorld, 1.0)).w;
  return depth;
}

/*
 * Transform point from world space to screen space([0, 1] x [0, 1])
 * 获取屏幕空间的坐标 的参数为世界坐标系中的位置
 *
 */
vec2 GetScreenCoordinate(vec3 posWorld) {
  vec2 uv = Project(vWorldToScreen * vec4(posWorld, 1.0)).xy * 0.5 + 0.5;
  return uv;
}

float GetGBufferDepth(vec2 uv) {
  float depth = texture2D(uGDepth, uv).x;
  if (depth < 1e-2) {
    depth = 1000.0;
  }
  return depth;
}

vec3 GetGBufferNormalWorld(vec2 uv) {
  vec3 normal = texture2D(uGNormalWorld, uv).xyz;
  return normal;
}

vec3 GetGBufferPosWorld(vec2 uv) {
  vec3 posWorld = texture2D(uGPosWorld, uv).xyz;
  return posWorld;
}

float GetGBufferuShadow(vec2 uv) {
  float visibility = texture2D(uGShadow, uv).x;
  return visibility;
}

vec3 GetGBufferDiffuse(vec2 uv) {
  vec3 diffuse = texture2D(uGDiffuse, uv).xyz;
  diffuse = pow(diffuse, vec3(2.2));
  return diffuse;
}

/*
 * Evaluate diffuse bsdf value.
 *
 * wi, wo are all in world space.
 * uv is in screen space, [0, 1] x [0, 1].
 * wi,wo入射方向和出射方向
 */
vec3 EvalDiffuse(vec3 wi, vec3 wo, vec2 uv) {
  // vec3 L = vec3(0.0);
  vec3 albedo = GetGBufferDiffuse(uv);//获取漫反射率
  vec3 normal =normalize(GetGBufferNormalWorld(uv));//获取法线
  float cosTheta =max(0.0,dot(normalize(wi),normal));//漫反射夹角不能为负! 不然间接光存在黑边
  return albedo *INV_PI *cosTheta;
}

/*
 * Evaluate directional light with shadow map
 * uv is in screen space, [0, 1] x [0, 1].
 *返回值为着色点位于 uv 处得到的光源的辐射度，并且需要考虑遮挡关系 (Shadow Map)。
 */
vec3 EvalDirectionalLight(vec2 uv) {
  //vec3 Le = vec3(0.0);
  float visibility  = GetGBufferuShadow(uv);//比较深度得到了可见性信息
  return uLightRadiance *visibility;
}

/*
*RayMarch 函数的返回值为是否相交，当相交的时候需要将参数 hitPos设置为交点
*参数 ori 和 dir 为世界坐标系中的值，分别代表光线的起点和方向
*/
bool RayMarch(vec3 ori, vec3 dir, out vec3 hitPos) {
  float step =0.05;
  vec3 endPoint =ori;
 
  for(int i=0;i<40;i++){
    vec3 testPoint = endPoint+step * dir;
    float testDepth = GetDepth(testPoint);
    float  bufferDepth = GetGBufferDepth(GetScreenCoordinate(testPoint));
    if(step > 40.0){
      return false;
    }else if(testDepth -bufferDepth > 1e-6){
      hitPos = testPoint;
      return true;
    }else if( testDepth < bufferDepth ){
      endPoint =testPoint;
    }else if( testDepth > bufferDepth){
    }

  }
  return false;
}

#define SAMPLE_NUM 2

void main() {
  float s = InitRand(gl_FragCoord.xy);

// vec3 worldPos=vPosWorld.xyz;
// vec2 uv0=GetScreenCoordinate(worldPos);
// vec3 directLight=EvalDirectionalLight(uv0);
// vec3 result +=directLight;
// vec3 inDirLRes=vec3(0.0);

  vec2 uv=GetScreenCoordinate(vPosWorld.xyz);
  vec3 wi=uLightDir;
  vec3 wo=uCameraPos-vPosWorld.xyz;
  vec3 N=normalize(GetGBufferNormalWorld(uv));
  vec3 L = vec3(0.0);//总光照
  vec3 L_indirect=vec3(0.0);
  L=EvalDiffuse(wi,wo,uv)*EvalDirectionalLight(uv); //直接光

  for(int i=0;i<SAMPLE_NUM;i++){
    float pdf;//採樣的概率
    Rand1(s);
    vec3 dir=SampleHemisphereUniform(s,pdf);//返回一個局部坐標系

    vec3 b1,b2; 
    vec3 hitPos;//间接光照第一次反射的点，之后反射到我们要着色的像素点上
    LocalBasis(N,b1,b2);//根据法线n构建局部坐标系

    dir = normalize(mat3(b1,b2,N)*dir);//将采样获取的局部坐标转化到世界坐标
    if(RayMarch(vPosWorld.xyz,dir,hitPos)){
    vec3 woNew=vPosWorld.xyz -hitPos;
    vec2 uv1=GetScreenCoordinate(hitPos);
    L_indirect +=EvalDiffuse(dir,wo,uv)/pdf *EvalDiffuse(wi,dir,uv1)*EvalDirectionalLight(uv1);
  }

  L_indirect =L_indirect/float(SAMPLE_NUM);
  L+=L_indirect;
  }


 // L = GetGBufferDiffuse(GetScreenCoordinate(vPosWorld.xyz));
  vec3 color = pow(clamp(L, vec3(0.0), vec3(1.0)), vec3(1.0 / 2.2));//clamp 三个参数中大小处在中间的那个值
  gl_FragColor = vec4(vec3(color.rgb), 1.0);
}
