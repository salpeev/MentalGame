
varying lowp vec3 v_reflectionDirection;
varying lowp vec3 v_refractionDirection;
varying lowp float v_fresnel;

uniform samplerCube u_samplerCube;



void main() {
    lowp vec4 refractionColor = textureCube(u_samplerCube, v_refractionDirection);
    lowp vec4 reflectionColor = textureCube(u_samplerCube, v_reflectionDirection);
    
    gl_FragColor = mix(refractionColor, reflectionColor, v_fresnel);
    
//    gl_FragColor = textureCube(u_samplerCube, v_reflectionDirection);
}