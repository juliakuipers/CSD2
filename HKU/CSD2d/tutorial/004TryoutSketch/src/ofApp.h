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
        float grad;
        float gradColorSpeed;
    //to make things change less fast make a speed variable (gradColorSpeed = 0.5) and add that instead of i
		
};
