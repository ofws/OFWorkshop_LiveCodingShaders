#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofEnableAlphaBlending();
    
	autoShader.load("shaders/livecoding");
    autoShader.setMillisBetweenFileCheck(100);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    autoShader.begin();
    autoShader.setUniform1f("time", ofGetElapsedTimef());
    autoShader.setUniform2f("windowSize", ofGetWidth(), ofGetHeight());
    autoShader.setUniform2f("mousePos", mouseX, mouseY);
    ofRect(0,0, ofGetWidth(), ofGetHeight() );
    autoShader.end();
    
    
    ofSetWindowTitle("FPS: " + ofToString(ofGetFrameRate()));
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
