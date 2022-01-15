#pragma once 



class Oscillator {
    public:
        Oscillator(double samplerate,double freq);
        //samplerate gets initialized in main
        ~Oscillator(); 

        //void setFreq(double freq);
        void setAmp(double amp);
        float getSample();

    protected:
    
        double freq;
        double amp;
        double sample; 
        double samplerate; 
};
