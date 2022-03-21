#include "pickSample.h"
AudioFile<float> audioFile;
//iterator
// #include <iterator>


PickSample::PickSample(float freq, float samplerate) //: Effect(freq,samplerate)
{
  wtf = new WriteToFile("output.csv",true);
  //make new WriteToFile
  v.clear();
  //make sure the vector is empty
  fillBuffer();
  //fill buffer with selected sample
}

PickSample::~PickSample()
{
  delete wtf;
  wtf = nullptr;
  delete buffer;
  buffer = nullptr;
  v.clear();
}

float PickSample::calculateM(float sample)
{
  sample += 1;
  cout << "PickSample::calculateM - sample =" << sample <<"\n ";
  float s = scale(sample,0,2.1,0,vectorSize);
  cout << "PickSample::calculateM - s =" << s <<"\n ";
  cout << "PickSample::calculateM - v.size() =" << vectorSize <<"\n ";
  int intS = (int) s;
  cout << "PickSample::calculateM - intS =" << intS <<"\n ";
  float y = interpolate(s,intS,intS+1,v[intS],v[intS+1]);
  cout << "PickSample::calculateM - y =" << y <<"\n \n";
  return y;
}

float PickSample::scale(float sample, float x1From, float x2From, float x1To, float x2To)
{
  // cout << "PickSample::scale - sample =" << sample << fixed <<"\n ";
  float xFromDistance = x2From - x1From;
  // cout << "PickSample::scale - xFromDistance =" << xFromDistance << fixed <<"\n ";
  float sampleScaled = sample/xFromDistance;
  // cout << "PickSample::scale - sampleScaled =" << sampleScaled << fixed <<"\n ";
  float xToDistance = x2To - x1To;
  // cout << "PickSample::scale - xToDistance =" << xToDistance << fixed <<"\n ";
  float x = (sampleScaled * xToDistance) + x1To;
  // cout << "PickSample::scale - x =" << x << fixed <<"\n \n";
  return x;
}

float PickSample::interpolate(float sample, float x1, float x2, float y1, float y2)
{
  float y = y1 + (y2-y1) * ((sample-x1) / (x2-x1));
  return y;
}

void PickSample::fillBuffer()
{
  audioFile.load ("../eigenEffect/samples/SNARE.wav");
  //load wav
  audioFile.printSummary();
  //print info about the wav
  numSamples = audioFile.getNumSamplesPerChannel();
  //store how many samples the wav has in numSamples
  numSamples -= 1;
  cout << "PickSample::Constructor - numSamples = " << numSamples <<endl;

  //numSamples -= 1 else the buffer exeeds how many samples the wav has
  int channel = 0;
  audioFile.setBitDepth(24);
  // cout << "PickSample::fillBuffer - numSamples = " << numSamples <<endl;
  int cs = 0;
  for(int i = 0; i < numSamples; i++)
  //fill vector with samples from wav
  {
    float currentSample = audioFile.samples[channel][i];
    //stores the current sample from the wav in currentSample
    if(currentSample > 0.009 || currentSample < -0.009) {v.push_back(currentSample);}
    //removes the x..9 numbers before storing the samples in the vector, since a having a lot of x.00 numbers make for a very boring waveshaper
    // if(currentSample > 0.009 || currentSample < -0.009) {cout << "PickSample::fillBuffer - currentSample =" << currentSample <<"\n ";}
    // cout << "PickSample::fillBuffer - currentSample =" << currentSample <<"\n ";
    // wtf->write(std::to_string(currentSample) + "\n");
  }

  sort(v.begin(), v.end());
  //sorts the vector from low to high
  float front = v.front();
  //stores the current first value of the vector which is the lowest
  float back = v.back();
  // for(int i < )
  //stores the current last value of the vector which is the highest
  cout << "PickSample::fillBuffer - *v.rbegin() & *v.rend() = " << *v.rbegin() << " & " << *v.rend()<< fixed <<"\n ";
  cout << "PickSample::fillBuffer - *v.begin() & *v.end() = " << *v.begin() << " & " << *v.end()<< fixed <<"\n ";
  cout << "PickSample::fillBuffer - v.back() & v.front() = " << v.back() << " & " << v.front() << fixed <<"\n ";
  cout << "PickSample::fillBuffer - *v.cbegin() & *v.cend() = " << *v.cbegin() << " & " << *v.cend()<< fixed <<"\n ";
  vectorSize = v.size();
  cout << "PickSample::fillBuffer - vectorSize = " << vectorSize << endl;
  delete buffer;
  buffer = nullptr;
  buffer = new float[vectorSize];
  for(int i = 0; i< vectorSize; i++)
  {
    buffer[i] = v[i];
    wtf->write(std::to_string(buffer[i]) + "\n");
  }
  // for (auto j = v.begin(); j != v.end(); ++j)
  //walks through the vector from begin to end, so i can remove the first element and add a new one to the end of the vector
  //for (auto j = v.rbegin(); j != v.rend(); ++j)
  //the problem right now might be that j sends the first element of the vector to be scaled, but it should send the last since the first element gets deleted
  // {

    // v.erase(v.begin());
    //erases the first element of the vector because
    // float begin = *v.begin();
    // cout << "PickSample::fillBuffer - *v.rbegin() & *v.rend() = " << *v.rbegin() << " & " << *v.rend() <<"\n ";
    // float end = *v.end();
    // cout << "PickSample::fillBuffer - front & back =" << front << " & " << back <<"\n ";
    // cout << "PickSample::fillBuffer - begin =" << begin <<"\n ";
    // cout << "PickSample::fillBuffer - j =" << j <<"\n ";
    // cout << "PickSample::fillBuffer - back = " << back <<"\n";
    // cout << "PickSample::fillBuffer - v.i* =" << *i <<"\n \n ";
    // cout << "PickSample::fillBuffer - v.j* =" << *j <<"\n \n ";
    // v.push_back(scale(*j, front, back, -1, 1));
    // float s = scale(*j, front, back, 0, 2.1);
    //scales the current element from the sample [highest,lowest] to [1,-1], for better waveshaping. does not work yet
    // cout << "PickSample::fillBuffer - s =" << s <<"\n \n ";
    // v.push_back(s);
    //stores the newly scaled sample in the back of the vector
    // cout << "PickSample::fillBuffer - v.j* =" << *j <<"\n \n ";
    // wtf->write(std::to_string(*j) + "\n");
  // }
  // vectorSize = v.size();
  // cout << "PickSample::fillBuffer - vectorSize = " << vectorSize << endl;
  //maybe make a buffer to fill instead of a vector in the for loop above and scale the size so it fits a buffer of bv 512
  //list
  //set
  // for(int j = 0; )

}

float PickSample::calculateL(float sample)
{
  return 0;
}

float PickSample::calculateR(float sample)
{
  return 0;
}
