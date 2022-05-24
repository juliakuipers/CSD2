#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

    ofApp();
    ~ofApp();

		void draw();
		void update();

		int bpmTick(float bpm, float note);
		void rotatingRects();
		void rotatingTriangles();
		void rotatingCircles();
		void drawRotatingShapes();
		void clockLine();
		void growingCircle();
		void peakDetection();
		void sexyCircle(float x, float y, float rad);
		void cantor(float x, float y, float length);
		void reactivePolyLine();
		void polyCircle();

    ofSoundPlayer mySound;

    private:
				float height;
				float width;
        int bandsAmount;
				float cue [2] = {0.0,34.0};
				float time;
				int tick;
				float volume;
				float increment;
				float grow;
				float *fft;
				float *soundSpectrum;
				int bands;

};
