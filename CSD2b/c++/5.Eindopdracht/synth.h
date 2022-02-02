#pragma once
#include <iostream>

class Synth{
    public:
        Synth(double samplerate);
        ~Synth();

        virtual void calculate() = 0;
        virtual double getSample() = 0;
        virtual double mTof(double midi) = 0; 

    protected:
        double samplerate;
};