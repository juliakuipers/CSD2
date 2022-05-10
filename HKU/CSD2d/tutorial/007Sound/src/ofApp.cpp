#include "ofApp.h"

ofApp::ofApp() : bandsAmount(25), time(0.0), tick(0){
    mySound.load("timev2.wav");
    mySound.play();
    ofBackground(255,182,193);
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
        volume = mySound.getVolume();
        // std::cout << "volume = " << volume << std::endl;
    }
    time  = ofGetElapsedTimef(); //work with true and false
    if(time > 34){
      // continue;
    }
    drawRotatingShapes();
    ofRotateDeg(ofGetElapsedTimef());
    ofDrawLine(0,0,300,200);
}



//bpm 126.5

int ofApp::bpmTick(float bpm, float note){
  time = ofGetElapsedTimeMillis();
  float ms = (60000/bpm) * note; //if note is 1 it results in a quarter note
  if(time >= ms){
    ofResetElapsedTimeCounter();
    return 1;
  }else {
    return 0;
  }
}

void ofApp::drawRotatingShapes(){
  bool clockrotate = true;
  while(clockrotate){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofNoFill();
    ofSetLineWidth(1);
    for(int i = 0; i < bandsAmount; i++){
        ofRotateDeg(tick+=bpmTick(126.5,1));
        ofScale(0.9);
        ofDrawRectangle(0, 0, 500, 500);
        ofDrawTriangle(ofGetWidth()*0.2, ofGetHeight()*0.2, ofGetWidth()*0.8, ofGetHeight()*0.2, ofGetWidth()/2, ofGetHeight()*0.8);
      }
    }
    clockrotate = false;
}
