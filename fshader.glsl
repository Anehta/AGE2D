#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform sampler2D source;
uniform lowp float qt_Opacity;
varying vec2 v_texCoord;

void main()
{
    gl_FragColor = texture2D(source, v_texCoord);
}
