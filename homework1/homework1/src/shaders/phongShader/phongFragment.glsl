#ifdef GL_ES
precision mediump float;  //低精度
#endif

// Phong related variables
uniform sampler2D uSampler;
uniform vec3 uKd;
uniform vec3 uKs;
uniform vec3 uLightPos;
uniform vec3 uCameraPos;
uniform vec3 uLightIntensity;

varying highp vec2 vTextureCoord;
varying highp vec3 vFragPos;
varying highp vec3 vNormal;

// Shadow map related variables
#define NUM_SAMPLES 20
#define BLOCKER_SEARCH_NUM_SAMPLES NUM_SAMPLES
#define PCF_NUM_SAMPLES NUM_SAMPLES
#define NUM_RINGS 10

#define EPS 1e-3
#define PI 3.141592653589793
#define PI2 6.283185307179586

uniform sampler2D uShadowMap;

varying vec4 vPositionFromLight;

float Bias();
float PCF(sampler2D shadowMap, vec4 coords);
float findBlocker( sampler2D shadowMap,  vec2 uv, float zReceiver ) ;
float useShadowMap(sampler2D shadowMap, vec4 shadowCoord);
float PCF_Internal(sampler2D shadowMap,vec2 shadowUV,float flagDepth,float simpleScale);

highp float rand_1to1(highp float x ) { 
  // -1 -1
  return fract(sin(x)*10000.0);
}

highp float rand_2to1(vec2 uv ) { 
  // 0 - 1
	const highp float a = 12.9898, b = 78.233, c = 43758.5453;
	highp float dt = dot( uv.xy, vec2( a,b ) ), sn = mod( dt, PI );
	return fract(sin(sn) * c);
}

//对于的pack 编码这里是解码
float unpack(vec4 rgbaDepth) {
    const vec4 bitShift = vec4(1.0, 1.0/256.0, 1.0/(256.0*256.0), 1.0/(256.0*256.0*256.0));
    float depth =dot(rgbaDepth, bitShift) ;
    //shadow map 没有深度值的地方默认是0 导致的有噪点
    if(abs(depth)<EPS){
      depth=1.0;
    }

    return  depth;
}

vec2 poissonDisk[NUM_SAMPLES];

void poissonDiskSamples( const in vec2 randomSeed ) {

  float ANGLE_STEP = PI2 * float( NUM_RINGS ) / float( NUM_SAMPLES );
  float INV_NUM_SAMPLES = 1.0 / float( NUM_SAMPLES );

  float angle = rand_2to1( randomSeed ) * PI2;
  float radius = INV_NUM_SAMPLES;
  float radiusStep = radius;

  for( int i = 0; i < NUM_SAMPLES; i ++ ) {
    poissonDisk[i] = vec2( cos( angle ), sin( angle ) ) * pow( radius, 0.75 );
    radius += radiusStep;
    angle += ANGLE_STEP;
  }
}

void uniformDiskSamples( const in vec2 randomSeed ) {

  float randNum = rand_2to1(randomSeed);
  float sampleX = rand_1to1( randNum ) ;
  float sampleY = rand_1to1( sampleX ) ;

  float angle = sampleX * PI2;
  float radius = sqrt(sampleY);

  for( int i = 0; i < NUM_SAMPLES; i ++ ) {
    poissonDisk[i] = vec2( radius * cos(angle) , radius * sin(angle)  );

    sampleX = rand_1to1( sampleY ) ;
    sampleY = rand_1to1( sampleX ) ;

    angle = sampleX * PI2;
    radius = sqrt(sampleY);
  }
}

//遮挡物平均深度的计算
float findBlocker( sampler2D shadowMap,  vec2 uv, float zReceiver ) {
  poissonDiskSamples(uv);
  float totalDepth=0.0;
  int blockCount =0;

  for(int i=0;i<NUM_SAMPLES; i ++){
    vec2 simpleUV = uv +poissonDisk[i]/float(2048) *50.0;
    float shadowMapDepth = unpack(vec4(texture2D(uShadowMap,simpleUV).rgb,1.0));
    if(zReceiver > (shadowMapDepth+0.003)){
      totalDepth += shadowMapDepth;
      blockCount +=1;
    }
  }


  //没有遮挡
  if(blockCount ==0){
    return -1.0;
  }

  //完全遮挡
  if(blockCount==NUM_SAMPLES){
    return 2.0;
  }

	return totalDepth/float( blockCount );
}


float Bias(){
 //解决shadow bias 因为shadow map的精度有限，当要渲染的fragment在light space中距Light很远的时候，就会有多个附近的fragement会samper shadow map中同一个texel,但是即使这些fragment在camera view space中的深度值z随xy变化是值变化是很大的，
  //但他们在light space 中的z值(shadow map中的值)却没变或变化很小，这是因为shadow map分辨率低，采样率低导致精度低，不能准确的记录这些细微的变化
 
  // calculate bias (based on depth map resolution and slope)  vec3 lightDir = normalize(uLightPos);
  vec3 lightDir = normalize(uLightPos);
  vec3 normal = normalize(vNormal);
  float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
  return  bias;
}


