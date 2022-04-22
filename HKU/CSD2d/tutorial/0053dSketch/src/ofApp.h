#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
        ofApp();
        ~ofApp();
		void setup();
		void update();
		void draw();
    
    private:
        float xPlane;
        float xPlaneSpeed;
        float yPlane;
        float yPlaneSpeed;
        float planeWidth = ofGetWidth();
        float planeWidthSpeed = 2.5;
        float planeHeight = ofGetHeight();
        float planeHeightSpeed = 5.5;
        
		
};
