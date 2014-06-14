
attribute vec4 a_position;
attribute vec3 a_normal;

uniform mat4 u_projection;
uniform mat4 u_modelview;
uniform mat3 u_normalMatrix;
uniform vec3 u_cameraPosition;

varying vec3 v_reflectionDirection;



void main() {
    vec3 cameraDirection = normalize(a_position.xyz - u_cameraPosition);
    
    // Reflection
//    vec3 reflectionVector = u_normalMatrix * reflect(cameraDirection, a_normal);
//    v_reflectionDirection = -reflectionVector.xyz;
    
    // Refraction
    vec3 refractionVector = u_normalMatrix * refract(cameraDirection, a_normal, 1.3);
    v_reflectionDirection = -refractionVector.xyz;
    
    gl_Position = u_projection * u_modelview * a_position;
}