CPP = g++
CFLAGS = -Wall
LDFLAGS=

OBJ = b.o b_test.o

all: b_test

b_test: $(OBJ)
	$(CPP) -o $@ $(CFLAGS) $(OBJ) $(LDFLAGS)

.cpp.o:
	$(CPP) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f `find . -perm /111 -type f`

