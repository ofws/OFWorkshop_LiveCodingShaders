#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofEnableAlphaBlending();
    
    
    //audio
    int bufferSize = 256;
	
	left.assign(bufferSize, 0.0);
	right.assign(bufferSize, 0.0);
    
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
    
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

    
    //texture
    image.loadImage("images/crab-nebula_wallpapers.jpg");
    
    //3d
    cam.setDistance(500);
    plane.set(200, 300, 50, 75);
//    plane.mapTexCoords(0, 0, 320, 240);
    plane.mapTexCoordsFromTexture(image.getTextureReference());
    sphere.set(150, 20);
    sphere.mapTexCoordsFromTexture(image.getTextureReference());
    cylinder.set(100, 300, 20, 40);
    cylinder.mapTexCoordsFromTexture(image.getTextureReference());
    cone.set(100, 300);
    cone.mapTexCoordsFromTexture(image.getTextureReference());
//    icosphere.set(10, 10);
    
    currentPrimitive = 0;
    drawWireframe = false;
    
    //shader
	autoShader.load("shaders/livecoding");
    autoShader.setMillisBetweenFileCheck(100);
}

//--------------------------------------------------------------
void testApp::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableDepthTest();
    cam.begin();
    autoShader.begin();
    autoShader.setUniformTexture("tex0", image.getTextureReference(), 0);
    autoShader.setUniform1f("time", ofGetElapsedTimef());
    autoShader.setUniform2f("windowSize", ofGetWidth(), ofGetHeight());
    autoShader.setUniform2f("mousePos", mouseX, mouseY);
    autoShader.setUniform1f("vol", scaledVol);
    
    
    switch (currentPrimitive) {
        case 0:
            drawWireframe ? plane.drawWireframe() : plane.draw();
            break;
            
        case 1:
            drawWireframe ? sphere.drawWireframe() :  sphere.draw();
            break;
            
        case 2:
            drawWireframe ? cylinder.drawWireframe() : cylinder.draw();
            break;
            
        case 3:
            drawWireframe ? cone.drawWireframe() : cone.draw();
            break;
    }
    
    
    autoShader.end();
    cam.end();
    ofDisableDepthTest();
    
    ofSetWindowTitle("FPS: " + ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
	
	float curVol = 0.0;
	
	// samples are "interleaved"
	int numCounted = 0;
    
	//lets go through each sample and calculate the root mean square which is a rough way to calculate volume
	for (int i = 0; i < bufferSize; i++){
		left[i]		= input[i*2]*0.5;
		right[i]	= input[i*2+1]*0.5;
        
		curVol += left[i] * left[i];
		curVol += right[i] * right[i];
		numCounted+=2;
	}
	
	//this is how we get the mean of rms :)
	curVol /= (float)numCounted;
	
	// this is how we get the root of rms :)
	curVol = sqrt( curVol );
	
	smoothedVol *= 0.93;
	smoothedVol += 0.07 * curVol;
	
}



//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == 'p') {
        currentPrimitive++;
        currentPrimitive%=4;
    }
    
    if (key == 'w') {
        drawWireframe ^= true;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
