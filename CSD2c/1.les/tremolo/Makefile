CPP = g++
CFLAGS = -Wall
LDFLAGS=

OBJ = tremolo.o main.o

all: main

a_test: $(OBJ)
	$(CPP) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm /111 -type f`

.cpp.o:
	$(CPP) -c $(CFLAGS) $<
