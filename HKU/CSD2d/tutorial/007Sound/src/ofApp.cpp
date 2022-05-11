#include "ofApp.h"

ofApp::ofApp() : bandsAmount(35), time(0.0), tick(0), increment(0){
    mySound.load("timev2.wav");
    mySound.play();
    ofColor colorOne(255,182,193);
    ofColor colorTwo(0, 0, 0);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
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
    clockLine();
}



//bpm 126.5

int ofApp::bpmTick(float bpm, float note){
  time = ofGetElapsedTimeMillis();
  float ms = (60000/bpm) * note; //if note is 1 it results in a quarter note
  if(time >= increment){
    increment += ms;
    return 1;
  }else {
    return 0;
  }
}

void ofApp::drawRotatingShapes(){
  ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofNoFill();
  ofSetLineWidth(1);
  for(int i = 0; i < bandsAmount; i++){
      ofRotateDeg((tick+=bpmTick(126.5,1))*-1);
      ofScale(0.85);
      ofDrawRectangle(0, 0, 500, 500);
      ofDrawTriangle(ofGetWidth()*0.2, ofGetHeight()*0.2, ofGetWidth()*0.8, ofGetHeight()*0.2, ofGetWidth()/2, ofGetHeight()*0.8);
  }
  ofPopMatrix();
}

void ofApp::clockLine(){
  ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  ofSetLineWidth(5);
  ofRotateDeg(ofGetElapsedTimeMillis()/8);
  ofDrawLine(0,0,ofGetWidth()/4,ofGetHeight()/4);
  ofRotateDeg(ofGetElapsedTimeMillis()/4);
  ofDrawLine(0,0,ofGetWidth()/6,ofGetHeight()/6);
  ofPopMatrix();
}
