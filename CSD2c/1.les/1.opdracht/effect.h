#pragma once
#include <iostream>

class Effect{
    public:
        Effect(float freq, float samplerate);
        virtual ~Effect();

        float calcDryWet(float drywet);
        float getSample(float sample);

    protected:
        virtual float process(float sample) = 0;
        
    private:
        // virtual float process(float sample) = 0;
        
};

//for both the delay and the tremolo it would be best if the effect sends the sample back
//value and sample are the same thing, depending on what i choose to use in the constructor i can return a sample of the tremolo or the delay