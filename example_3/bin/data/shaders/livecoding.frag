#version 120

uniform float vol;

void main( void )
{
    float r = vol;
    float g = 0.0;
    float b = 0.0;
    
	gl_FragColor = vec4(r, g, b, 1.0);
}