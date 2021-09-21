import simpleaudio as sa 
# as in als: sa om te verwijzen na simpleaudio als sa 
import asyncio as ac

Kick = "Kick.wav"
wave_obj = sa.WaveObject.from_wave_file(Kick)

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
    for i in range(numPlaybackTimes):
    #de for loop runt het aantal keren numPlaybackTimes 
        #for i in range(dur[i]):
        #andere loop 
        wave_obj.play()
        await ac.sleep(bpm / dur[i])

ac.run(duration())
#roept de def aan met de sequencer 

#FIXME
#TODO 
#list toepassingen 
#time.sleep(dur)
#sample.play() = 