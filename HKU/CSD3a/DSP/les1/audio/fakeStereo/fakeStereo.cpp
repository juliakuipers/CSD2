#include "fakeStereo.h"

FakeStereo::FakeStereo(int channel_){
  // apf = new AllPassFilter();
  this -> channel = channel_;
  std::cout << "fakestereo Constructor channel = " << channel << '\n';
}

FakeStereo::~FakeStereo(){
  // delete apf;
  // apf = nullptr;
}
