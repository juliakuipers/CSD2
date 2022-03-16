from random import random, randrange 
import time
import simpleaudio as sa
import requests
import math
from midiutil import MIDIFile

wrong = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/comedy.wav")

def weather():
    while True:
        api_key = "068525cf5cc1307c8e027bfc4f19de7d" 
        #retrieve api key 
        base_url = "http://api.openweathermap.org/data/2.5/weather?" 
        city_name = input("ENTER CITY NAME\n")
        #retrieve city name 
        complete_url = base_url + "appid=" + api_key + "&q=" + city_name + "&units=metric" 
        #make link that retrieves weather to corresponding city      

        response = requests.get(complete_url)
        x = response.json() 

        if x["cod"] != "404": 

            y = x["main"] 
            temp_cur = round(y["temp"])+0.5

            z = x["sys"] 
            sunrise = z["sunrise"]
            sunset = z["sunset"]

            a = x["wind"] 
            wind_speed = a["speed"]
 
            return sunrise, sunset, wind_speed, temp_cur

        else:
            wrong.play()
            print("city not found")
            pass

weatherdef = weather()

sunrise = weatherdef[0]

sunset = weatherdef[1]

windspeed = weatherdef[2]

temp_cur = weatherdef[3]

#source: https://www.geeksforgeeks.org/python-find-current-weather-of-any-city-using-openweathermap-api/

print("temp_cur=",temp_cur)
def pick_sample():
    while True:
        yes_or_no = input("GLITCHY? (y/n)\n")
        if yes_or_no == "y":
            kick  = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/Glitch_low.wav")
            snare = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/Glitch_mid.wav")
            hihat = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/Glitch_high.wav")
            return kick, snare, hihat
        if yes_or_no == "n":
            hihat = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/Hihat.wav")
            kick  = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/Kick.wav")
            snare_or_clap = input("SNARE OR CLAP?(s/c)\n")          
            if snare_or_clap == "s":
                snare = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/Snare.wav")
                return kick, snare, hihat
            if snare_or_clap == "c":
                snare = sa.WaveObject.from_wave_file("/Users/Julia/Documents/CSD2/CSD2a/python_basics/samples/Sml_Clp3.wav")
                return kick, snare, hihat
            else:
                wrong.play()
                print("TRY AGAIN")
                pass

instrument = pick_sample()

def createEvent(instrument,timestamp,MIDInote):
    return{
        'instrument' : instrument,
        'timestamp' : timestamp,
        'MIDInote' : MIDInote
    }

#math.log(max_bpm,lowest_bpm)
wind_log = math.log(300,60)
#answer is about 1.4, so 60 to the power of 1.4 is about 300
minimum_power_value_wind = wind_log/wind_log
#answer = 1
wind_scale = wind_log - minimum_power_value_wind
#answer is 0.4
#make it so that later in the formula the answer will always be at least 60(since 60 to the power of 1 = 60)
windspeed_scale = wind_scale / 20 #since average wind speed is about 20 km/h
bpm_scale = 1 + (windspeed_scale*windspeed)
bpm = round((60**bpm_scale)+0.5)

daylight = round((((sunset - sunrise)/60)/60)+0.5)
#calculate the amout of hours it was light 
light_scale = 36/24
#maximum amout of measures devided bij maximum hours it can be light, so it can be used to scale 
bars =  round((light_scale * daylight)+0.5)
#calculate how many bars are relative to how many hours it was light 

print("windspeed =",windspeed,"bpm =",bpm)

note_duration = list()

def timestamp():
    #this is a function that's executed depending on how many instruments i wanna use, the outcome should be a different list per time it's being executed 
    ran_num = randrange(5,40) 
    ran_num_float = ran_num/10 
    #turn the random numbers into floats 
    quarter_note_duration = 60.0/bpm 
    note_duration.append(quarter_note_duration*ran_num_float)
    #calculate actual time per note 
    if len(note_duration) >= bars: #(bars)
        note_duration.clear()
    note_duration_sum = sum(note_duration)
    #sums actual time per note 

    return round(note_duration_sum,1)

events = list()
note = [60,70,80]
select_instrument = [instrument[0],instrument[1],instrument[2]]
for inst in range(len(select_instrument)):
    for i in range(bars):
        event = createEvent(select_instrument[inst],timestamp(),note[inst])
        events.append(event)

def get_timestamp(events):
    return events.get('timestamp')

events.sort(key =get_timestamp)

#source: 10_sort_lists_with_dictionaries
#sort the timestamps so that they are chronological when called later

timestamp_list = list()
instrument_list = list()
note_list = list()
mf = MIDIFile(1)
track = 0
MIDItime = 0
mf.addTrackName(track,MIDItime,"iets")
mf.addTempo(track,MIDItime,bpm) 

for event in events:
    timestamp_list.append(event['timestamp'])
    #make a list from all the timestamps so they can be popped later
    instrument_list.append(event['instrument'])
    #make a list from instruments so the right one is triggered 
    #note_list.append(event['MIDInote'])
    mf.addNote(track,0,event['MIDInote'],event['timestamp'],0.1,80)
    #add a note for every event 

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

export_midi = input("DO YOU WANT TO EXPORT MIDI FILE?(TYPE n FOR NO)\n")

if export_midi != "n":
    with open(input("NAME MIDI FILE\n") + ".midi",'wb') as outf:
        mf.writeFile(outf)