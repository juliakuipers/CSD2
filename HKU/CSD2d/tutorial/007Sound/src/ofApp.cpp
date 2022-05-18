#include "ofApp.h"

ofApp::ofApp() : height(ofGetHeight()), width(ofGetWidth()), bandsAmount(35), time(0.0), tick(0), increment(0), grow(0){
    mySound.load("timev2.wav");
    mySound.play();
    ofBackground(0);
}

ofApp::~ofApp(){
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(width/2, height/2);
    sexyCircle(0,0,400);
    ofPopMatrix();
    ofSetLineWidth(1);
    // cantor(20,10,width-20);
    // growingCircle();
    // drawRotatingShapes();
    // ofSetColor(255);
    // clockLine();
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
  ofTranslate(width/2, height/2);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofNoFill();
  ofSetLineWidth(2);
  for(int i = 0; i < bandsAmount; i++){
      ofSetColor(0);
      ofRotateDeg((tick+=bpmTick(126.5,1))*-1);
      ofScale(0.85);
      ofDrawRectangle(0, 0, height,height);
      // ofDrawTriangle(width*0.2, height*0.2, width*0.8, height*0.2, width/2, height*0.8);
  }
  ofPopMatrix();
}

void ofApp::clockLine(){
  ofPushMatrix();
  ofTranslate(width/2, height/2);
  ofSetLineWidth(5);
  ofRotateDeg(ofGetElapsedTimeMillis()/8);
  ofDrawLine(0,0,width/4,height/4);
  ofRotateDeg(ofGetElapsedTimeMillis()/4);
  ofDrawLine(0,0,width/6,height/6);
  // ofFill();
  ofDrawCircle(0,0,3,3);
  // ofNoFill();
  ofPopMatrix();
}

void ofApp::growingCircle(){
  ofPushMatrix();
  ofTranslate(width/2, height/2);
  ofNoFill();
  for(int i = 0; i < bandsAmount; i++){
      ofScale(0.85);
      for(int x = 0; x < width; x+=100){
        ofSetColor(255);
        ofSetLineWidth(1);
        ofRotateDeg(ofGetElapsedTimef()/4);
        // ofDrawCircle(width/2,height/2,x);
        ofDrawCircle(0,0,x+grow*-1);
      }
      grow+=0.01;
      if(grow>width){grow*=-1;}
    }
    ofPopMatrix();
}

void ofApp::peakDetection(){

}

void ofApp::sexyCircle(float x, float y, float rad){
  ofNoFill();
  ofSetLineWidth(1);
  ofDrawRectangle(x,y,rad,rad);
  if(rad > 4){
    rad *= 0.75f;
    sexyCircle(x + rad/2,y,rad/2);
    sexyCircle(x - rad/2,y,rad/2);
    sexyCircle(x,y + rad/2,rad/2);
    sexyCircle(x,y - rad/2,rad/2);
  }
}

void ofApp::fft(){
  float * fft = ofSoundGetSpectrum(bandsAmount);
  for(int i = 0; i < bandsAmount; i ++){
      float getDing = width / bandsAmount * (i+1);
      float result = ofLerp(1, height, fft[i]);
      ofDrawLine(getDing,0,getDing,result*20);

  }
}

void ofApp::cantor(float x, float y, float length){
  if(length > 2){
    y+=20;
    ofDrawLine(x,y,x+length,y);
    cantor(x,y,length/3);
    cantor(x+length*2/3,y,length/3);
  }
}

//rms ms
