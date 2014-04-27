#version 120

uniform float time;
uniform vec2 windowSize;
uniform vec2 mousePos;

void main( void )
{
    
    
    vec2 flippedMousePos = mousePos;
    flippedMousePos.y = windowSize.y - mousePos.y;
    
    float r = 0.0;
    float g = 0.0;
    float b = 0.0;
    
    float dist = distance(flippedMousePos / windowSize, gl_FragCoord.xy / windowSize);
    
    if ( dist < 0.1) {
        r = 1.0;
    }
    else {
        r = 0.0;
    }
    
    b = (pow(dist, tan(((sin(dist*10.0 - time * 5.0) + 1) * 0.5) * 10.0)) + 1) * 0.5;
    
    g = 1.0 - pow(dist, (sin(time) + 1) *0.5);
    
    
	gl_FragColor = vec4(r, g, b, 1.0);
}