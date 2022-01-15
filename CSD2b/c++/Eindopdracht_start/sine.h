#include "oscillator.h"

class Sine : public Oscillator {
  public:
    //Constructor and destructor
    Sine(double samplerate,double freq);
    ~Sine();

    void tick();

  protected:
    double phase;
    double freq;
    double samplerate;
};


