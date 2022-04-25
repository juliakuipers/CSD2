#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
    ofApp();
    ~ofApp();
    
		void setup();
		void update();
		void draw();
        
        void drawVerticalLine();
        void drawDiagonalLine();
        void drawCurve();
    
    private:
    
        float curveFittingFactor;
		
};
