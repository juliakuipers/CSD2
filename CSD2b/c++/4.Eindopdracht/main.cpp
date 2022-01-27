#include <iostream>
#include "synth.h"
#include <thread>

int main(){
    double samplerate = 44100;
    Synth synth(samplerate,48,0.5);
    synth.mTof();
}