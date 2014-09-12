
attribute vec4 a_position;

uniform mat4 u_projection;
uniform mat4 u_inverseProjection;
uniform sampler2D u_refractiveNormals;
uniform sampler2D u_refractiveDepth;
uniform sampler2D u_receiverDepth;
uniform sampler2D u_refractiveBackfaceNormals;
uniform sampler2D u_refractiveBackfaceDepth;



vec3 reproject(vec3 position, mat4 projection, mat4 inverseProjection, sampler2D depthmap);
vec3 estimateIntersection(vec3 startPoint, vec3 ray, mat4 projection, mat4 inverseProjection, sampler2D depthmap);


void main() {
    
}


vec3 reproject(vec3 position, mat4 projection, mat4 inverseProjection, sampler2D depthmap) {
    vec4 vProjected = projection * vec4(position, 1.0);
    vec2 texCoord = vProjected.xy / vProjected.w;
    
    // TODO: Why 2.0 * ...?
    float fSampledDepth = 2.0 * texture(depthmap, vec2(0.5) + 0.5 * texCoord).x - 1.0;
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