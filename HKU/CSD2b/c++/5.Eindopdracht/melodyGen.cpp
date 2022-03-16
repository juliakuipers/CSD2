#include "melodyGen.h"

MelodyGen::MelodyGen(double samplerate, Synth* synth){
    this->synth = synth;
    this ->samplerate = samplerate; 
}

MelodyGen::~MelodyGen(){

}

void MelodyGen::tick(){
    sampleCount += 1;
    if(sampleCount >= samplerate){
        sampleCount = 0;
        synth->mTof(list[index]);
        index += 1;
        if(index>3){
          index = 0;
        }
      
    }
}