import simpleaudio as sa 
import time 

grid = 15
playkick = sa.WaveObject.from_wave_file("Kick.wav")
playsnare = sa.WaveObject.from_wave_file("Snare.wav")
playhihat = sa.WaveObject.from_wave_file("Hihat.wav")

playhihat.play()
playsnare.play()

snare_durations = []
snare_sum = []
#for i in range(per_snare):
#    s = int(input("INPUT TIMESTAMPS SNARE\n")) # input grid 
#    snare_durations.append(s) # list duration snare 
#    ssum = sum(snare_durations) # sum snare grid 
#    snare_sum.append(ssum) #list duration + duration snare 

#ik heb een array van 16 nodig (grid) waar een 1 voor een snare staat, dus de array die ik hier maar is niet de array die ik doorstuur 


def createEvent (instrument, velo, time):
    return {
        'timestamp': time,
        'instrument': instrument,
        'velocity': velo,
        'duration': 500
    }
    
ts = []
snarenum = int(input("NUMER OF SNARES\n"))
events = [
    createEvent("snare", 72, int(input("INPUT TIMESTAMPS SNARE\n"))),
    createEvent("snare", 72, int(input("INPUT TIMESTAMPS SNARE\n"))),
    createEvent("snare", 72, int(input("INPUT TIMESTAMPS SNARE\n"))),
    createEvent("snare", 72, int(input("INPUT TIMESTAMPS SNARE\n"))),
    createEvent("kick", 72, int(input("INPUT TIMESTAMPS KICK\n"))),
    createEvent("kick", 72, int(input("INPUT TIMESTAMPS KICK\n"))),
    createEvent("kick", 72, int(input("INPUT TIMESTAMPS KICK\n"))),
    createEvent("kick", 72, int(input("INPUT TIMESTAMPS KICK\n"))),
    createEvent("hihat", 72, int(input("INPUT TIMESTAMPS HIHAT\n"))),
    createEvent("hihat", 72, int(input("INPUT TIMESTAMPS HIHAT\n"))),
    createEvent("hihat", 72, int(input("INPUT TIMESTAMPS HIHAT\n"))),
    createEvent("hihat", 72, int(input("INPUT TIMESTAMPS HIHAT\n"))),
    createEvent("hihat", 72, int(input("INPUT TIMESTAMPS HIHAT\n"))),
]

print("events=",events)

def counter():
    count = -1
    tijd = time.time()
    interval = 1
    while True:
        if (time.time()-tijd )>= interval:
            count = count + 1 
            tijd = time.time()
            time.sleep(0.001)
            print("timestamp=",count)
            for event in events:
                if event['timestamp'] == count and event['instrument'] == "snare":
                    print("snare")
                    playsnare.play()
                    #play.wait_done()
                if event['timestamp'] == count and event['instrument'] == "kick":
                    print("Kick")
                    playkick.play()
                    #play.wait_done()
                if event['timestamp'] == count and event['instrument'] == "hihat":
                    print("hihat")
                    playhihat.play()
                    #play.wait_done()
                #if event['timestamp'] == count and event['instrument'] == "hihat":
                
            #count_array.append(count)
            #first = count_array[i]
            #first in sum
            #for i in range(grid):
            #return count  # if true return 1 dan ga overnieuw 
                #continue  
            if count >= grid:
                break       

counter()
#scheme 
#git init zorgt dat je nieuwe folder op git kan beheren 
#git diff; veranderingen inzien 
#alias 