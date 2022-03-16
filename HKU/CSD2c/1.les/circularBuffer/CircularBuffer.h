#pragma once
#include <iostream>

class CircularBuffer{
    public:
      CircularBuffer();
      CircularBuffer(int size, int numSamplesDelay);
      ~CircularBuffer();

      void setReadIndex();
      void write(float sample);
      //function wherein i write the buffer, this one is always a few steps ahead of the read
      float read();
      void calculateRW();

    private:
      int readIndex;
      int writeIndex;
      int wrap(int head);
      float sample;
      int size;
      int numSamplesDelay;
      float* buffer = nullptr;
};
