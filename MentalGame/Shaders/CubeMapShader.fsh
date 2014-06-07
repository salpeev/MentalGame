
varying lowp vec3 v_reflectionDirection;

uniform samplerCube u_samplerCube;



void main() {
    gl_FragColor = textureCube(u_samplerCube, v_reflectionDirection);
}