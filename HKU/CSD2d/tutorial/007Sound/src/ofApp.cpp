#include "ofApp.h"
#include <cmath>


ofApp::ofApp() : height(ofGetHeight()), width(ofGetWidth()), tick(0), grow(0),bands(1),radiusIncrement(400){
    ofBackground(0);
    fft = new float[512];
    for (int i = 0; i < 512; i++) {
      fft[i] = 0;
    }
}

ofApp::~ofApp(){}

void ofApp::update(){
  mir.updateMIR();
  for(int i = 0; i < bands; i ++){
    fft[i] = mir.fillFftArray(bands,i);
  }
  std::cout << "ofApp::update() : mir.onsetDetection() = " << mir.onsetDetection() << std::endl;
}

//dust generator

void ofApp::draw(){
    // reactivePolyLine();
    // fractal.circles(0,0,width/2);
    // polyCircle();
    // growingCircle();
    // drawRotatingShapes();
    // ofSetColor(255);
    // clockLine();

    ofDrawCircle(width/2,height/2,(mir.getCurrentSample()+2)*100);
}



//bpm 126.5

void ofApp::drawRotatingShapes(){
  ofPushMatrix();
  ofTranslate(width/2, height/2);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofNoFill();
  ofSetLineWidth(1);
  for(int i = 0; i < 35; i++){
      ofSetColor(255);
      ofRotateDeg((tick+=mir.bpmTick(126.5,1))*-1);
      // ofRotateDeg(ofGetElapsedTimef());
      ofScale(0.85);
      ofDrawRectangle(0, 0, height,height);
      // ofDrawCircle(width*0.2, height*0.2,width*0.2);
      ofDrawTriangle(width*0.2, height*0.2, width*0.8, height*0.2, width/2, height*0.8);
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
  for(int i = 0; i < 35; i++){
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

void ofApp::reactivePolyLine(){
  bands = 512;
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
  bands = 6;
  ofPolyline polyline1;
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


//rms ms
