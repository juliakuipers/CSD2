#pragma once
#include <iostream>
#include "effect.h"
#include "circularBuffer.h"

class Delay : public Effect{
    public:
        Delay(float freq, float samplerate);
        ~Delay();

        //maybe multiply the returned signal with feedback in terms of what gets send back
        //the function calculate should also return in feedback which returns to calculate
        //so the signal of the return sample * feedback

        float calculate(float sample) override;

    protected:
        // virtual void setReadIndex(int numSamplesDelay) = 0;
        // virtual void write(float sample)= 0;
        // virtual float read()= 0;
        int size;
        //size of the buffer, depending on how long i want the delay to be
        float numSamplesDelay;
        //amount of samples delay
        float feedback;

        float drywet;
    private:
        CircularBuffer circ;
        //the incoming signal * how much wet i want

        //both drywet and feeback need setters

        //i maybe need a function calculate wich calculates the delay and return the calculated signal

};
