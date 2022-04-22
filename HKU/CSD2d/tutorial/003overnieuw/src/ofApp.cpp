#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofSetCircleResolution(100);
    ofSetDepthTest(true);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float time = ofGetElapsedTimef();
    for(int i = 0; i < 900; i+=5)
    {
        ofDrawCircle(ofGetWidth()/2 + 100 * sin(i * 0.01 + time), 50 + i, 50 + 40 * sin(i * 0.005 + time));
    }
}

void ofApp::keyPressed(int key){

}

