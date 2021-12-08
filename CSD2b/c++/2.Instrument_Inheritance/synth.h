#include "instrument.h"

class Synth : public Sound {
public: 
    Synth(int velocity, std::string pitch);
    ~Synth();
    void play();
    void fm();
    //void envelope();
    //void lfo();

};

