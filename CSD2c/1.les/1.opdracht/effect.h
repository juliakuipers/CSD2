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
        int bypass();
        // what if i want to use two effects at the same time?
        // feedback

    protected:
      float drywet = 101;
      float feedback;
      //feedback drywet

    private:
      int onoff = 1;


};

//feedback is the used and modified signal getting send back into the calculate function
//might work with virtual and override and then
