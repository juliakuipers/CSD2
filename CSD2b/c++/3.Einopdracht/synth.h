#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "sine.h"
#include "saw.h"

class Synth{
    public:
        Synth(double samplerate);
        virtual ~Synth();

        virtual double getSample()=0;
        virtual void calculate()=0; //=leeg 
        //virtual zit een functie die niet wordt aangemaakt in de base class maar wel bestaat en in de derived class kan worden aangeroepen en verandert 
        void waveForm();
        void set();
    
    protected:
        double samplerate;
        Sine* sine = nullptr;
        Saw* saw = nullptr;
    };

#endif