#include "oscillator.h"

class Sine : public Oscillator{
  public:
    //Constructor and destructor
    Sine(double freq,double samplerate);
    ~Sine();

    void tick();

  protected:
    double phase;
    double freq;
    double samplerate;
};


