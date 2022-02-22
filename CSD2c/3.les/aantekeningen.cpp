/*
  TODO: make right map structure, write a chorus and waveshaper
  waveshaper
  with arctan
  the higher value k is the heavier the distortion
  buffer
  normalize in functio : tremolo and waveshaper

  01_interpolation

  make a buffer + buffersize
  make an interger variable offset with a float so: int x = 10.0f
  this is because the offset will also be floats
  make a for loop that goes with the size of the buffer
  the for loop fills the buffer with the number form offset

  make a floating point index which equals 0;
  the floating point index will be transformed to an integer index i
  and an increment float values (increment = ophogen van waarde)
  the incremented value is the point from which the linear interpolation takes place
  the incremented value has nothing to do with the increased size of the buffer
  since we interpolate between 2 values we need a value or place between step 1 and step 2

  as long as the floating point index < buffersize -1 ()
    retrieve the value behind the point from the floating point index
    make a restvalue which results in the floating point index - the floating point index as in integer
    the rest value is the .x number between two y coordinates, or two places in the buffer
    then for linear interpollation i need both the high (or future) and the low (or current) sample
    then the delta is the high minus the low, so get the amount that rests between high and low
    then the restvalue * the delta results in the vector + the low value
    this places the linear interpolated point or value somwhere between low and high

    floating point index + the incremented value
*/
