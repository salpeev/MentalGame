
varying highp vec2 v_textureCoordinate;

uniform sampler2D sampler;



void main() {
    gl_FragColor = texture2D(sampler, v_textureCoordinate);
}



