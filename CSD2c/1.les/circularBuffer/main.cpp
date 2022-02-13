#include "CircularBuffer.h"
#include <iostream>

int main(){

int size = 10;
int foo [10] = { };
int numSamplesDelay= 1;

CircularBuffer cb(size, numSamplesDelay);
//initilize CircularBuffer
cb.setReadIndex();
cb.calculateRW();
//set the readIndex of the buffer
//so apparantly cpp cant print entire lists

for(int i = 0 ; i < size ; i++){
  foo[i] = i;
  cb.write(foo[i]);
  // std::cout << "main - foo[i]" << foo[i] << "\n";
  cb.read();
  cb.calculateRW();
}
cb.calculateRW();



}
