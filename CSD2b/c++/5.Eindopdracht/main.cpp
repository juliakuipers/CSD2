#include <iostream>
#include "SimpleSynth.h"

int main(){
    double samplerate = 44100;
    SimpleSynth synth(samplerate);
    synth.calculate();
    synth.getSample();
}