#include <iostream>
#include "writeToFile.h"

class FirstOrderFIR
{
public:
  FirstOrderFIR();
  ~FirstOrderFIR();

  float filter(float x);

private:
  float y;
  WriteToFile* writeFile = nullptr;
};

FirstOrderFIR::FirstOrderFIR() :
y(0)
{
  std::cout << "FirstOrderFIR - Constructor \n";
  writeFile = new WriteToFile("output.csv",true);
}

FirstOrderFIR::~FirstOrderFIR()
{
  delete writeFile;
  writeFile = nullptr;
}

float FirstOrderFIR::filter(float x)
{
  static float xi = 0; //means that this value can not be changed
  y = 0.5 * (x + xi);
  xi = x;
  writeFile->write(std::to_string(y) + "\n");
  std::cout << y << std::endl;
  return y;
}

int main()
{
  int a = 1;
  FirstOrderFIR fir;
  for(int i = 0; i < 10; i++)
  {
    fir.filter(a);
    a = 0;
  }
}
