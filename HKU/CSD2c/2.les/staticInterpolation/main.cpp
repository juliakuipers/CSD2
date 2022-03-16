#include "staticInterpolation.h"

int main()
{
  float bufferArray[4] = {0.1,0.8,0.3,0.6};
  StaticInterpolation sI;

  for(int i = 0 ; i < 4 ; i ++)
  {
    std::cout << "main - bufferArray[i] " << bufferArray[i] << std::endl;
    std::cout << "main - sI.nnMap(bufferArray[i]) " << sI.nnMap(bufferArray[i]) << std::endl;
    std::cout << "main - sI.linMap(bufferArray[i]) " << sI.linMap(bufferArray[i]) << std::endl;
  }
}
