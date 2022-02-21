#include "CircularBuffer.h"

CircularBuffer::CircularBuffer(int size, int numSamplesDelay) : readIndex(0), writeIndex(0)
{
  this -> size = size;
  this -> numSamplesDelay = numSamplesDelay;
  buffer = new float [size];
  // setReadIndex();
}

CircularBuffer::~CircularBuffer()
{
  delete [] buffer;
  buffer = nullptr;
}

void CircularBuffer::setReadIndex()
{
  readIndex = size - 20;
}

void CircularBuffer::write(float sample)
{
  buffer[writeIndex++] = sample;
  std::cout << "CircularBuffer - write - writeIndex = " << writeIndex << std::endl;
  writeIndex = warp(writeIndex);
}

float CircularBuffer::read()
{
  float sample = buffer[readIndex++];
  std::cout << "CircularBuffer - write - readIndex = " << readIndex << std::endl;
  // std::cout << "CircularBuffer - write - sample = " << sample << std::endl;
  readIndex = warp(readIndex);
  return sample;

}

float CircularBuffer::calculate(float sample)
{
  write(sample);
  float readSample = read();
  // std::cout << "CircularBuffer - calculate - readSample = " << readSample << std::endl;
  return readSample;
}

int CircularBuffer::warp(int head)
{
  if(head>=size) head -=size;
  return head;
}
