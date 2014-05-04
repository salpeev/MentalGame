
attribute vec4 a_position;
attribute vec2 a_textureCoordinate;

varying vec2 v_textureCoordinate;



void main() {
    v_textureCoordinate = a_textureCoordinate;
    gl_Position = a_position;
}