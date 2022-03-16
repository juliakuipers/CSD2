/*
  with static interpolation nnMap:
    use low -1 and high 1 (in the audio domain i have to use -1,1)
    in essence this is a squarewave, which is already used

    Linear interpolation:
      also known as a form of curve fitting, there a certain data point or samples which are already known
      these points are then used to construct other samples inbetween the know samples

      two sets of points (x0,y0) and (x1,y2) indicate two samples on a plane. The linear interpolant indicates
      the line from coordinate (x0,y0) to (x1,y1)
      the interval between x0 and x1 is x and it's like a point in time on the plane, between sample 0 and 1, we know where it is
      y is then the value that needs to be calculated
      the formula = y = y1 + (x - x1) * (y2 - y1) / (x2 - x1)
      so then y would be the sample vaule, x the sample count

      there is a difference between linear and non linear waveshaping
      linear waveshaping uses a buffer and a wavetable (sine or any other)

      so make a waveShaper with an circularBuffer which has 1 sample in the 'future' and 1 sample form the 'past', the current
      sample gets calculated as an interpolation between the two samples so:
        linMap(signal[i], wavetable[i-1], wavetable[i+1])
        (could also make a waveShaper with samples instead of waveforms)

      best is if i try it without sound: use of an array and my circularBuffer

*/
