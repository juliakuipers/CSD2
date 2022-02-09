#pragma once
#include <iostream>

class CircularBuffer{
    public:
        CircularBuffer(int size, int numSamplesDelay);
        //numSamplesDelay, space between readIndex and writeIndex 
        ~CircularBuffer();

        float read();
        // in here i return the delayed samples 
        void write(float value);  
        //in this i write the samples in the buffer      

    private:
        int wrap(int head);
        //makes it so that when the buffer is at it's end the read and write head get reset back to the beginning

        int size; 
        //size of the buffer, depending on how long i want the delay to be 
        int numSamplesDelay;
        //amount of samples delay 
        int readIndex;
        //read the samples out of the buffer 
        int writeIndex;
        //write the info of the samples in the buffer 
        float* buffer;

        //the readIndex an writeIndex are always equally far apart = numSamplesDelay
        //everytime a sample goes through the buffer gets filled one step

};