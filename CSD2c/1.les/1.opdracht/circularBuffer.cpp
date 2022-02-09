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


CircularBuffer::CircularBuffer(int size, int numSamplesDelay) : numSamplesDelay(numSamplesDelay){
    std::cout << "Constructor \n";
    buffer =  new float[size]; 

}

CircularBuffer::~CircularBuffer(){
    std::cout << "Destructor \n";
}

void CircularBuffer::write(float value){
    std::cout << "circularBuffer - write \n"; 
    buffer[writeIndex] = value;
    //so in the writeIndex i input the value of the sample that get's put in write 
}

float CircularBuffer::read(){
    std::cout << "circularBuffer - buffer[readIndex] " << buffer[readIndex] <<  "\n";
    //something goes wrong when calculating the buffer[readIndex]
    //should only read the index once it surpasses 0
    return buffer[readIndex] = buffer[writeIndex] - numSamplesDelay;  
}