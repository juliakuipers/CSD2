import simpleaudio as sa 
import time 

playkick = sa.WaveObject.from_wave_file("Kick.wav")
playsnare = sa.WaveObject.from_wave_file("Snare.wav")

per_snare = int(input("NUMER OF SNARES\n"))
snare_durations = []
snare_sum = []
for i in range(per_snare):
    s = int(input("INPUT TIMESTAMPS SNARE\n")) # input grid 
    ssum = sum(snare_durations) # sum snare grid 
    snare_durations.append(s) # list duration snare 
    snare_sum.append(ssum) #list duration + duration snare 

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

count = []
def counter():
    tijd = time.time()
    interval = 1
    if tijd + interval == time.time():
        counter +1 
        tijd = time.time()



def equal_to(gelijk):
    while True:
        if (gelijk['instrument'] == "snare") and (gelijk['timestamp'] <= counter()): #hier gaat het fout 
            print("het is gelijk")
            playsnare.play()
            #play.wait_done()

#equal_to(snare_event)
#scheme 
#git init zorgt dat je nieuwe folder op git kan beheren 
#git diff; veranderingen inzien 
#alias 