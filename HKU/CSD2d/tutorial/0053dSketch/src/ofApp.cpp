#include "ofApp.h"

ofApp::ofApp() : xPlane(ofGetWidth()/2), xPlaneSpeed(0.02), yPlane(ofGetHeight()/2),yPlaneSpeed(0.2){}

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
    ofDrawCylinder(xPlane, yPlane ,planeWidth, planeHeight);
    xPlane += xPlaneSpeed;
    yPlane += yPlaneSpeed;
    planeWidth += planeWidthSpeed;
    planeHeight += planeHeightSpeed;
    
    if(xPlane > ofGetWidth()){xPlane == 0;}
    if(yPlane > ofGetHeight()){yPlane == 0;}
    
    if(planeWidth >= ofGetWidth()) {planeWidthSpeed == 0;}
    if(planeHeight >= ofGetHeight()) {planeHeightSpeed == 0;}
    
}
