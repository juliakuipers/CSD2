#include "ofApp.h"

ofApp::ofApp() : height(ofGetHeight()), width(ofGetWidth()), bandsAmount(35), time(0.0), tick(0), increment(0), grow(0),bands(512),radiusIncrement(400){
    mySound.load("timev2.wav");
    mySound.play();
    ofBackground(0);

    fft = new float[bands];
    for (int i = 0; i < bands; i++) {
      fft[i] = 0;
    }
}

ofApp::~ofApp(){
}

void ofApp::update(){
  ofSoundUpdate();
  soundSpectrum = ofSoundGetSpectrum(bands);
  for (int i = 0; i < bands; i++) {
    fft[i] *= 0.9; //decay
    if (fft[i] < soundSpectrum[i]) {
      fft[i] = soundSpectrum[i];
    }
  }
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(width/2, height/2);
    ofSetRectMode(OF_RECTMODE_CENTER);
    // sexyCircle(0,0,400);
    //array width/2, result/2, result/2 ect
    ofPopMatrix();
    ofSetLineWidth(1);
    formFract();
    // reactivePolyLine();
    // polyCircle();
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
  ofDrawCircle(x,y,rad,rad);
  std::cout << "rad = " << rad << std::endl;
  std::cout << "radiusIncrement = " << radiusIncrement << std::endl;
  if(rad > radiusIncrement && rad > 2){
    // rad *= 0.75f;
    sexyCircle(x + rad/2,y,rad/2);
    sexyCircle(x - rad/2,y,rad/2);
    sexyCircle(x,y + rad/2,rad/2);
    sexyCircle(x,y - rad/2,rad/2);
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

void ofApp::reactivePolyLine(){
    ofTranslate(256, 192);
    for (int i = 0; i < 1; i+=width/2) {
      ofPolyline polyline;
      for (int j = 0; j < bands; j++) {
        polyline.addVertex(j, i - fft[j] * 400.0);
      }
      polyline.draw();
    }
}

void ofApp::polyCircle(){
  ofPolyline polyline1, polyline2, polyline3, polyline4;
  ofPoint point1(width/2,height/2);
  float step = 360/bands;
  ofSetColor(0,0,255);
  ofFill();
  // draw an circle with a diameter of 100 in blue
  for(int i = 0; i < bands; i++){
    polyline1.arc(point1,fft[i]*10000,fft[i]*10000,step*i,step*(i+1));
  }
  polyline1.draw();
}

void ofApp::formFract(){
  //7*0.75 = 1.11.... 7 is dus de max aan increment voor fractals.
  for (int j = 0; j < bands; j++) {
    radiusIncrement = ofLerp(1,7,fft[j]);
    std::cout << radiusIncrement << std::endl;
  }
} //0 tot 0.5 naar 1 tot 7

//rms ms
