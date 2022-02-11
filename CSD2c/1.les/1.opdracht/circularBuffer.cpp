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

// maybe i should make the relationship betweet the circbuffer and the delay the same as tremolo and square
CircularBuffer::CircularBuffer(){}
CircularBuffer::CircularBuffer(float size, float numSamplesDelay) : size(size),numSamplesDelay(numSamplesDelay),readIndex(size - numSamplesDelay),writeIndex(0){
//                                                                                          maybe make a seperate function to set the readIndex    
    std::cout << "Constructor \n";
    buffer =  new float[size]; 

}

CircularBuffer::~CircularBuffer(){
    std::cout << "Destructor \n";
    delete [] buffer;
    buffer = nullptr;
}

void CircularBuffer::setReadIndex(int numSamplesDelay){
    readIndex = size - numSamplesDelay;
}

void CircularBuffer::write(float value){
    // std::cout << "circularBuffer - write \n"; 
    buffer[writeIndex] = value;
    writeIndex = wrap(buffer[writeIndex]);
    //so in the writeIndex i input the value of the sample that get put into write 
}

float CircularBuffer::read(){
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