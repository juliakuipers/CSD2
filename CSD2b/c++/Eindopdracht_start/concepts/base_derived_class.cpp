#include <iostream>

//Base class
class Oscillator{
    public:
        Oscillator();
        ~Oscillator();

        void setFreq(int freq);
        //int getFreq();
        void setAmp(int amp);
        //int getAmp();

    protected:
        int freq;
        int amp;

};

//Derived class
class Sine : public Oscillator{
    public:
        Sine();
        ~Sine();
        void tick();
};

Oscillator::Oscillator(){
    std::cout 
    << "Oscillator Constructor"
    << std::endl;
}

Oscillator::~Oscillator(){
    std::cout 
    << "Oscillator Destructor"
    << std::endl;
}

void Oscillator::setFreq(int freq){
    this->freq = freq;
}

void Oscillator::setAmp(int amp){
    this->amp = amp;
}


Sine::Sine(){
    std::cout 
    << "Sine Constructor"
    << std::endl;
}

Sine::~Sine(){
    std::cout 
    << "Sine Destructor"
    << std::endl;
}
void Sine::tick(){
    std::cout
    << "Frequency ="
    << freq
    << "\namplitude ="
    << amp
    << std::endl;
}


int main(){
    Sine Sine;
    Sine.setFreq(200);
    Sine.setAmp(5);
    Sine.tick();
}