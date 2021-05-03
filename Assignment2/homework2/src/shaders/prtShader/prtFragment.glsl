#ifdef GL_ES
precision mediump float;
#endif

varying highp vec3 vColor;

void  main(void){
 //gl_FragColor = vec4(0.0,.75,1.0, 0.3);
 //gl_FragColor = vec4(1.0,1.0,1.0, 1.0);

 gl_FragColor = vColor;


}