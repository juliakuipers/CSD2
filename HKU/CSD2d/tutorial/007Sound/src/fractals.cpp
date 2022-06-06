#include "fractals.h"

Fractals::Fractals(){}

Fractals::~Fractals(){}

void Fractals::circles(float x, float y, float rad){
  ofNoFill();
  ofSetLineWidth(1);
  ofDrawCircle(x,y,rad,rad);
  // if(rad > radiusIncrement && rad > 2){
  if(rad > 2){
    circles(x + rad/2,y,rad/2);
    circles(x - rad/2,y,rad/2);
    circles(x,y + rad/2,rad/2);
    circles(x,y - rad/2,rad/2);
  }
}

void Fractals::cantor(float x, float y, float length){
  if(length > 2){
    y+=100;
    ofDrawLine(x,y,x+length,y);
    cantor(x,y,length/3);
    cantor(x+length*2/3,y,length/3);
  }
}