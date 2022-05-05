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
        float rad;
        int growW;
        int growH;
		
};
