CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack
SOURCE=jack_module.o writeToFile.o oscillator.o sine.o saw.o square.o SimpleSynth.o FmSynth.o synth.o melodyGen.o main.o
TARGET=e

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
