#version 120

void main( void )
{
	float width = 1024;
    float height = 768;
    
    
    float red = pow(gl_FragCoord.x / width, sin();
    float green = 0.0;//(sin(gl_FragCoord.y * 0.2)+1) * 0.25 * gl_FragCoord.y / height; //gl_FragCoord.y / height;
    float blue = 0.0; //sin(tan(gl_FragCoord.x * 0.02)+1) * 0.5;
    
    gl_FragColor = vec4(red, green, blue, 1.0);
}