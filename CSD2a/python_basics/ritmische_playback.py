import simpleaudio as sa 

Kick = "Kick.wav"
wave_obj = sa.WaveObject.from_wave_file(Kick)

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?"))
dur = int(input("noem de duratie van elke kick")) 
bpm = int(input("wat is het BPM?"))

i =1  
for i in range(numPlaybackTimes):  
    play_obj = wave_obj.play()
    play_obj.wait_done()
    #wacht een bepaalde tijd van het BPM 
 

