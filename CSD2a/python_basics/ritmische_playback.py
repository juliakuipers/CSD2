import simpleaudio as sa 
import asyncio

Kick = "Kick.wav"
wave_obj = sa.WaveObject.from_wave_file(Kick)

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?"))
# %d roept de integer van numPlaybackTimes als ik dat specificeer aan het einde van de regel met % 
print("noem %d duraties van elke kick"% numPlaybackTimes)
dur = []
    
for i in range(numPlaybackTimes): 
    durar = float(input(""))
    dur.append(durar)



bpm = int(input("wat is het BPM?"))
#sec = dur * bpm
#wait = sec/bpm 
#print(wait)

async def duration():
    for i in range(numPlaybackTimes):
        await asyncio.sleep(dur)
# while loop met def dan de for loop +1 totdat de while loop niet meer geld 



for i in range(numPlaybackTimes):  
    play_obj = wave_obj.play()
    play_obj.wait_done()
    asyncio.run(duration())

    #i+ 1
 

