
attribute vec4 a_position;
attribute vec3 a_normal;

uniform mat4 u_projection;
uniform mat4 u_modelview;

varying vec4 v_color;

void main() {
    gl_Position = u_projection * u_modelview * a_position;
    
    v_color = vec4(vec3(0.5) + 0.5 * a_normal, 0.8);
}
