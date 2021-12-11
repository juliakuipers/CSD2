#ifndef _SYNTH_H_
#define _SYNTH_H_
#include "instrument.h"

class Synth : public Sound { //public Sound anders is het private 
public: 
    Synth();
    Synth(int velocity,std::string pitch);
    ~Synth();

    int getVel();
    void getPitch();
    void setVel(int vel);
    void setPitch();

private:
    int vel;
    void pi; 
    void fm();
};

#endif
