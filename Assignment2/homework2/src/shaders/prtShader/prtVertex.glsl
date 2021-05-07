attribute vec3 aVertexPosition;
attribute vec3 aNormalPosition;
attribute vec2 aTextureCoord;
attribute mat3 aPrecomputeLT;

uniform mat4 uModelMatrix;
uniform mat4 uViewMatrix;
uniform mat4 uProjectionMatrix;

varying highp vec2 vTextureCoord;
varying highp vec3 vFragPos;
varying highp vec3 vNormal;
varying highp mat3 vPrecomputeLT;

void main(void) {

  vFragPos = (uModelMatrix * vec4(aVertexPosition, 1.0)).xyz;
  vNormal = (uModelMatrix * vec4(aNormalPosition, 0.0)).xyz;

  gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix *
                vec4(aVertexPosition, 1.0);

  vTextureCoord = aTextureCoord;
  vPrecomputeLT = aPrecomputeLT;
}




// attribute vec3 aVertexPosition;
// attribute mat3 aPrecomputeLT;

// uniform mat4 uModelMatrix;
// uniform mat4 uViewMatrix;
// uniform mat4 uProjectionMatrix;

// uniform mat3 precomputeLR;
// uniform mat3 precomputeLG;
// uniform mat3 precomputeLB;

// varying highp vec3 vColor;

// void main() {
//     gl_Position = uProjectionMatrix * uViewMatrix * uModelMatrix *
//         vec4(aVertexPosition, 1.0);


//     vColor =vec4(
//     dot(precomputeLR[0],aPrecomputeLT[0])+ dot(precomputeLR[1],aPrecomputeLT[1]) +dot(precomputeLR[2],aPrecomputeLT[2]),
//     dot(precomputeLG[0],aPrecomputeLT[0])+ dot(precomputeLG[1],aPrecomputeLT[1]) +dot(precomputeLG[2],aPrecomputeLT[2]),
//     dot(precomputeLB[0],aPrecomputeLT[0])+ dot(precomputeLB[1],aPrecomputeLT[1]) +dot(precomputeLB[2],aPrecomputeLT[2]),
//     1.0
//     );

// }