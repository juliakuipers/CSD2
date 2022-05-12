#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

    ofApp();
    ~ofApp();

		void draw();
		int bpmTick(float bpm, float note);
		void rotatingRects();
		void rotatingTriangles();
		void rotatingCircles();
		void drawRotatingShapes();
		void clockLine();
		void growingCircle();

    ofSoundPlayer mySound;
		ofImage myImg;

    private:
        int bandsAmount;
				float cue [2] = {0.0,34.0};
				float time;
				int tick;
				float volume;
				float increment;
				float grow;

};
