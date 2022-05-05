#include "ofApp.h"
AudioFile<float> audioFile;

ofApp::ofApp() : numSamples(audioFile.getNumSamplesPerChannel()), bandsAmount(5){
    buffer = new float [numSamples];
    mySound.load("shanti.mp3");
    mySound.play();
}

ofApp::~ofApp(){
    delete buffer;
    buffer = nullptr;
}

//i deleted ofApp::setup() and ofApp::update()

//--------------------------------------------------------------
void ofApp::draw(){
    float * fft = ofSoundGetSpectrum(bandsAmount);
    
    for(int i = 0; i < bandsAmount; i ++){
        std::cout << "fft[i] = "<< std::fixed << fft[i] << std::endl;
        float haha = fft[i] * 10000;
        ofDrawCircle(500, ofGetHeight()/2,haha);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

void ofApp::fillAudioBuffer(){
//    int channel = 0;
    for (int i = 0; i < numSamples; i++)
      {
       buffer[i] = audioFile.samples[0][i];
      }
}
