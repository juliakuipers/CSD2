#include "CircularBuffer.h"
#include <iostream>

int main(){

int list = 10;
int array [10] = {1,2,3,4,5,6,7,8,9,10};
int numSamplesDelay= 8;

std::cout << "Main - array " << array << "\n";

CircularBuffer cb(list, numSamplesDelay);
//initilize CircularBuffer
cb.setReadIndex();
//set the readIndex of the buffer
std::cout << "main - array " << array << "\n";

for(int i = 0 ; i < list ; i++){
  array[i] = i;
  std::cout << "main - forloop - array " << array << "\n";
  std::cout << "main - i " << i << "\n";
}




}
