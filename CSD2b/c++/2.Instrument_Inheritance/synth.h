#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "instrument.h"

class Synth : public Sound { //public Sound anders is het private 
public: 
    Synth();
    ~Synth();
    void play();
    int velocity();
    void pitch(); 
    void fm();
p
};

#endif
