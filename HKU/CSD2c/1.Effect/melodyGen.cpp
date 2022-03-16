#include "melodyGen.h"

MelodyGen::MelodyGen(float samplerate) : sampleCount(0), index(0){
  this -> samplerate = samplerate;
}

MelodyGen::~MelodyGen(){}


int MelodyGen::melody()
{
  sampleCount += 1;
  if(sampleCount >= samplerate)
  {
    sampleCount = 0;
    index += 1;
    if(index>=8) index = 0;
  }
  return freqList[index];
}
