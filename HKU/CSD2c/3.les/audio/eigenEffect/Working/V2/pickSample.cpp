#include "pickSample.h"
AudioFile<float> audioFile;
#include <numeric>
#include "math.h"

PickSample::PickSample(float freq, float samplerate) //: Effect(freq,samplerate)
{
  wtf = new WriteToFile("output.csv",true);
  //make new WriteToFile
  v.clear();
  averageNumber.clear();
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
  averageNumber.clear();
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
  cout << "PickSample::scale - sample =" << sample << fixed <<"\n ";
  float xFromDistance = x2From - x1From;
  cout << "PickSample::scale - xFromDistance =" << xFromDistance << fixed <<"\n ";
  float sampleScaled = sample/xFromDistance;
  cout << "PickSample::scale - sampleScaled =" << sampleScaled << fixed <<"\n ";
  float xToDistance = x2To - x1To;
  cout << "PickSample::scale - xToDistance =" << xToDistance << fixed <<"\n ";
  float x = (sampleScaled * xToDistance) + x1To;
  cout << "PickSample::scale - x =" << x << fixed <<"\n \n";
  return x;
}

float PickSample::interpolate(float sample, float x1, float x2, float y1, float y2)
{
  float y = y1 + (y2-y1) * ((sample-x1) / (x2-x1));
  return y;
}

void PickSample::fillBuffer()
{
  audioFile.load ("../eigenEffect/samples/SUB.wav");
  // audioFile.setAudioBufferSize (1, 512);
  //load wav
  audioFile.printSummary();
  //print info about the wav
  numSamples = audioFile.getNumSamplesPerChannel();
  //store how many samples the wav has in numSamples
  numSamples -= 1;
  cout << "PickSample::Constructor - numSamples = " << numSamples <<endl;
  //numSamples -= 1 else the buffer exeeds how many samples the wav has
  audioFile.setBitDepth(24);
  int channel = 0;
  // for(int i = 0; i < numSamples; i++)
  //fill vector with samples from wav
  // {
    // float currentSample = audioFile.samples[channel][i];
    //stores the current sample from the wav in currentSample
    // if(currentSample > 0.009 || currentSample < -0.009) {v.push_back(currentSample);}
    // v.push_back(currentSample);
    //removes the x..9 numbers before storing the samples in the vector, since a having a lot of x.00 numbers make for a very boring waveshaper
    // if(currentSample > 0.009 || currentSample < -0.009) {cout << "PickSample::fillBuffer - currentSample =" << currentSample <<"\n ";}
    // cout << "PickSample::fillBuffer - currentSample =" << currentSample <<"\n ";
    // wtf->write(std::to_string(currentSample) + "\n");
  // }
  int channel = 0;
  while(true)
  {
    for(int l = 0; l < numSamples; l++)
  //   //walks through the number of samples
    {
      float currentSample = audioFile.samples[channel][l];
      if(currentSample < floatCount +0.1 && currentSample > floatCount)
      {
        // cout << "if(currentSample < floatCount+0.1 || currentSample > floatCount) " << "if(" << currentSample <<" < "<< floatCount+0.1 << " || " << currentSample << " > " << floatCount << endl;
        cout << "currentSample is within range  [floatCount, floatCount-0.1]  = [" << floatCount+0.1 << ", " << floatCount << "]" << endl;
        cout << "currentSample is at number = " << currentSample << "\n\n";
        v.push_back(currentSample);
      }
    }
    if(floatCount <= 1){sampleAverage();}
    else {break;}
  }
  sort(v.begin(), v.end());
  //sorts the vector from low to high
  float begin = v.front();
  float end = v.back();
  vectorSize = averageNumber.size();
  //size of vector
  cout << "PickSample::fillBuffer - vectorSize = " << vectorSize << endl;
  delete buffer;
  buffer = nullptr;
  buffer = new float[vectorSize];
  //delete and make a new buffer since when this function is called the buffer will be a different size
  for(int i = 0; i< vectorSize; i++)
  {
    // float s = scale(v[i],begin,end,-1,1);
    buffer[i] = averageNumber[i];
    // float s  = scale(buffer[i],begin + 1,end + 1,0, 2) -1;
    // cout << s << "\n\n\n";
    wtf->write(std::to_string(buffer[i]) + "\n");
  }
  //list
  //set
}

void PickSample::sampleAverage()
{
  float k = 1;
  float normalizeFactor = 1.0f / atan(k);
  float sum  = accumulate(v.begin(),v.end(),0.0f);
  float average = sum/v.size();
  //puts the average of every .x number sample in a new vector
  cout << "PickSample::sampleAverage - v.size(), sum, average = " << v.size() << ", " << sum << ", " << average << "\n\n";
  // averageNumber.push_back(normalizeFactor * atan(k * average));
  averageNumber.push_back(average);
  floatCount += 0.02;
  v.clear();
}


float PickSample::calculateL(float sample)
{
  return 0;
}

float PickSample::calculateR(float sample)
{
  return 0;
}
