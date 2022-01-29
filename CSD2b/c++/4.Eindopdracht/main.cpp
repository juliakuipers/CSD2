#include <iostream>
#include "synth.h"
#include "FmSynth.h"
#include <thread>


//TODO be able to call Fmsynth in main with right settings 
int main(){
    double samplerate = 44100;
    FmSynth synth(samplerate,48,0.5);
    synth.mTof();
    synth.setAmp();
    synth.calculate();
    
}