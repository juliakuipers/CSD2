#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_
#include <iostream>

class Sound {
public: 
    Sound();
    ~Sound();
    void play();
    int pitch();
    int velocity();
    int roll();

};

#endif