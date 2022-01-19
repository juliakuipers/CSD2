#pragma once

class Synth {
    public:
        Synth(double samplerate);
        ~Synth();
        

    protected:
    //protected means this cannot be accessed from outside the class
    //can be accessed in inhereted classes 
        double samplerate;
};

