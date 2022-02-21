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

  // float calculate(float sample);

private:
  int warp(int head);
  int readIndex;
  int writeIndex;
  int size;
  int numSamplesDelay;
  float* buffer = nullptr;

};
