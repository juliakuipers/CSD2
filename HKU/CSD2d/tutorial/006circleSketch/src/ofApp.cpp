#include "ofApp.h"
ofApp::ofApp() : rad(100), growW(1), growH(1) {}

ofApp::~ofApp(){}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float xRand = ofRandom(-1, 1);
    float yRand = ofRandom(-1, 1);
    float x = (ofGetWidth()/2);
    float y = (ofGetHeight()/2) + growH;
    ofNoFill();
//    ofSetColor(0);
//    ofFill();
//    ofSetIcoSphereResolution(20);
    ofDrawIcoSphere(x + xRand, y + yRand, rad + 100);
//    ofSetColor(255);
//    ofFill();
    ofDrawIcoSphere(x + xRand, y + yRand, rad);
    growW += 3;
//    growH += 7;
    ofRotateRad(growW);
    if(x > ofGetWidth()){x *= -1;}
    if(y > ofGetHeight()){y *= -1;}
}

//ofRandom() //get two random numbers betweer (x,x)
//ofRandomWidth/ofRandomHeight

//see if i can make something move shockingly/thrillingly
