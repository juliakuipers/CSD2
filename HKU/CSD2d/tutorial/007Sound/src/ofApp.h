#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

    ofApp();
    ~ofApp();

		void draw();
		int bpmTick(float bpm, float note);

        ofSoundPlayer mySound;

    private:
        int bandsAmount;
				float cue [2] = {0.0,34.0};
				float time;
				int tick;

};


//    ofDrawCurve(200, 200, 0,ofGetHeight()/2, ofGetWidth() , ofGetHeight()/2, 200, 20);
//
//      int spacing = 50;
//      ofBeginShape();
//      for(int x=0; x<ofGetWidth(); x+= spacing) {
//          ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 0.02f));
//      }
//      ofEndShape(false);
//    //https://forum.openframeworks.cc/t/drawing-a-curved-line/1141/3

//    ofBeginShape();
//        ofVertex(0,ofGetHeight()/2);
//        ofVertex(ofGetWidth()/2, ofGetHeight());
//        ofVertex(ofGetWidth(), ofGetHeight()/2);
//        ofVertex(ofGetWidth()/2,0);
//    ofEndShape();