//以及你没图像是因为那个随机分布的范围是-1到1，直接在某个像素点计算的话直接飞出uv坐标外了，你要乘一个单位偏移，根据你的shadowmap的像素来，
//比如2048像素的你就可以设置一个unit offset=1/2048 他就会在某个像素的周围，按照filter size为半径找随机采样点
float PCF(sampler2D shadowMap, vec4 coords) {
 float  bias = Bias();
 float  visibility =0.0;
 float  currentDepth =coords.z;
 float  filterSize=  1.0 / 2048.0 * 10.0;
 poissonDiskSamples(coords.xy);
 for(int i=0;i<NUM_SAMPLES;i++){
    vec2  texcoords =poissonDisk[i]*filterSize+coords.xy;
    float  closesDepth =unpack(vec4(texture2D(shadowMap,texcoords).xyz,1.0));
    visibility += closesDepth  < currentDepth -bias ?0.0:1.0;
 }

return visibility/float(NUM_SAMPLES);
}


// calculate shadow 询sampler2d这个材质上记录的某一个点的深度值
float useShadowMap(sampler2D shadowMap, vec4 shadowCoord){
  float  bias = Bias();
  vec4 depthpack =texture2D(shadowMap,shadowCoord.xy);
  float depthUnpack =unpack(depthpack);
   // 检查当前片段是否在阴影中
  if(depthUnpack > shadowCoord.z -bias)
      return 1.0;
  return 0.0;
}



float PCF_Internal(sampler2D shadowMap,vec2 shadowUV,float flagDepth,float simpleScale){
  float sum=0.0;
  float  filterSize=  1.0 / 2048.0 ;
  for(int i=0;i<NUM_SAMPLES; i ++){
    vec2 simpleUV =shadowUV + poissonDisk[i] /float(4096) *simpleScale;
    float shadowMapDepth =unpack(vec4(texture2D(uShadowMap,simpleUV).rgb,1.0));
     sum +=(flagDepth >(shadowMapDepth +0.003)?0.0:1.0);
  }

  return sum/float(NUM_SAMPLES);
}

//利用相似三角形计算半影直径并传递给 PCF 函数以调整其滤波核大小
float PCSS(sampler2D shadowMap, vec4 coords){

  // STEP 1: avgblocker depth 平均遮挡深度
   float zBlocker=findBlocker(shadowMap,coords.xy,coords.z);
  if(zBlocker<EPS){//没有被遮挡
    return 1.0;
  }

  if(zBlocker >1.0+EPS){
    return 0.0;
  }

  // STEP 2: penumbra size 确定半影的大小
  float penumbraScale =(coords.z -zBlocker) /zBlocker;


  // STEP 3: filtering  过滤
  return PCF_Internal(shadowMap,coords.xy,coords.z,penumbraScale*10.0);

}



vec3 blinnPhong() {
  vec3 color = texture2D(uSampler, vTextureCoord).rgb;
  color = pow(color, vec3(2.2));

  vec3 ambient = 0.05 * color;

  vec3 lightDir = normalize(uLightPos);
  vec3 normal = normalize(vNormal);
  float diff = max(dot(lightDir, normal), 0.0);
  vec3 light_atten_coff =
      uLightIntensity / pow(length(uLightPos - vFragPos), 2.0);
  vec3 diffuse = diff * light_atten_coff * color;

  vec3 viewDir = normalize(uCameraPos - vFragPos);
  vec3 halfDir = normalize((lightDir + viewDir));
  float spec = pow(max(dot(halfDir, normal), 0.0), 32.0);
  vec3 specular = uKs * light_atten_coff * spec;

  vec3 radiance = (ambient + diffuse + specular);
  vec3 phongColor = pow(radiance, vec3(1.0 / 2.2));
  return phongColor;
}

void main(void) {

  float visibility;
  // perform perspective divide 执行透视划分
  vec3 projCoords = vPositionFromLight.xyz / vPositionFromLight.w;
  // transform to [0,1] range 变换到[0,1]的范围
  vec3 shadowCoord = projCoords * 0.5 + 0.5;
  // visibility = useShadowMap(uShadowMap, vec4(shadowCoord, 1.0));
  // visibility = PCF(uShadowMap, vec4(shadowCoord, 1.0));
  visibility = PCSS(uShadowMap, vec4(shadowCoord, 1.0));

  vec3 phongColor = blinnPhong();

  gl_FragColor = vec4(phongColor * visibility, 1.0);
  //gl_FragColor = vec4(phongColor, 1.0);
}