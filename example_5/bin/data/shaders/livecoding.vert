#version 120

uniform sampler2DRect tex0;
varying vec2 texCoordVarying;

uniform float time;
uniform vec2 windowSize;
uniform vec2 mousePos;
uniform float vol;


void main(void)
{
    // get the texture coordinates
    texCoordVarying = gl_MultiTexCoord0.xy;
    
    
    // get the position of the vertex relative to the modelViewProjectionMatrix
    vec4 position = gl_Vertex;//ftransform();
    vec4 modifiedPosition = position;

    
    // we need to scale up the values we get from the texture
    float scale = 0.1;
    
    // here we get the red channel value from the texture
    // to use it as vertical displacement
//    float displacementY = texture2DRect(tex0, texCoordVarying).x;
    
    float sineWave = (sin(time + position.x) + 1.0) * 0.5;
    float displacementY = sineWave * position.x;
    
    // use the displacement we created from the texture data
    // to modify the vertex position
    modifiedPosition.x += displacementY * scale;
    
    // this is the resulting vertex position
	gl_Position = modifiedPosition * gl_ModelViewProjectionMatrix;
//    gl_Position = gl_Vertex * gl_ModelViewProjectionMatrix;
//    gl_Position = ftransform();

}
