//sin(t) -> period 2pi 
//sin(t*2pie) -> period 1 
//t = pi 
//sin (tt*2pi / 44100) -> period 44100
//zo beslaat de periode 44100 samples 
//sin (t*2pi / 44100*2/44100)
//sin = (freq*t*2pi/44100)
//phase += delta phase 
//phase wordt verdeelt in 44100 stapjes 
//phase = freq/44100 -> phase > 1 wrap 
//sample = sin((t/samplerate)*2*pi)
//t is het verloop van de sample dus 1 t/m 44100 
//dus sample = sin(phase*2*pi)

//in code WriteToFile
//om jack2 te laten runnen jackd -d coreaudio in terminal naast het programma wat ik wil runnen 