#pragma once
#include <iostream>

class Effect{
    public:
        Effect(float freq, float samplerate);
        virtual ~Effect();

        // float calcDryWet(float drywet);
        float getSample(float sample);

        virtual float calculate(float sample) = 0;
        void setDryWet();
        int bypass();
        void setFeedback();
        void setWaveform();
        void set();

    protected:
      unsigned int drywet = 0;
      unsigned int feedback = 0;

    private:
      int onoff = 1;


};

//feedback is the used and modified signal getting send back into the calculate function
//might work with virtual and override and then
