#pragma once
#include "ofMain.h"

class Fractals{

  public:

    Fractals();
    ~Fractals();

    void circles(float x, float y, float rad, int radiusIncrement);
    void cantor(float x, float y, float length);
};
