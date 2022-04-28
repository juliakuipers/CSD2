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
        void randomStrands();
        void drawCircleLine();
    
    private:
    
        float curveFittingFactor;
        float margin;
        float accel;
        int steps;
        float* x = nullptr;
        float* y = nullptr;
        float* xSpeed = nullptr;
        float* ySpeed = nullptr;
		
};
