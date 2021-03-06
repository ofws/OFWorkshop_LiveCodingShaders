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

    
    //image
    image.loadImage("images/crab-nebula_wallpapers.jpg");
    grabber.initGrabber(320, 240);
    
    //shader
	autoShader.load("shaders/livecoding");
    autoShader.setMillisBetweenFileCheck(100);
}

//--------------------------------------------------------------
void testApp::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
//    ofFbo fbo;
//    fbo.allocate(1024, 768);
//    
//    
//    fbo.begin();
//    ofClear(0);
//    ofSetColor(255);
//    ofCircle(ofGetWidth()/2 + sin(ofGetElapsedTimef()) * 100, ofGetHeight()/2, 25);
//    fbo.end();
//    fbo.draw(0,0);
    
    
    

    autoShader.begin();
    autoShader.setUniform1f("time", ofGetElapsedTimef());
    autoShader.setUniform2f("windowSize", ofGetWidth(), ofGetHeight());
    autoShader.setUniform2f("mousePos", mouseX, mouseY);
    autoShader.setUniform1f("vol", scaledVol);
//    fbo.draw(0,0);
//    image.draw(0,0);
    grabber.draw(0,0, 1024, 768);
    autoShader.end();
    
    
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
