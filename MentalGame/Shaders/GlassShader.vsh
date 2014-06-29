
attribute vec4 a_position;
attribute vec3 a_normal;

uniform mat4 u_projection;
uniform mat4 u_modelview;
uniform mat3 u_normalMatrix;
uniform vec3 u_cameraPosition;

varying vec3 v_reflectionDirection;
varying vec3 v_refractionDirection;
varying float v_fresnel;



float fresnel(vec3 cameraDirection, vec3 normal, float eta);




void main() {
    // Camera direction
    vec3 cameraDirection = normalize(a_position.xyz - u_cameraPosition);
    vec3 mirroredCameraDirection = -cameraDirection;    // Because we have mirrored cube map
    
    // Vertex direction
    vec4 translatedPosition = u_modelview * a_position;
    vec3 vertexCameraDirection = normalize(translatedPosition.xyz - u_cameraPosition);
    vec3 mirroredVertexCameraDirection = -vertexCameraDirection;
    
    // Reflection
    vec3 reflectionVector = u_normalMatrix * reflect(mirroredCameraDirection, a_normal);
    v_reflectionDirection = reflectionVector.xyz;
    
    // Refraction
    vec3 refractionVector = u_normalMatrix * refract(mirroredCameraDirection, a_normal, 0.7);
    v_refractionDirection = refractionVector.xyz;
    
    // Fresnel
    v_fresnel = fresnel(mirroredVertexCameraDirection, a_normal, 0.7);
    
    gl_Position = u_projection * u_modelview * a_position;
}



float fresnel(vec3 cameraDirection, vec3 normal, float eta) {
    // http://www.uraldev.ru/articles/39/page/1
    float cDotN = dot(cameraDirection, normal);
    float sqrEta = eta * eta;
    float etaCos = eta * cDotN;
    float sqrEtaCos = etaCos * etaCos;
    float oneMinSqrEta = 1.0 - sqrEta;
    float value = etaCos - sqrt(oneMinSqrEta + sqrEtaCos);
    value *= value / oneMinSqrEta;
    return min(1.0, value * value);
}