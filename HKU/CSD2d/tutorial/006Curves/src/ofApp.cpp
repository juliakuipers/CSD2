
#include "ofApp.h"

ofApp::ofApp() : curveFittingFactor(0.1){}

ofApp::~ofApp(){}

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawCurve();
//    drawVerticalLine();
//    drawDiagonalLine();
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
