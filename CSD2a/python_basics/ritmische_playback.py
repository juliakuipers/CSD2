import simpleaudio as sa 
# as in als: sa om te verwijzen na simpleaudio als sa 
import asyncio as ac

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?"))
# %d roept de integer van numPlaybackTimes als ik dat specificeer aan het einde van de regel met % 
print("noem %d duraties van elke kick"% numPlaybackTimes)
#kan ook met list() 

dur = []    
for i in range(numPlaybackTimes): 
    duration_array = float(input(""))
    dur.append(duration_array)
    #zorgt ervoor dat je het aantal numplaybacktimes in een float stopt die het in een array stopt; dur 

bpm = int(input("wat is het BPM?"))

async def duration():
    i = 0
    for i in range(numPlaybackTimes):
    #de for loop runt het aantal keren numPlaybackTimes 
        Kick = "Kick.wav"
        wave_obj = sa.WaveObject.from_wave_file(Kick)
        wave_obj.play()
        await ac.sleep(dur[i])
        i +1
ac.run(duration())
#roept de def aan met de sequencer 

#FIXME
#TODO 
#list toepassingen 
#time.sleep(dur)
#sample.play() = 