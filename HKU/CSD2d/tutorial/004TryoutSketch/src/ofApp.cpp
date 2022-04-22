#include "ofApp.h"

ofApp::ofApp() : grad(0), gradColorSpeed(0.1){}

ofApp::~ofApp(){}

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int interval = 255;
    float rad = ofGetHeight()/8;
    for(float i = 0; i < 255; i++)
    {
        ofColor colorOne(grad);
        ofColor colorTwo(0);
        ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_CIRCULAR);
        grad += gradColorSpeed;
        std::cout << "grad: " << grad << endl;
        if(grad > 255){gradColorSpeed *= -1;}
        // Sets the background to a circular gradient
    }
    //float time = ofGetElapsedTimef(); // get a continouis value
    ofEnableAlphaBlending();    // turn on alpha blending
    ofSetColor(175,238,238,50);
    //ofSetColor(175); // greyscale 
    ofFill();
    //ofNoFill(); //for noFill
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2,rad);
//    ofDrawBox(64, 64, 100, 50, 60, 200); // 3Dshape
//    ofDrawCone(100, 100, 100, rad, ofGetHeight()/4);
    ofDisableAlphaBlending();   // turn it back off, if you don't need it
}
