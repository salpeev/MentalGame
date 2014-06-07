
attribute vec4 a_position;
attribute vec3 a_normal;

uniform mat4 u_projection;
uniform mat4 u_modelview;
uniform mat3 u_normalMatrix;
uniform vec3 u_cameraPosition;

varying vec3 v_reflectionDirection;



void main() {
    vec3 cameraDirection = normalize(a_position.xyz - u_cameraPosition);
    
    vec3 reflectionVector = u_normalMatrix * reflect(cameraDirection, a_normal);
    v_reflectionDirection = vec3(reflectionVector.x, -reflectionVector.y, reflectionVector.z);
    
    gl_Position = u_projection * u_modelview * a_position;
}