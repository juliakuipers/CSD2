from random import random, randrange 
import time
import simpleaudio as sa
import requests
import math

select_instrument = ["kick","hihat","snare"]

def createEvent(instrument,timestamp):
    return{
        'instrument' : instrument,
        'timestamp' : timestamp,
    }

dif = 40
wind = 5
temp_cur = 25 + 91
temp_log = math.log(40,5)
start_temp_log = (temp_log - 1)
print("log =",temp_log)
temp_scale = start_temp_log/146
print("temp_scale =",temp_scale)
temp_power = 1 + (temp_scale*temp_cur)
begin_randrange = round((5**temp_power)+0.5)
print("begin_randrange =",begin_randrange)
max_length = dif - begin_randrange
print("max_length=",max_length)
print("temp_log=",temp_log)
other_log = math.log(begin_randrange,5) #templog klopt niet 
print("other_log =",other_log)
start = other_log - 1
print("start =",start)
other_scale = start/12
print("other_scale =",other_scale)
other_power = 1 + (other_scale*wind)
print("other_power =",other_power)
scope_length = round((5**other_power)+0.5)
print("scope_length =",scope_length)
scope = randrange(scope_length,max_length)
print("scope =",scope)

note_duration = list()
def timestamp():
    ran_num = randrange(scope_length,begin_randrange) # from 0.5 to 4 with 0.5 max difference 
    ran_num_float = ran_num/10
    quarter_note_duration = 60.0/120 
    note_duration.append(quarter_note_duration*ran_num_float)
    if len(note_duration) >= 4: #(bars)
        note_duration.clear()
    note_duration_sum = sum(note_duration)

    return round(note_duration_sum,1)

events = list()
for inst in range(len(select_instrument)):
    if select_instrument[inst] == "kick":
        for i in range(4):#uppertimesig
            event = createEvent(select_instrument[inst],timestamp())
            events.append(event)
