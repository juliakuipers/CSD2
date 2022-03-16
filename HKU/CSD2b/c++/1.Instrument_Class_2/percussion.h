#ifndef _PERCUSSION_H_
#define _PERCUSSION_H_
#include "sound.h"
#include <iostream>

class Percussion : public Sound{
public: 
    Percussion();
    ~Percussion();
    void play();
    int roll();

};

#endif