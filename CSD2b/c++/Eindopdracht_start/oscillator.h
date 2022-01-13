#pragma once 
//something going wrong probably with the hashtags 


class Oscillator {
    public:
        Oscillator(double freq, double samplerate);
        //both freq and samplerate get initialized in main
        ~Oscillator(); 

        void setFreq(double freq);
        void setAmp(double amp);
        float getSample();

    protected:
    
        double freq;
        double amp;
        double sample; 
        double samplerate; 
};
