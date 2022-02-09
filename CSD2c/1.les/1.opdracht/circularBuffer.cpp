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

CircularBuffer::CircularBuffer(int size, int numSamplesDelay) : readIndex(size - numSamplesDelay),writeIndex(0){
    this -> size = size;
    this -> numSamplesDelay = numSamplesDelay;
    std::cout << "Constructor \n";
    buffer =  new float[size]; 

}

CircularBuffer::~CircularBuffer(){
    std::cout << "Destructor \n";
    delete [] buffer;
    buffer = nullptr;
}

void CircularBuffer::write(float value){
    // std::cout << "circularBuffer - write \n"; 
    buffer[writeIndex] = value;
    writeIndex = wrap(buffer[writeIndex]);
    //so in the writeIndex i input the value of the sample that get put into write 
}

float CircularBuffer::read(){
    // std::cout << "circularBuffer - buffer[readIndex] " << buffer[readIndex] <<  "\n";
    //something goes wrong when calculating the buffer[readIndex]
    //should only read the index once it surpasses 0
    readIndex = wrap(buffer[readIndex]);
    return buffer[readIndex]; 

}

int CircularBuffer::wrap(int head){
    if(head>=size){
        head-=size;
    }
    return head;
}

/* 
buffer[readIndex] = 

*/