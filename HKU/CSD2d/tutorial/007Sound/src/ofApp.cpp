#include "ofApp.h"
#include <cmath>


ofApp::ofApp() :
height(ofGetHeight()), width(ofGetWidth()), grow(0),radiusIncrement(400), bands(1), tick(0), peaked(false){
    ofBackground(0);
    fft = new float[512];
    for (int i = 0; i < 512; i++) {
      fft[i] = 0;
    } //make an empty buffer
}

ofApp::~ofApp(){}

void ofApp::update(){
  mir.updateMIR();
  for(int i = 0; i < bands; i ++){
    fft[i] = mir.fillFftArray(bands,i);
    //fill a buffer with fft information
  }
  (mir.onsetDetection() == 1) ? peaked = true : peaked = false;
  //code van justin
}

//dust generator

void ofApp::draw(){
    // reactivePolyLine();
    fractal.circles(width/2,height/2,width/2,0);
    // polyCircle();
    // growingCircle();
    // drawRotatingShapes();
    // ofSetColor(255);
    // clockLine();

    // generativeLines();
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
      // ofRotateDeg((tick+=mir.bpmTick(126.5,1))*-1);
      ofRotateDeg(ofGetElapsedTimef());
      ofScale(0.95);
      // ofDrawRectangle(0, 0, height,height);
      // ofDrawCircle(width*0.3, height*0.3,width*0.3);
      ofDrawTriangle(width*0.2, height*0.2, width*0.8, height*0.2, width/2, height*0.8);
  }
  ofPopMatrix();
  //src https://github.com/lewislepton/openFrameworksTutorialSeries/blob/master/072_rectangleLoop/src/ofApp.cpp
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
  // ofDrawCircle(0,0,3,3);
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
  //select the amount of bands wanted for fft
    ofTranslate(256, 192);
    for (int i = 0; i < bands; i+=16) {
      ofPolyline polyline;
      for (int j = 0; j < bands; j++) {
        polyline.addVertex(j, i - fft[j] * 400.0);
      }
      polyline.draw();
    } //src https://github.com/lewislepton/openFrameworksTutorialSeries/blob/master/048_audioReactivePolyline/src/ofApp.cpp
    //draw a sound spectrum with a poly line (a line to which vertexis can be added) andd fft
}

void ofApp::polyCircle(){
  bands = 6;
  ofPolyline polyline1;
  ofPoint point1(width/2,height/2);
  float step = 360/bands;
  ofFill();
  for(int i = 0; i < bands; i++){
    polyline1.arc(point1,fft[i]*10000,fft[i]*10000,step*i,step*(i+1));
  }
  polyline1.draw();
  //audioreactive circle divided in 6 equal parts (circular spectrum)
}

void ofApp::generativeLines(){
  // ofColor whiteHDR(255, 255, 255,100);
  ofSetColor(255,255,255,100);
  lijntje.draw();
  if(peaked == true){
    lijntje.addVertex(ofRandom(width),ofRandom(height));
    //draw a new line everytime peaked == true
    for(int i = 0; i < 100; i ++){
      // ofDrawLine(ofRandom(width),ofRandom(height),ofRandom(width),ofRandom(height));
    } //src https://www.youtube.com/watch?v=S4KMORhoFMk
  }
}

// void ofApp:reactiveCircleFractal(){
//   if(peaked == true && energy < 7){
//     energy +=1;
//     radiusIncrement = pow(0.75,energy) *ofGetWidth()/2;
//   } else {energy = 0;}
// }
//bloom = HDR & blur

void ofApp::keyPressed(int key){
  if (key == 't'){
  }
}
