import simpleaudio as sa 
# as in als: sa om te verwijzen na simpleaudio als sa 
import asyncio as ac
import time as tm 

numPlaybackTimes = int(input("hoe vaak wil je de kick afspelen?\n"))
# %d roept de integer van numPlaybackTimes als ik dat specificeer aan het einde van de regel met % 
print("noem %d duraties van elke kick"% numPlaybackTimes)
#kan ook met list() 

dur = []    
for i in range(numPlaybackTimes): 
    duration_array = float(input(""))
    dur.append(duration_array)
    #zorgt ervoor dat je het aantal numplaybacktimes in een float stopt die het in een array stopt; dur 

bpm = int(input("wat is het BPM?\n"))

notedur = []
for i in range(numPlaybackTimes):
    notedur.append((dur[i]* 60) / bpm)
    print("dur=",dur[i])

print("notedur:",notedur)
#for i in range (numPlaybackTimes):

counter = []
currentcount = 0.0
#counter = tm.time() - tm.time()
for i in range(numPlaybackTimes):
    print(currentcount)
    currentcount += 1
    print("currrentcount=",currentcount)
    print("counter=",counter)
    #tm.sleep(notedur[i])
    print("currentcount=",currentcount,"notedur[i]=",notedur[i])
    currentcount =+ notedur[i]
    #print("cur=",cur)

  
async def duration():
    i = 0   
    for i in range(numPlaybackTimes):
    #de for loop runt het aantal keren numPlaybackTimes 
        #geen for loop gebruiken, de loop moet de hele tijd afwachtend zijn op wanneer de volgende noot gespeeld moet worden
        Kick = "Kick.wav"
        wave_obj = sa.WaveObject.from_wave_file(Kick)
        wave_obj.play()
        await ac.sleep(notedur[i])

        #deze moet dus in een grid van 16e passen 
        

#als iets gelijk is aan de counter speel dan af, dit kan met tijd die telt vanaf 0 en een array die de timestamps heeftr 
ac.run(duration())
#roept de def aan met de sequencer x

#FIXME
#TODO 
#list toepassingen 
#time.sleep(dur)
#sample.play() = 