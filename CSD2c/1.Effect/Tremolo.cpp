#include "Tremolo.h"
#include "square.h"
#include "sine.h"

Tremolo::Tremolo(float freq,float samplerate)
{
  osc = new Sine(freq,samplerate);
}

Tremolo::~Tremolo()
{}

void Tremolo::setModFreq()
{
  float setMFreq;
  while(1){
    std::cout << " Tremolo - setModFreq " << std::endl;
    std::cin >> setMFreq;
    if(std::cin.fail()) std::cin.clear();
    if(!std::cin.fail()) break;
    }
    std::cout << "Tremolo setModFreq break \n" ;
    osc->setFrequency(setMFreq);
    //source https://www.hackerearth.com/practice/notes/validating-user-input-in-c/
}

float Tremolo::calculate(float sample)
{
  modSig = (osc->genNextSample() + 1.0)*0.5;
  // std::cout << "Tremolo::calculate - modSig = " << modSig << std::endl;
  return sample * modSig;
}
