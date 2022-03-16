import simpleaudio as sa 
import time as tm

#Kick = "Kick.wav"
kick = sa.WaveObject.from_wave_file("Kick.wav")
snare = "Snare.wav"
playsnare = sa.WaveObject.from_wave_file(snare)

kick.play()
tm.sleep(10)
playsnare.play()
