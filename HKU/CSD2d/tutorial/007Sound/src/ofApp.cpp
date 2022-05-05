#include "ofApp.h"
AudioFile<float> audioFile;

ofApp::ofApp() : numSamples(audioFile.getNumSamplesPerChannel()), bandsAmount(5){
    buffer = new float [numSamples];
//    mySound.load("shanti.mp3");
//    mySound.play();
}

ofApp::~ofApp(){
    delete buffer;
    buffer = nullptr;
}

//i deleted ofApp::setup() and ofApp::update()

//--------------------------------------------------------------
void ofApp::draw(){
//    float * fft = ofSoundGetSpectrum(bandsAmount);
//
//    for(int i = 0; i < bandsAmount; i ++){
//        float getDing = ofGetWidth() / (i+1);
//        float result = ofLerp(1, ofGetHeight(), fft[i]);
//        ofDrawLine(getDing,0,getDing,result);
////        std::cout << "ofGetWidth() = " << ofGetWidth() << std::endl;
////        std::cout << "i + 1 = " << i + 1 << std::endl;
////        std::cout << "getDing = " << getDing << std::endl;
//        std::cout << "result = " << result << std::endl;
//    }
    
//    ofDrawCurve(200, 200, 0,ofGetHeight()/2, ofGetWidth() , ofGetHeight()/2, 200, 20);
    
    
      int spacing = 50;
      ofBeginShape();
      for(int x=0; x<ofGetWidth(); x+= spacing) {
          ofCurveVertex(x, ofGetHeight()/2 + ofGetHeight() * 0.3f * sin(x*0.01f + ofGetFrameNum() * 0.02f));
      }
      ofEndShape(false);
    //https://forum.openframeworks.cc/t/drawing-a-curved-line/1141/3
    
//    ofBeginShape();
//        ofVertex(0,ofGetHeight()/2);
//        ofVertex(ofGetWidth()/2, ofGetHeight());
//        ofVertex(ofGetWidth(), ofGetHeight()/2);
//        ofVertex(ofGetWidth()/2,0);
//    ofEndShape();
    
}

