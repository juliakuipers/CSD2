import simpleaudio as sa 
import asyncio

Kick = "Kick.wav"
wave_obj = sa.WaveObject.from_wave_file(Kick)

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?"))
dur = []
print("noem %d duraties van elke kick"% numPlaybackTimes)
# %d roept de integer van numPlaybackTimes als ik dat specificeer aan het einde van de regel met % 

i=0
for i in range(numPlaybackTimes): 
    durar = float(input(""))
    dur.append(durar)
    

async def duration():
    await asyncio.sleep([dur])
    #plaatsing van deze code moet hoger?

print(dur)

bpm = int(input("wat is het BPM?"))
wait = 60/bpm 

a =1 
for a in range(numPlaybackTimes):  
    play_obj = wave_obj.play()
    play_obj.wait_done()
    asyncio.run(duration()) 
 

