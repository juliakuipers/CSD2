#include "ofApp.h"
AudioFile<float> audioFile;

ofApp::ofApp() : numSamples(audioFile.getNumSamplesPerChannel()){
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
