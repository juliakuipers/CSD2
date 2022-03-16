import time 
import simpleaudio as sa 
from random import random, randrange

def createEvent(instrument, duration,active):
    return {
        'instrument' : instrument,
        'duration' : duration,
        'active' : active, 
    } #hier creer ik de evenementen 

bars = int(input("HOW MANY BARS?\n"))
upper_timesig = int(input("HOW MANY BEATS IN EACH BAR?\n"))
lower_timesig = float(input("VALUE PER BEAT\n"))
bpm = int(input("BPM?\n"))

beat_in_seconds = 60 / bpm
total_beats = upper_timesig * bars
drum_loop_dur = beat_in_seconds * total_beats
single_note_dur = (drum_loop_dur / lower_timesig) / upper_timesig

print("drum_loop_dur=",drum_loop_dur)
print("single_note_dur=",single_note_dur)

i = 0 

r = randrange(0,100)
chance = int(input("CHANCE\n"))
print("r=",r) 
if chance > r:
    this = True
    print("this=",this)

def select_instrument(n):
    if n == 0:
        x = input("KICK/SNARE/HIHAT?\n")
        print("0x=",x)
        print("n=",n)
    if n == 1:
        x = input("SNARE/HIHAT?\n")
        print("1x=",x)
        print("n=",n)
    if n == 2:
        x = input("KICK/HIHAT?\n")
        print("2x=",x)
        print("n=",n)
    if n == 3:
        x = input("KICK/SNARE\n")
        print("3x=",x)
        print("n=",n)
    print("x=",x)
    return x 
    #hier vraag ik om input van de gebruiker, of ze snare hihat of kick willen


while True:
    sel_instrument = select_instrument(i) # de functie roep ik hier aan   
    print("sel_instrument=",sel_instrument)

    kick_event = []

    if sel_instrument == "kick" or  sel_instrument == "Kick" or  sel_instrument == "KICK":
        print("YOU SELECTED KICK")
        for i in range(total_beats): #range wordt het aantal keren dat ik het instrument wil maken dmv random 
            events = createEvent("kick",single_note_dur,chance)
            kick_event.append(events)
        another_inst = input("DO YOU WANT TO SELECT ANOTHER INSTRUMENT Y/N\n")
        if another_inst == "Y" or another_inst == "y" or another_inst == "yes":
            i = 1
            print("i=",i)
            select_instrument(i)
        else:
            break
        
#enumerate 

    snare_event = []

    if sel_instrument == "snare" or sel_instrument == "Snare" or sel_instrument == "SNARE":
        print("YOU SELECTED SNARE")
        for i in range(total_beats):
            events = createEvent("snare",single_note_dur,chance)
            snare_event.append(events)
        another_inst = input("DO YOU WANT TO SELECT ANOTHER INSTRUMENT Y/N\n")
        if another_inst == "Y" or another_inst == "y" or another_inst == "yes":
            i = 2
            print("i=",i)
            select_instrument(i)
        else:
            break


    hihat_event = []

    if sel_instrument == "hihat" or sel_instrument == "Hihat" or sel_instrument == "HIHAT":
        print("YOU SELECTED HIHAT")
        for i in range(total_beats):
            events = createEvent("hihat",single_note_dur,chance)
            hihat_event.append(events)
        another_inst = input("DO YOU WANT TO SELECT ANOTHER INSTRUMENT Y/N\n")
        if another_inst == "Y" or another_inst == "y" or another_inst == "yes":
            i = 3
            print("i=",i)
            select_instrument(i)
        else:
            break

    #else:
        #print("TRY AGAIN")
        #select_instrument(i)
    
print(sel_instrument)

def tm():
    count = 0
    tijd = time.time()
    interval = beat_in_seconds
    count_array = []
    bar = 0
    while True:
        if (time.time()-tijd )>= interval:
            count = count + 1 
            tijd = time.time()
            time.sleep(0.001)
            print("count=",count)
            print("bar=",bar)
            count_array.append(count)
            if count >= upper_timesig:
                count = 0
                bar = + bar + 1
            if bar > bars:
                break
  
tm()
#while True:
#   ran = random.randint(0,1)
#   print("ran=",ran)
#
#   if ran > 0:
#        kick = "Kick.wav" 
#        wave_obj = sa.WaveObject.from_wave_file(kick)
#        wave_obj.play()