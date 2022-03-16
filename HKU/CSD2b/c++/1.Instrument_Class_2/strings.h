#ifndef _STRINGS_H_
#define _STRINGS_H_
#include "sound.h" 
#include <iostream>

class Strings : public Sound{
public: 
    Strings();
    ~Strings();
    void guitar();
    void violin();
    int roll();

};

#endif