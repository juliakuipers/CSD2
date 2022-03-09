/*
  waveshaper
  with arctan
  the higher value k is the heavier the distortion
  buffer
  normalize in function : tremolo and waveshaper

  01_interpolation

  make a buffer + buffersize
  make an interger variable offset with a float so: int x = 10.0f
  this is because the offset will be used to calculate the interpolation, we need floating numbers for that
  make a for loop that goes with the size of the buffer
  the for loop fills the buffer with the number form offset

  make a floating point index which equals 0;
  the floating point index will be transformed to an integer index i
  and an increment float values (increment = ophogen van waarde)
  the incremented value is the point from which the linear interpolation takes place
  the incremented value has nothing to do with the increased size of the buffer
  since we interpolate between 2 values we need a value or place between step 1 and step 2

  as long as the floating point index < buffersize -1 ()
    retrieve the value behind the point from the floating point index like so:
    make a restvalue which results in the floating point index - the floating point index as in integer (1-1.3 = 0.3)
    the rest value is the .x number between two y coordinates, or the two places in the buffer
    then for linear interpollation i need both the high (or future) and the low (or current) sample buffer[i + 1], buffer[i]
    then the delta is the high minus the low, so get the amount that rests between high and low
    then the restvalue * the delta results in the vector, this + the low value
    places the linear interpolated point or value somwhere between low and high

  the buffer for the waveshaper has a reach of [-1,1]
  the sigmoid curve goes from [-1,1]
  the buffer contains the information of the sigmoid curve
  the sample indicates the x position which is always a number between 0 and 1
  the low and high are then buffer[i] and buffer[i+1]
  a buffer which stores the sigmoid curve
  the interpolation takes place at the x position between buffer[i] and buffer[i+1]
  the output is then the interpolated signal (sample) which indicates position x between buffer[i] and buffer[i+1] a buffer which contains the sigmoid

  then the low and high are the y and y + 1

    floating point index + the incremented value

    linear interpollation with a buffer

    make a buffer + buffer size
    the index of the buffer needs to be an int with the possibility of being a float
    since we use linear interpollation so the result may be a .x number




*/
