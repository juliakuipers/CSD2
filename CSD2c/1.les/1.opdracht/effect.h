#pragma once
#include <iostream>

class Effect{
    public:
        Effect(float freq, float samplerate);
        virtual ~Effect();

        float calcDryWet(float drywet);
        float getSample(float sample);

        virtual float calculate(float sample) = 0;
        void setDryWet();

    protected:
      float drywet = 101;
      // float scaledDW;

    private:


};

//for both the delay and the tremolo it would be best if the effect sends the sample back
//value and sample are the same thing, depending on what i choose to use in the constructor i can return a sample of the tremolo or the delay
//should probably work with a pointer that points to either tremolo or delay for calculate
