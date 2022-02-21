#pragma once
#include <iostream>

class CircularBuffer
{
public:
  CircularBuffer(int size, int numSamplesDelay);
  ~CircularBuffer();

  void setReadIndex(int numSamplesDelay);
  void write(float sample);
  float read();

private:
  int warp(int head);
  unsigned int readIndex;
  unsigned int writeIndex;
  unsigned int size;
  int numSamplesDelay;
  float* buffer = nullptr;

};
