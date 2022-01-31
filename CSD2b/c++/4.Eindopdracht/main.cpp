#include <iostream>
#include "synth.h"
#include "FmSynth.h"
#include <thread>


//TODO be able to call Fmsynth in main with right settings 
int main(){
    double samplerate = 44100;
    //Synth synth(samplerate,48,0.5);
    FmSynth fmsynth(samplerate,48,0.5);
    fmsynth.mTof();
    fmsynth.setAmp();
    fmsynth.calculate();
    fmsynth.getSample();
    
}