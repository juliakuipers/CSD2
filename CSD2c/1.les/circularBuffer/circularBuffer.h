#pragma once
#include <iostream>

class CircularBuffer{
    public:
      // CircularBuffer();
      CircularBuffer(int size, int numSamplesDelay);
      ~CircularBuffer();

      void setReadIndex();
      void write(float sample);
      //function wherein i write the buffer, this one is always a few steps ahead of the read
      float read();

    private:
      int size;
      int numSamplesDelay;
      int readIndex;
      int writeIndex;
      int wrap(int head);
      float* buffer = nullptr;
};
