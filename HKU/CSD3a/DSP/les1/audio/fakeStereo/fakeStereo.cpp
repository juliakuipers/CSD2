#include "fakeStereo.h"

FakeStereo::FakeStereo(int channel_) : output(0){
  apf1 = new AllPassFilter();
  apf2 = new AllPassFilter();
  modDelay(channel_,1);
  // modDelay(channel_,100);

}

FakeStereo::~FakeStereo(){
  delete apf1;
  delete apf2;
  apf1 = nullptr;
  apf2 = nullptr;
}

float FakeStereo::returnStereo(float input_, int channel_){
  if(!channel_){
    output = apf1->allPass(input_);
  }
  if(channel_){
    output = apf2->allPass(input_);
  }
  return output;
}

void FakeStereo::modDelay(int channel_, float time){
  if(!channel_){
    apf1->setDelayTime(time);
  }
  if(channel_){
    apf2->setDelayTime(time);
  }
}

//two allpass need to be initalated with different delay settings
