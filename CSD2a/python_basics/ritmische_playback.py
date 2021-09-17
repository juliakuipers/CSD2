import simpleaudio as sa 
import asyncio

Kick = "Kick.wav"
wave_obj = sa.WaveObject.from_wave_file(Kick)

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?"))
# %d roept de integer van numPlaybackTimes als ik dat specificeer aan het einde van de regel met % 

dur = []
print("noem %d duraties van elke kick"% numPlaybackTimes)
   
i=0 
#for i in range(numPlaybackTimes): 
 #   durar = float(input(""))
#    dur.append(durar)

async def duration():
    for i in range(numPlaybackTimes): 
        durar = float(input(""))
        dur.append(durar)
    await asyncio.sleep(durar)
    #plaatsing van deze code moet hoger?

# while loop met def dan de for loop +1 totdat de while loop niet meer geld 

bpm = int(input("wat is het BPM?"))
wait = 60/bpm 

a = 1 
for a in range(numPlaybackTimes):  
    play_obj = wave_obj.play()
    play_obj.wait_done()
    asyncio.run(duration()) 
    #i+ 1
 

