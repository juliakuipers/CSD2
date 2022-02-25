#include "chorus.h"
#include "square.h"

Chorus::Chorus()
{
  std::cout << "Chorus - Constructor \n";
  osc = new Square(440,44100);
  circ = new CircularBuffer(4,2);
}

Chorus::~Chorus()
{
  std::cout << "Chorus - Destructor \n";
  delete osc;
  delete circ;
  osc = nullptr;
  circ = nullptr;
}
