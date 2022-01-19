#pragma once 

class Synth {
    public:
        Synth(double samplerate);
        //samplerate gets configurated in main 
        //frequency in Synth or oscillator? 
        ~Synth();

        double getSample();

    protected:
    //protected means this cannot be accessed from outside the class
    //can be accessed in inhereted classes 
        double sample; 
        double samplerate;
};