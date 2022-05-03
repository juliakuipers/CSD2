#pragma once

#include "ofMain.h"
#include "AudioFile.h"

class ofApp : public ofBaseApp{

	public:
    
    ofApp();
    ~ofApp();
    
		void update();
		void draw();
    
		void keyReleased(int key);
        void fillAudioBuffer();
    
    private:
        float* buffer = nullptr;
        int numSamples;
    
};
