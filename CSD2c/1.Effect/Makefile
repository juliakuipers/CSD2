CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE=jack_moduleStereo.o melodyGen.o writeToFile.o oscillator.o square.o Tremolo.o sine.o CircularBuffer.o ringbuffer.o Delay.o Effect.o main_stereo.o
TARGET=e

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
