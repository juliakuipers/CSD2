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
CircularBuffer::CircularBuffer(float size, float numSamplesDelay) :
 readIndex(size - numSamplesDelay),writeIndex(0){
   this -> size = size;
   this-> numSamplesDelay = numSamplesDelay;
//                                                                                          maybe make a seperate function to set the readIndex
    std::cout << "CircularBuffer - Constructor \n";
    buffer =  new float[size];


}

CircularBuffer::~CircularBuffer(){
    std::cout << "Circular - Destructor \n";
    delete [] buffer;
    buffer = nullptr;
}

void CircularBuffer::setReadIndex(float numSamplesDelay){
  if(size - numSamplesDelay >= 0){
    readIndex = size - numSamplesDelay;
    std::cout << "CircularBuffer - setReadIndex - readIndex " << readIndex << "\n";
    }   else
        readIndex = 0;
  }

void CircularBuffer::write(float sample){
    //either the buffer or the write is not right
    //something might go wrong with the buffer itself but the number i get when i print buffer could also be because its such a big buffer
    std::cout << "CircularBuffer - write - sample " << sample << "\n";
    buffer[writeIndex++] = sample;


    writeIndex = wrap(writeIndex);
    //so in the writeIndex i input the value of the sample that get put into write
}

float CircularBuffer::read(){
    float sample = buffer[readIndex++];
    readIndex = wrap(readIndex);
    return sample;

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
