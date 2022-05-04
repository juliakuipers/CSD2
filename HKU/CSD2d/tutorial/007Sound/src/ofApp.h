#pragma once

#include "ofMain.h"
#include "AudioFile.h"

class ofApp : public ofBaseApp{

	public:
    
    ofApp();
    ~ofApp();

		void draw();
    
		void keyReleased(int key);
        void fillAudioBuffer();
        ofSoundPlayer   mySound;
    
    private:
        float* buffer = nullptr;
        int numSamples;
    
};
