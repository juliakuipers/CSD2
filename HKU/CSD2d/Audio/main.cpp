#include "MIR.h"
#include "jack_module.h"
#include <thread>

MIR mir;

#define WRITE_NUM_SAMPLES 44100
bool running = true;

constexpr size_t chunksize = 256;

float samplerate = 44100; // default

float amplitude = 0.5;

JackModule jack;

static void processAudio()
{
  float inBuf[chunksize];
  float outBuf[chunksize * 2];

  memset(&inBuf, 0, sizeof(inBuf));

  do
  {
    jack.readSamples(inBuf, chunksize);
    for (unsigned int i = 0; i < chunksize; i++)
    {
      // // LEFT CHANNEL
      outBuf[2 * i] = mir.playWAV(); // effect code here

      // RIGHT CHANNEL
      outBuf[2 * i + 1] = mir.playWAV(); // effect code here

    }
    jack.writeSamples(outBuf, chunksize * 2);
  } while (running);
}

int main(int argc, char **argv)
{

  jack.setNumberOfInputChannels(1);
  jack.setNumberOfOutputChannels(2);

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  jack.autoConnect();
  samplerate = jack.getSamplerate();

  // new thread
  std::thread jackThread(processAudio);

  while (running)
  {
    switch (std::cin.get())
    {
    case 'q':
      running = false;
      break;
    }
  }
  jackThread.join();
  jack.end();
  return 0;
}
