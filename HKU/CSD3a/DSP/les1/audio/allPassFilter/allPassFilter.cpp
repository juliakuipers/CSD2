#include "allPassFilter.h"

AllPassFilter::AllPassFilter() : delay1(0), delay2(0), output(0) {
  circ1 = new CircularBuffer(5,1);
  circ2 = new CircularBuffer(5,1);
}

AllPassFilter::~AllPassFilter() {
  delete circ1;
  circ1 = nullptr;
  delete circ2;
  circ2 = nullptr;
}

float AllPassFilter::allPass(float input_){
  output = kamFilterFIR(kamFilterIIR(input_));
  std::cout << "AllPassFilter::allPass input = " << input_ << '\n';
  std::cout << "AllPassFilter::allPass output = " << output << '\n';
  return output;
}

float AllPassFilter::kamFilterFIR(float input)
{
  //circBuffer???
  circ1->write(input);
  output = input + circ1->read();
  std::cout << "AllPassFilter::kamFilterFIR circ1->read() = " << circ1->read() << '\n';
  std::cout << "AllPassFilter::kamFilterFIR input = " << input << '\n';
  std::cout << "AllPassFilter::kamFilterFIR output = " << output << '\n';
  return output;
}

float AllPassFilter::kamFilterIIR(float input)
{
  circ2->write(input);
  output = input - circ2->read();
  std::cout << "AllPassFilter::kamFilterIIR circ2->read() = " << circ2->read() << '\n';
  std::cout << "AllPassFilter::kamFilterIIR input = " << input << '\n';
  std::cout << "AllPassFilter::kamFilterIIR output = " << output << '\n';
  return output;
}

void AllPassFilter::setDelayTime(float time){
  circ1->setReadIndex(time);
  circ2->setReadIndex(time);
}
