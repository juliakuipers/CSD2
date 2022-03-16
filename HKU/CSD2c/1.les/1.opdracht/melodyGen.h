#pragma once
#include <iostream>

class MelodyGen
{
public:
  MelodyGen(float samplerate);
  ~MelodyGen();

  int melody();


private:
  unsigned int sampleCount;
  float samplerate;
  unsigned int freqList[8] = {110,220,330,440,550,660,770,880};
  int index;

};
