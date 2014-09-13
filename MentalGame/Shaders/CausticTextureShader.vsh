
attribute vec2 a_position;

uniform mat4 u_modelviewProjection;
uniform mat4 u_inverseModelviewProjection;
uniform vec3 u_cameraPosition;
uniform sampler2D u_refractiveNormals;
uniform sampler2D u_refractiveDepth;
uniform sampler2D u_receiverDepth;
uniform sampler2D u_refractiveBackfaceNormals;
uniform sampler2D u_refractiveBackfaceDepth;

varying vec4 v_color;


vec3 reproject(vec3 position, mat4 projection, mat4 inverseProjection, sampler2D depthmap);
vec3 estimateIntersection(vec3 startPoint, vec3 ray, mat4 projection, mat4 inverseProjection, sampler2D depthmap);
vec3 sampleRefractivePosition(vec2 texCoords, sampler2D depthmap);


void main() {
    v_color = vec4(1.0);
    
    if (texture2D(u_refractiveDepth, a_position).x == 1.0) {
        gl_Position = vec4(2.0 * a_position - vec2(1.0), 0.0, 1.0);
        return;
    }
    
    vec4 vSampledNormal = texture2D(u_refractiveNormals, a_position);
    if (vSampledNormal.a == 1.0) {
        gl_Position = vec4(2.0 * a_position - vec2(1.0), 0.0, 1.0);
        return;
    }
    
    vec3 vRefractivePosition = sampleRefractivePosition(a_position, u_refractiveDepth);
    vec3 vNormal = 2.0 * vSampledNormal.xyz - vec3(1.0);
    vec3 vLightVector = normalize(vRefractivePosition - u_cameraPosition);
    vLightVector = refract(vLightVector, vNormal, vSampledNormal.a);
    
    vec3 vFirstIntersectedVertex = estimateIntersection(vRefractivePosition, vLightVector, u_modelviewProjection, u_inverseModelviewProjection, u_refractiveBackfaceDepth);
    vec4 vProjectedIntersection = u_modelviewProjection * vec4(vFirstIntersectedVertex, 1.0);
    vec2 vProjectedIntersectionTC = vec2(0.5) + 0.5 * vProjectedIntersection.xy / vProjectedIntersection.w;
    vec3 vBackfaceSampledNormal = vec3(1.0) - 2.0 * texture2D(u_refractiveBackfaceNormals, vProjectedIntersectionTC).xyz;
    
    vLightVector = refract(vLightVector, vBackfaceSampledNormal, 1.0 / vSampledNormal.a);
    if (dot(vLightVector, vLightVector) < 1.0e-5) {
        v_color = vec4(0.0);
        gl_Position = vec4(a_position, 0.0, 1.0);
        return;
    }
    
    vRefractivePosition = sampleRefractivePosition(vProjectedIntersectionTC, u_refractiveBackfaceDepth);
    vec3 vIntersectedVertex = estimateIntersection(vRefractivePosition, vLightVector, u_modelviewProjection, u_inverseModelviewProjection, u_receiverDepth);
    gl_Position = u_modelviewProjection * vec4(vIntersectedVertex, 1.0);
}


vec3 reproject(vec3 position, mat4 projection, mat4 inverseProjection, sampler2D depthmap) {
    vec4 vProjected = projection * vec4(position, 1.0);
    vec2 texCoord = vProjected.xy / vProjected.w;
    
    float fSampledDepth = 2.0 * texture2D(depthmap, vec2(0.5) + 0.5 * texCoord).x - 1.0;
    vec4 vWorldSpaceVertex = inverseProjection * vec4(texCoord, fSampledDepth, 1.0);
    return vWorldSpaceVertex.xyz / vWorldSpaceVertex.w;
}

vec3 estimateIntersection(vec3 startPoint, vec3 ray, mat4 projection, mat4 inverseProjection, sampler2D depthmap) {
    vec3 p = reproject(startPoint + ray, projection, inverseProjection, depthmap);
    for (int i = 0; i < 5; i++) {
        p = reproject(startPoint + ray * distance(startPoint, p), projection, inverseProjection, depthmap);
    }
    return p;
}

vec3 sampleRefractivePosition(vec2 texCoord, sampler2D depthmap) {
    float fSampledDepth = 2.0 * texture2D(depthmap, texCoord).x - 1.0;
    vec4 vWorldSpaceVertex = u_inverseModelviewProjection * vec4(2.0 * texCoord - vec2(1.0), fSampledDepth, 1.0);
    return vWorldSpaceVertex.xyz / vWorldSpaceVertex.w;
}