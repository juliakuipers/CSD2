#include "circularBuffer.h"
/*
Circular buffer 
- buffer 
- read index 
- write index
initialize
write value 
read value 
wrap
*/

CircularBuffer::CircularBuffer(int size, int numSamplesDelay) : size(size), numSamplesDelay(numSamplesDelay){
    std::cout << "Constructor \n";
    buffer =  new float[size]; 

}

CircularBuffer::~CircularBuffer(){
    std::cout << "Destructor \n";
}

void CircularBuffer::write(float value){
        buffer[writeIndex] = value;
}

float CircularBuffer::read(){
    return buffer[readIndex];  
}