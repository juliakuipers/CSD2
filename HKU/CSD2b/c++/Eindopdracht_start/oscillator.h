#pragma once 

class Oscillator {
    public:
        Oscillator(double samplerate,double freq,double amp);
        //samplerate gets initialized in main
        ~Oscillator(); 

        void setFreq(double freq);
        void setAmp(double amp);
        //void mod(double mFreq);
        float getSample();

    protected:
    
        double freq;
        double amp;
        double sample; 
        double samplerate; 
};
