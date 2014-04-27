#pragma once

#include "ofMain.h"
#include "ofxAutoReloadedShader.h"

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //audio
    void audioIn(float * input, int bufferSize, int nChannels);
	
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    //image
    ofImage image;
    ofVideoGrabber grabber;
		
    //shader
    ofxAutoReloadedShader autoShader;
};
