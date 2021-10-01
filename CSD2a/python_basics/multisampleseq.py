import simpleaudio as sa 
import time 

playkick = sa.WaveObject.from_wave_file("Kick.wav")
playsnare = sa.WaveObject.from_wave_file("Snare.wav")

per_snare = int(input("NUMER OF SNARES"))
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
    timezero = 0
    for i in range (16):
        count_1 = time.time()
        time.sleep(1)
        count_2 = time.time()
        dif = count_2 - count_1
        count.append(dif)
        count_sum = timezero + dif
        print("count_1=",count_1,"count_2=",count_2)
        print("dif=",dif,"timezero=",timezero)
        print("count(list)=",count)
        print("timezero=",timezero)
        print("count_sum",count_sum)


counter()

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