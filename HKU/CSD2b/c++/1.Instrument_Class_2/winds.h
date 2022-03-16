//#pragma once 
#ifndef _WINDS_H_
#define _WINDS_H_
#include "sound.h"
#include <iostream>

class Winds : public Sound {//deze hoort bij sound als subclass
public: 
    Winds();
    ~Winds();
    void flute();
    void clarinet();

};

#endif