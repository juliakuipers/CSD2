#include "oscillator.h"

class Sine : public Oscillator {
  public:
    //Constructor and destructor
    Sine(double samplerate,double freq,double amp);
    ~Sine();

    void calculate();

  protected:
    double phase;
    //double freq;
    //double samplerate;
};


