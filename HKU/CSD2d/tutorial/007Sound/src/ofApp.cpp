#include "ofApp.h"
AudioFile<float> audioFile;

ofApp::ofApp() : numSamples(audioFile.getNumSamplesPerChannel()){
    buffer = new float [numSamples];
}

ofApp::~ofApp(){
    delete buffer;
    buffer = nullptr;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}
