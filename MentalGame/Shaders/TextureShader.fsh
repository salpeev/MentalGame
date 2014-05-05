
varying highp vec2 v_textureCoordinate;

uniform sampler2D u_sampler;



void main() {
    gl_FragColor = texture2D(u_sampler, v_textureCoordinate);
}



