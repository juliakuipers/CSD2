import simpleaudio as sa 
import time 

playkick = sa.WaveObject.from_wave_file("Kick.wav")
playsnare = sa.WaveObject.from_wave_file("Snare.wav")
#dictionary; een manier om info te bewaren en structureren 
me = {
    'name': 'NAME',
    'role': 'ROLE'
}
print(me['name']) # roept gespecificeerd ding uit dictionary op 

#event; gegenereerd, moeten/vinden op bepaald moment plaatsen 
#midi; timestamp, instrument, velocity(MIDI-based 0-127), duration 

per_snare = int(input("NUMER OF SNARES"))
snare_durations = []
snare_sum = []
for i in range(per_snare):
    s = int(input("INPUT TIMESTAMPS SNARE\n")) # input grid 
    ssum = sum(snare_durations) # sum snare grid 
    snare_durations.append(s) # list duration snare 
    snare_sum.append(ssum) #list duration + duration snare 

    #print("snare_arr",snare_arr)
 #sum()
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

def event(): #defenition functie +naam 
    print("hoi")

event() #roept functie aan, haakjes zijn belangrijk 

def note_event(x): #tussen de haakjes kan je iets stoppen wat je als je de functie aanroept kan veranderen dus;
    print(x)
    #x.play

note_event(3) #omdat ik hier 3 aanroep verplaatst hij de x in de functie met 3 

def play_event(event):
    #event.play()

 #   event.play()
 #   event.wait_done()
 #   event['instrument'].play()
    print("playeventkickplayed")
    
play_event(kick_event)

count = []
def counter():
    for i in range (16):
        count_1 = time.time()
        time.sleep(1)
        count_2 = time.time()
        cur_count = count_2 - count_1
        count.append(cur_count)
        cur_count + 1
    print(cur_count)

#counter()

def equal_to(gelijk):
    while True:
        if (gelijk['instrument'] == "snare") and (gelijk['timestamp'] <= counter() ):
            print("het is gelijk")
            play = playsnare.play()
            #play.wait_done()

#equal_to(snare_event)
#equal_to(kick_event)
#play_event(Kick)
#play_event(playkick)

def played_event(event_e):
    #event.play()
    print(event_e['timestamp']) #roept specifiek ding uit de dictionary op

played_event(kick_event) #met deze methode kan ik 2 samples (bijna) tegerlijkertijd afspelemn 
played_event(snare_event)

# om hier een loop van te maken:
class sequence:
    #pass #zo slaat python de claas over 
    def __init__(self,midi,duration,velocity):
        self.first = midi
        self.last = duration
        self.velocity = velocity 
        self.attribute = midi, duration, velocity, 'dit stop ik in mij sequence'
    
    def iets(self):
        return'{} {}'.format(self.velocity)
        
seq_1 = sequence(81,0.5,72)
#print(seq_1)
print(seq_1.attribute)
#print(seq_1.iets())

class geluid:
    pass 

#scheme 
#git init zorgt dat je nieuwe folder op git kan beheren 
#git diff; veranderingen inzien 
#alias 

