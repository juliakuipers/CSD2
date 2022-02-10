#pragma once 

class Delay{
    public:
        Delay(int size, int numSamplesDelay);
        ~Delay();

        virtual float read() = 0; //call both read and write into calculate (????)
        virtual void write(float value) = 0;
        float calculate(float value);
        //might multiply the value that gets send into write with the drywet 
        //maybe multiply the returned signal with feedback in terms of what gets send back
        //maybe i can make a something in calculate which returns feedback

        void setFeedback(int feedback);
        void setDrywet(int drywet);
        //maybe make one function for both feedback and drywet 
        void setNumSamplesDelay(int numSamplesdelay);
        void setMSecDelay(int mSec);

        //the function calculate should also return in feedback which returns to calculate 
        //so the signal of the return sample * feedback 

    protected:
        int size;
        //size of the buffer, depending on how long i want the delay to be 
        int numSamplesDelay;
        //amount of samples delay 
        int feedback;

        int drywet; 

        int mSec;
        //the incoming signal * how much wet i want 
    
        //both drywet and feeback need setters 

        //i maybe need a function calculte wich calculates the delay and return the calculated signal

};