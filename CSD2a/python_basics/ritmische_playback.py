import simpleaudio as sa 
import asyncio

Kick = "Kick.wav"
wave_obj = sa.WaveObject.from_wave_file(Kick)

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?"))
print("noem de duratie van elke kick")
dur = []

while numPlaybackTimes > dur: 
    dur = int(input(""))

bpm = int(input("wat is het BPM?"))
wait = 60/bpm 

async def duration():
    await asyncio.sleep(dur)


i =1 
for i in range(numPlaybackTimes):  
    play_obj = wave_obj.play()
    play_obj.wait_done()
    asyncio.run(duration()) 
 

