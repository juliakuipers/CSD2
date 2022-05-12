#include "ofApp.h"

ofApp::ofApp() : bandsAmount(35), time(0.0), tick(0), increment(0), grow(0){
    mySound.load("timev2.wav");
    mySound.play();
    myImg.load("clock2.png");
    // myImg.draw(ofGetWidth()/2, ofGetHeight()/2);
    // ofEnableBlendMode(OF_BLENDMODE_ALPHA);
}

ofApp::~ofApp(){
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofColor colorTwo(255,182,193);
    ofColor colorOne(137, 207, 240);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
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
    growingCircle();
    drawRotatingShapes();
    ofSetColor(255);
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
  ofSetLineWidth(2);
  for(int i = 0; i < bandsAmount; i++){
      ofSetColor(0);
      ofRotateDeg((tick+=bpmTick(126.5,1))*-1);
      ofScale(0.85);
      ofDrawRectangle(0, 0, ofGetHeight(),ofGetHeight());
      // ofDrawTriangle(ofGetWidth()*0.2, ofGetHeight()*0.2, ofGetWidth()*0.8, ofGetHeight()*0.2, ofGetWidth()/2, ofGetHeight()*0.8);
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
  ofFill();
  ofDrawCircle(0,0,3,3);
  ofNoFill();
  ofPopMatrix();
}

void ofApp::growingCircle(){
  ofPushMatrix();
  ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
  for(int i = 0; i < bandsAmount; i++){
      ofScale(0.85);
      for(int x = 0; x < ofGetWidth(); x+=100){
        ofSetColor(64,224,208);
        ofSetLineWidth(1);
        // ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,x+grow*-1);
        ofDrawCircle(0,0,x+grow*-1);
      }
      grow+=0.01;
      if(grow>ofGetWidth()){grow=ofGetWidth()/2;}
    }
    ofPopMatrix();
}
