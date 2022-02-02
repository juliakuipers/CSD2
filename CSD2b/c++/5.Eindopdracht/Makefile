CXX= g++
CXXFLAGS = -I/usr/local/include -Wall -std=c++1z
#LDFLAGS= -ljack
SOURCE=synth.o main.o SimpleSynth.o 
TARGET=e

$(TARGET) : $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -f $(TARGET) *.o
