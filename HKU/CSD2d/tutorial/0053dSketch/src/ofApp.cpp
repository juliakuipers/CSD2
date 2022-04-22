#include "ofApp.h"

ofApp::ofApp() : xPlane(0), xPlaneSpeed(0.02), yPlane(0),yPlaneSpeed(0.2){}

ofApp::~ofApp(){}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(255,182,193);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofDrawPlane(xPlane, yPlane, ofGetWidth()/2, ofGetHeight()/2);
    xPlane =+ xPlaneSpeed;
    yPlane =+ yPlaneSpeed;
    
    if(xPlane > ofGetWidth()){xPlane == 0;}
    if(yPlane > ofGetHeight()){yPlane == 0;}
    
    std::cout << "xPlane = " << xPlane << std::endl;
    std::cout << "yPlane = " << yPlane << std::endl;
}
