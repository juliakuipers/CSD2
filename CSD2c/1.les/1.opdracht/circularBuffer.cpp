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
        //so in the writeIndex i input the value of the sample that get's put in write 
}

float CircularBuffer::read(){
    return buffer[readIndex] = buffer[writeIndex] - numSamplesDelay;  
}