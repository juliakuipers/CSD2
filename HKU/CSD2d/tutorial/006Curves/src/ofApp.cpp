
#include "ofApp.h"

ofApp::ofApp() : curveFittingFactor(0.1), margin(ofGetHeight()*0.1), accel(0), steps(ofGetWidth()/16){
    x = new float[steps];
    y = new float[steps];
    xSpeed = new float[steps];
    ySpeed = new float[steps];
}

ofApp::~ofApp(){
    delete x;
    delete y;
    delete xSpeed;
    delete ySpeed;
    x = nullptr;
    y = nullptr;
    xSpeed = nullptr;
    ySpeed = nullptr;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//    drawCurve();
//    drawVerticalLine();
//    drawDiagonalLine();
//    randomStrands();
    drawCircleLine();
}

void ofApp::drawVerticalLine()
{
    int margin = ofGetHeight()/3;
    //margin = ruimte plaats ect
    //how smaller the /x number the smaller the line
    for (int i=margin; i<ofGetHeight()-margin; i++)
    {
        //line that gets drawn from the margin value to the heigt - margin value
        float random = ofRandom(0,5);
        ofDrawEllipse(i + (margin / 2) + random, i, 3, 3);
        //x stays constant y changes
    }
}


void ofApp::drawDiagonalLine()
{
    int marginW = ofGetWidth()/15;
    float x = marginW;
    float y = marginW;
//    int marginH = ofGetHeight()/15;
//    float y = marginH;
    float deltaX = 1.0;
    float deltaY = 0.5;
    
    if (deltaX>deltaY)
        {
            while(x<ofGetWidth()-marginW)
            {
                ofDrawEllipse(x, y, 3, 3);
                x += deltaX;
                y += deltaY;
            }
        } else {
            while(y<ofGetWidth()-marginW){
                ofDrawEllipse(x, y, 3, 3);
                x += deltaX;
                y += deltaY;
            }
        }
}


void ofApp::drawCurve()
{
    float xSpeed = 1.1;
    float ySpeed = 1.02;
    float marginH = ofGetHeight()/15;
    float x = marginH;
    float y = marginH;
    
    while(y<ofGetHeight()-marginH)
    {
        ofDrawEllipse(x, y, 3, 3);
        x +=xSpeed; // arithmetic progression
        y *=ySpeed; // geometric progression
    }
}

void ofApp::randomStrands(){
    for(int i = 0; i < steps; i++){
        x[i] = 0;
        y[i] = ofRandom(margin);
        xSpeed[i] = ofRandom(0.75, 1.04);
        ySpeed[i] = ofRandom(1.0075,1.04);
    }
    
    for(int i = 0; i < steps; i++){
        while(y[i] < ofGetHeight()){
            ofDrawEllipse(x[i], y[i], 3, 3);
            x[i]+=xSpeed[i];
            y[i]*=ySpeed[i];
            if(y[i] >= ofGetHeight()){ySpeed[i] *= -1;}
        }
    }
}

void ofApp::drawCircleLine(){
    for(int i = 0; i < 16; i++){
        x[i] = steps * i;
        y[i] = ofGetHeight()/2;
        xSpeed[i] = i*1.3;
    }
    for(int i = 0; i < 16; i++){
            ofDrawEllipse(x[i], y[i], xSpeed[i], xSpeed[i]);
    }
//    ofBackground(0);
}
