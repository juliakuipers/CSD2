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

		void drawRotatingShapes();
		void clockLine();
		void growingCircle();
		void reactivePolyLine();
		void polyCircle();
		void generativeLines();
		void reactiveCircleFractal();

		Fractals fractal;
		MIR mir;
		ofPolyline lijntje;

    private:

				float height;
				float width;
				float grow;
				float radiusIncrement;

				int bands;
				int tick;

				bool peaked;

				float *fft;

};
