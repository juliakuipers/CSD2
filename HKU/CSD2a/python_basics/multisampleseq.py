import simpleaudio as sa 
import time 

grid = 15
playkick = sa.WaveObject.from_wave_file("Kick.wav")
playsnare = sa.WaveObject.from_wave_file("Snare.wav")

per_snare = int(input("NUMER OF SNARES\n"))
snare_durations = []
snare_sum = []
for i in range(per_snare):
    s = int(input("INPUT TIMESTAMPS SNARE\n")) # input grid 
    snare_durations.append(s) # list duration snare 
    ssum = sum(snare_durations) # sum snare grid 
    snare_sum.append(ssum) #list duration + duration snare 

#ik heb een array van 16 nodig (grid) waar een 1 voor een snare staat, dus de array die ik hier maar is niet de array die ik doorstuur 

print("snare_sum",snare_sum)
 
snare_event = {
    'timestamp': snare_sum,
    'instrument': "snare", 
    'velocity': 72,    
    'duration' : 500 #msec
}

kick_arr = []
for i in range(0):  
    k = float(input("INPUT TIMESTAMPS KICK\n"))
    kick_arr.append(k)

kick_event = {
    'timestamp': kick_arr,
    'instrument': "kick", #als ... === kick dan play kick 
    'velocity': 72,
    'duration' : 500 #msec
} # om de hele event aan te roepen kick_event 

hihat_arr = []
for i in range(0):
    h = float(input("INPUT TIMESTAMPS HIHAT\n"))
    hihat_arr.append(h)

hihat_event = {
    'timestamp': hihat_arr,
    'instrument': 'hihat',
    'velocity': 72,
    'duration': 500
}

count_array = []
print("dictionary over")

def sequence():
    count = -1
    tijd = time.time()
    interval = 1
    while True:
        if (time.time()-tijd )>= interval:
            count = count + 1 
            tijd = time.time()
            time.sleep(0.001)
            print("count=",count)
            count_array.append(count)
            #first = count_array[i]
            #first in sum
#            for i in range(grid):
            #return count  # if true return 1 dan ga overnieuw 
                #continue  
            if count >= grid:
                break       
                
        #for i in range(grid):
            #if (instrument['instrument'] == "snare") and (snare_sum[i] == count()): #hier gaat het fout 
                #print("snare")
                #play = playsnare.play()
                #play.wait_done()

waar = sequence()
print(waar)

def equal_to(gelijk): 
    while (gelijk['instrument'] == "snare") and (gelijk['timestamp'] in sequence()): #waar moet de functie worden waar ik tel 
            print("snare")
            play = playsnare.play()
            play.wait_done()

equal_to(snare_event)
#scheme 
#git init zorgt dat je nieuwe folder op git kan beheren 
#git diff; veranderingen inzien 
#alias 