import simpleaudio as sa 
import asyncio

Kick = "Kick.wav"
wave_obj = sa.WaveObject.from_wave_file(Kick)

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?"))
# %d roept de integer van numPlaybackTimes als ik dat specificeer aan het einde van de regel met % 
print("noem %d duraties van elke kick"% numPlaybackTimes)
dur = []
    
for i in range(numPlaybackTimes): 
    durarray = float(input(""))
    dur.append(durarray)
    #zorgt ervoor dat je het aantal numplaybacktimes in een float stopt die het in een array stopt; dur 



bpm = int(input("wat is het BPM?"))

async def duration():
#
    for i in range(numPlaybackTimes):
        for i in range(dur[i]):
            await asyncio.sleep(bpm / i)
            wave_obj.play()
            
        
# while loop met def dan de for loop +1 totdat de while loop niet meer geld 

asyncio.run(duration())

