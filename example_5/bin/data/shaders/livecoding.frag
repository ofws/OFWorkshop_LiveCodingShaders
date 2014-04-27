#version 120

uniform sampler2DRect tex0;
varying vec2 texCoordVarying;

uniform float time;
uniform vec2 windowSize;
uniform vec2 mousePos;
uniform float vol;


void main( void )
{
    float r = texture2DRect( tex0, texCoordVarying ).r;
    float g = texture2DRect( tex0, texCoordVarying ).g;
    float b = texture2DRect( tex0, texCoordVarying ).b;
    
	gl_FragColor = vec4(r, g, b, 1.0);
}