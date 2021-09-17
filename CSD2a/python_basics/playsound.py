import simpleaudio as sa

filename = 'loop.wav'
wave_obj = sa.WaveObject.from_wave_file(filename)


play_obj = wave_obj.play()
playstop = input("")
ophouden = "stop"
if playstop == ophouden:
    play_obj.stop
   
    


