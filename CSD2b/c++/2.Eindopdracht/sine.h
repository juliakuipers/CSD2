#include "synth.h"
#include "oscillator.h"

class Sine : public Synth, public Oscillator {
  public:
  //Constructor and destructor
    Sine(double samplerate, double freq, double amp);
    ~Sine();

    void calculate();
    double getSample();

  private:
    double phase;
    double sample;
};

