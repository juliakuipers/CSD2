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

changeBPM = input("Het BPM is 120, wil je dit veranderen? (typ ja/nee)\n")

if changeBPM == "ja":
    bpm = int(input("voer het gewilde bpm in\n"))
elif changeBPM == "nee":
    bpm = 120
else: 
    "voer opnieuw in"

notedur = []
for i in range(numPlaybackTimes):
    notedur.append((dur[i]* 60) / bpm)
    #stopt de duraties die ik invul in een lijst 

print("notedur:",notedur)

timestamps16th = []
speeltijd = [] 
currentcount = 0.0
tijd = 0
difftime = tm.time()
tijd_tijd = tijd + difftime 

for i in range(numPlaybackTimes):
    print("currentcount=",currentcount)
    timestamps16th.append(currentcount/0.125)
    #deelt zodat het in 16e past 
    currentcount = currentcount + notedur[i]
    print("tijd_tijd",tijd_tijd)
    speeltijd.append(tijd_tijd+timestamps16th[i])

print("speeltijd=",speeltijd)
#while True:
    #print("t",timestamps16th)
#tijdsverschil berekenen 
#de tijd van voor de while loop meten min de tijd in de while loop 

tijd_while = tm.time()
while True:
    tijdj = tm.time() - tijd_while
    for i in range(numPlaybackTimes):
        if tm.time() - speeltijd[i] >= tijdj: 
            Kick = "Kick.wav"
            wave_obj = sa.WaveObject.from_wave_file(Kick)
            wave_obj.play()
            tm.sleep(0.001)
        else:
            break
#function gebruiken
#while True:
#    Kick = "Kick.wav"
#  wave_obj = sa.WaveObject.from_wave_file(Kick)
#   wave_obj.play()

    #de for loop runt het aantal keren numPlaybackTimes 
        #geen for loop gebruiken, de loop moet de hele tijd afwachtend zijn op wanneer de volgende noot gespeeld moet worden


        #deze moet dus in een grid van 16e passen 

 
#als iets gelijk is aan de counter speel dan af, dit kan met tijd die telt vanaf 0 en een array die de timestamps heeftr 
#roept de def aan met de sequencer x

#FIXME
#TODO 
#list toepassingen 
#time.sleep(dur)
#sample.play() = 