#include <iostream>
#include "allPassFilter.h"

class FakeStereo
{

public:
  FakeStereo(int channel_);
  ~FakeStereo();
  //should dynamically allocate apf since the circbuffer needs to be deleted
  void modDelay(int channel_, float time);
  //use switch function for modDelay
  //modulate delay in ms?
  float returnStereo(float input_, int channel_);

private:
  AllPassFilter* apf1;// = nullptr;
  AllPassFilter* apf2;// = nullptr;
  int channel;
  float output;

};

// two allPassFilters, different delay time
// maybe one allPassFilter, function can be called twice in main
// argument which implies whether it should be left or right (0,1)?
// fuction to modulate delays
