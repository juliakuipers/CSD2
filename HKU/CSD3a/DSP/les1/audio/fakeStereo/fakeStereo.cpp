#include "fakeStereo.h"

FakeStereo::FakeStereo(int channel_){
  apf = new AllPassFilter();
  this -> channel = channel_;
  std::cout << "fakestereo Constructor channel = " << channel << '\n';
}

FakeStereo::~FakeStereo(){
  delete apf;
  apf = nullptr;
}

float FakeStereo::returnStereo(float input_){
  float output = apf->allPass(input_);
  return output;
}

//two allpass need to be initalated with different delay settings
