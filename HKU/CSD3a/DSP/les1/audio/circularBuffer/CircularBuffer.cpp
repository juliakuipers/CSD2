#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int size, int numSamplesDelay) : readIndex(0), writeIndex(0)
{
  this -> size = size;
  this -> numSamplesDelay = numSamplesDelay;
  buffer = new float [size];
  setReadIndex(numSamplesDelay);
}

CircularBuffer::~CircularBuffer()
{
  delete [] buffer;
  buffer = nullptr;
}

void CircularBuffer::setReadIndex(int numSamplesDelay)
{
  readIndex = writeIndex - numSamplesDelay + size;
  readIndex = warp(readIndex);
}

void CircularBuffer::write(float sample)
{
  buffer[writeIndex++] = sample;
  writeIndex = warp(writeIndex);
}

float CircularBuffer::read()
{
  float sample = buffer[readIndex++];
  readIndex = warp(readIndex);
  return sample;

}

int CircularBuffer::warp(int head)
{
  if(head>=size) head -=size;
  return head;
}
