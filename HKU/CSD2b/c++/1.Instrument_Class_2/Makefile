CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE=sound.o winds.o percussion.o strings.o main.o 
TARGET=instrument 

$(TARGET): $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
clean:
	rm -f $(TARGET) *.o