# Which subdirs do we want to scan for <makefile>.mk ?
MODULES := oscillators tremolo utilities circularBuffer

# $(patsubst pattern,replacement,text)
# Finds whitespace-separated words in text that match pattern and
# replaces them with replacement
#
#  % acts as a wildcard

CPP = g++

# look for header files in each of the modules
CFLAGS += $(patsubst %,-I%, $(MODULES))
LDFLAGS :=

# each module will add to this
# We'll start with the module in this dir which contains main()
SRC := main.cpp

# include the description for each module
#
include $(patsubst %, %/module.mk,$(MODULES))

# determine the object files
OBJ := $(patsubst %.cpp,%.o, $(filter %.cpp,$(SRC)))

# build the program
app: $(OBJ)
	$(CPP) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f app

.cpp.o:
	$(CPP) -c $(CFLAGS) $< -o $(patsubst %.cpp,%.o,$<)


