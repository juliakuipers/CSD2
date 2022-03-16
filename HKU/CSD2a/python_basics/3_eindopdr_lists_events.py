from random import random, randrange 
import time
import simpleaudio as sa

kick = sa.WaveObject.from_wave_file("Kick.wav")
snare = sa.WaveObject.from_wave_file("Snare.wav")
hihat = sa.WaveObject.from_wave_file("Hihat.wav")

def createEvent(instrument,timestamp):
    return{
        'instrument' : instrument,
        'timestamp' : timestamp,
    }



note_duration = list()
def timestamp():
    #this is a function that's executed depending on how many instruments i wanna use, the outcome should be a different list per time it's being executed 
    ran_num = randrange(5,20) # from 0.5 to 4 with 0.5 max difference 
    ran_num_float = ran_num/10
    quarter_note_duration = 60.0/120 
    note_duration.append(quarter_note_duration*ran_num_float)
    if len(note_duration) >= 4: #(bars)
        note_duration.clear()
    note_duration_sum = sum(note_duration)

    return round(note_duration_sum,1)

events = list()
select_instrument = [kick,hihat,snare]
for inst in range(len(select_instrument)):
    for i in range(4):#uppertimesig
        event = createEvent(select_instrument[inst],timestamp())
        events.append(event)
        #print("event =",event)
#in this function i create multiple dictionary's that arent hardcoded 

def get_timestamp(events):
    return events.get('timestamp')

events.sort(key =get_timestamp)

timestamp_list = list()
instrument_list = list()
for event in events:
    timestamp_list.append(event['timestamp'])
    instrument_list.append(event['instrument'])
    #make a list from all the timestamps 
 #pick the first item from that list

start_time = time.time()
def playEvent():
    ts = timestamp_list.pop(0)
    inst = instrument_list.pop(0)
    while True:
        count = time.time() - start_time
        if count >= ts:
            inst.play()
            #work with index to play the right instrument
            ts = timestamp_list.pop(0)
            inst = instrument_list.pop(0)
            if not timestamp_list:
                break
    time.sleep(0.001)

playEvent()