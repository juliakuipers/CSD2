#pragma once
#include <iostream>

class Oscillator{
    public: 
        Oscillator(double samplerate);
        virtual ~Oscillator();

        virtual void calculate() = 0;
        virtual double getSample() = 0;
        void tick();


    protected:
        //double freq;
        double amp; 
        double sample; 
        double phase; 
        double samplerate;
        double freq;

};