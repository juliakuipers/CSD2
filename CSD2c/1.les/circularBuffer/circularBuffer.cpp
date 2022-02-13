#include "CircularBuffer.h"

// CircularBuffer::CircularBuffer(){};
CircularBuffer::CircularBuffer(int size, int numSamplesDelay) :
  readIndex(0), writeIndex(0)
  {
    this -> size = size;
    this -> numSamplesDelay = numSamplesDelay;

    std::cout << "Constructor - CircularBuffer \n";

    buffer = new float [size];
    //this way i can indicate how large i want the buffer size to be

  }

  CircularBuffer::~CircularBuffer()
  {
    std::cout << "Destructor - CircularBuffer \n";
    delete [] buffer;
    buffer = nullptr;
  }

  void CircularBuffer::setReadIndex()
  {
    //setReadIndex should only be used when i change the delay time and in the beginning when initilizing the delay
    readIndex = size - numSamplesDelay;
    std::cout << "Constructor - setReadIndex - readIndex " << readIndex << "\n";
    //so i checked the readIndex and it works like this, it could be that in my previous code it didn't work because i also work with wrap;
  }

  void CircularBuffer::write(float sample)
  {
    buffer[writeIndex] = wrap(buffer[writeIndex]);
    buffer[writeIndex] = sample;
  }

  float CircularBuffer::read()
  {
    buffer[readIndex] = wrap(buffer[readIndex]);
    return buffer[readIndex];
  }

  int CircularBuffer::wrap(int head){
    if(head >= size){
      head -= size;
    }
    std::cout << "CircBuffer - wrap - head " << head << "\n";
    return head;
  }
