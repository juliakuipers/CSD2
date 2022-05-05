#pragma once

#include "ofMain.h"
#include "AudioFile.h"

class ofApp : public ofBaseApp{

	public:
    
    ofApp();
    ~ofApp();

		void draw();
    
        ofSoundPlayer mySound;
    
    private:
        float* buffer = nullptr;
        int numSamples;
        int bandsAmount; 
    
};
