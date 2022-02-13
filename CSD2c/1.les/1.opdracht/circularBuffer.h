#pragma once
#include <iostream>

class CircularBuffer{
    public:
        CircularBuffer();
        CircularBuffer(float size, float numSamplesDelay);
        ~CircularBuffer();

        void setReadIndex(float numSamplesDelay);
        float read();
        void write(float sample);

    private:
        int wrap(int head);
        int size;
        //size of the buffer, depending on how long i want the delay to be
        int numSamplesDelay;
        //numSamplesDelay, space between readIndex and writeIndex
        unsigned int readIndex;
        //read the samples out of the buffer
        int writeIndex;
        //write the info of the samples in the buffer
        float* buffer;

        //the readIndex an writeIndex are always equally far apart = numSamplesDelay
        //everytime a sample goes through the buffer gets filled one step

};
