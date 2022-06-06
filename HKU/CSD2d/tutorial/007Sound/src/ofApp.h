#pragma once
#include "AudioFile.h"
#include "fractals.h"
#include "MIR.h"

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:

    ofApp();
    ~ofApp();

		void draw();
		void update();

		void fillFftArray();

		void drawRotatingShapes();
		void clockLine();
		void growingCircle();
		void reactivePolyLine();
		void polyCircle();

		Fractals fractal;
		MIR mir;

    private:
				float height;
				float width;
				float cue [2] = {0.0,34.0};
				int tick;
				float volume;
				float grow;
				int bands;
				float radiusIncrement;
				int low;
				int mid;
				int high;

};
