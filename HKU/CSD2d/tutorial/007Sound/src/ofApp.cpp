#include "ofApp.h"

ofApp::ofApp() : bandsAmount(25), time(0.0){
    mySound.load("timev2.wav");
    mySound.play();
}

ofApp::~ofApp(){
}
//--------------------------------------------------------------
void ofApp::draw(){
    float * fft = ofSoundGetSpectrum(bandsAmount);

    for(int i = 0; i < bandsAmount; i ++){
        float getDing = ofGetWidth() / bandsAmount * (i+1);
        float result = ofLerp(1, ofGetHeight(), fft[i]);
        ofDrawLine(getDing,0,getDing,result*20);
    }
    time  = ofGetElapsedTimef(); //work whit true and false
    if(time > 34){
      std::cout << "cue-point " << std::endl;
    }
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofNoFill();
    ofSetLineWidth(1);
//    ofDrawRectangle(0, 0, 500, 500);
    for(int i = 0; i < bandsAmount; i++){
        ofRotateDeg(mySound.getPositionMS()/1000);
        ofScale(0.9);
        ofDrawRectangle(0, 0, 500, 500);
        ofDrawTriangle(ofGetWidth()*0.2, ofGetHeight()*0.2, ofGetWidth()*0.8, ofGetHeight()*0.2, ofGetWidth()/2, ofGetHeight()*0.8);
    }
}

//bpm 126.5

int ofRunApp::bpmTick(float bpm, int note){
  time = ofGetElapsedTimeMillis();
  float ms = 60,000/bpm;
  //60,000 / 100 bpm = 600ms
}
