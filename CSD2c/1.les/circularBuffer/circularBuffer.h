#include <iostream>

class CircularBuffer{
    public:
        CircularBuffer(int size, int numSamplesDelay);
        //numSamplesDelay, space between readIndex and writeIndex 
        ~CircularBuffer();

        float read();
        void write(float value);       

    private:
        int readIndex;
        //positions in the list 
        int writeIndex;
        int size; 
        float numSamplesDelay;
        float* buffer;
};