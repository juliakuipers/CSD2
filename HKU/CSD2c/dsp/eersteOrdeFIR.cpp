#include <iostream>
#include <complex>
#include "writeToFile.h"
#include <math.h>

class FirstOrderFIR
{
public:
  FirstOrderFIR();
  ~FirstOrderFIR();

  float filter(float impulse);
  float calcFreq(float omega);

private:
  float y;
  WriteToFile* writeFile = nullptr;
  float addToSignal;
};

FirstOrderFIR::FirstOrderFIR() :
y(0), addToSignal(0.5)
{
  std::cout << "FirstOrderFIR - Constructor \n";
  writeFile = new WriteToFile("output.csv",true);
}

FirstOrderFIR::~FirstOrderFIR()
{
  delete writeFile;
  writeFile = nullptr;
}

float FirstOrderFIR::calcFreq(float omega)
{
  float e = exp(omega);
  float yn = 1 + e;
  float xn = 2;
  float hOmega = yn / xn;
  std::cout << hOmega << std::endl;
  return 0;
  //rechthoekig = bv (1+i) notatie
  //polair = angle
}

float FirstOrderFIR::filter(float impulse)
{
  std::complex<double> mycomplex(impulse, addToSignal);
  // std::complex<double> mycomplex(real, imaginary);
  static float xx = 0; //means that this value can not be changed
  y = addToSignal * (impulse + xx);
  xx = impulse;
  writeFile->write(std::to_string(y) + "\n");
  // std::cout << "y " << y << std::fixed << std::endl;
  // std::cout << "Real part: " << real(mycomplex) << std::endl;
  // std::cout << "Imaginary part: " << imag(mycomplex) << std::endl;
  return y;
}

int main()
{
  float phase = 1;
  float eToThePowerOfINOmega = sin(phase * M_PI * 2.0f );
    std::cout << "eToThePowerOfINOmega " << eToThePowerOfINOmega << std::endl;
  // float eToThePowerOfINOmega = 1;
  FirstOrderFIR fir;
  for(int i = 0; i < 10; i++)
  {
    fir.filter(eToThePowerOfINOmega);
    eToThePowerOfINOmega = 0;
  }
  std::cout << "M_PI = " << M_PI << std::endl;
  fir.calcFreq(-M_PI/2);
}

//differential equation from formula above = y[n] = 1/2x[n] + x 1/2x[n]
//if x[n] = e^inΩ (which is a full rotation (i think))
//Ω = 2π (rotation)
//e^inΩ might be = sin(phase * M_PI * 2.0f );
//e^iomega = cos(omega)+ isin(omega)
//exp() = e
