#pragma once
#include <iostream>

class CircularBuffer{
    public:
      CircularBuffer();
      CircularBuffer(int size, int numSamplesDelay);
      ~CircularBuffer();

      void setReadIndex();
      void write(float sample);
      float read();
      void calculateRW();

    private:
      int readIndex;
      int writeIndex;
      int wrap(int head);
      int size;
      int numSamplesDelay;
      float* buffer = nullptr;
};
