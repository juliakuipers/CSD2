#include "instrument.h"

class Synth : public Sound {
public: 
    Synth();
    ~Synth();
    void play();
    void fm();
    //void envelope();
    //void lfo();

};

