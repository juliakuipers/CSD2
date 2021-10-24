import time
import wave 
import simpleaudio as sa 
from random import random, randrange
import requests, json
import math 

#list.sort 

playkick = sa.WaveObject.from_wave_file("Kick.wav")
playsnare = sa.WaveObject.from_wave_file("Snare.wav")
playhihat = sa.WaveObject.from_wave_file("Hihat.wav")

def weatherdef():
    while True:
        api_key = "068525cf5cc1307c8e027bfc4f19de7d" #sleutel 
        base_url = "http://api.openweathermap.org/data/2.5/weather?" 
        city_name = "berlin"#input("Enter city name : ")
        complete_url = base_url + "appid=" + api_key + "&q=" + city_name + "&units=metric" #link voor info over weer

        response = requests.get(complete_url)#krijgt weer door 
        x = response.json() #stopt de info in x 

        if x["cod"] != "404": #als cod in x niet gelijk is aan 404 (404 is een foutmelding)

            z = x["sys"] 
            sunrise = z["sunrise"]
            sunset = z["sunset"]

            a = x["wind"] 
            wind_speed = a["speed"]
 
            return sunrise, sunset, wind_speed

        else:
            print("city not found")
            pass

weather = weatherdef()
sunrise = weather[0]
sunset = weather[1]
wind_speed = weather[2]

daylight = round((((sunset - sunrise)/60)/60)+0.5)
#calculates how long the sun is/was shining 
print("sunset",sunset,"sunrise =",sunrise,"daylight =",daylight)
print("wind_speed =",wind_speed)
#hoe langer de zon heeft geschenen hoe langer de beat is 

def createEvent(instrument,active,timestamp):
    return {
        'instrument' :instrument,
        'active' : active,
        'timestamp' : timestamp, 
    } #hier creer ik de evenementen 

def sampleplay(event):{
    event['instrument'].play()
}

def bpm():
    #zo reken ik de macht uit die lowest_bpm nodig heeft om bij max_bpm te komen
    #math.log(max_bpm,lowest_bpm)
    power= math.log(300,60)
    print("power =",power)
    #power is ongeveer 1.4, om de windkracht te meten word de schaal van beaufort gebruikt
    #de schaal van beaufort is van 0 t/m 12, als het windstil is en de schaal 0 aangeeft wil ik dat er alsnog een bpm wordt gegenereerd dat geen nul is
    #mijn laagste bpm is 60 en 60 tot de macht van 1 = 60
    #daarom doe ik 1.4 - 0.4 en deel ik 0.4 door 12 
    #het resultaat is 0.033 dit kan ik nu keer de winspeed doen en dan krijg ik een macht
    bpm_scale = 1 + (0.033*wind_speed)
    #als ik dat + 1 de 1 doe die ik eerder had afgetrokken krijg ik een logaritmische schaal 
    #dit doe ik dan tot de macht van 60 en dit genereerd een bpm dat bij de wind past 
    bpm = round((60**bpm_scale)+0.5)
    return bpm

def bar():
    light_scale = 36/24
    bars =  round((light_scale * daylight)+0.5)
    return bars 
    #round checken 

bars = 4
current_sum = []
cur_a = [] 
beat_in_seconds = 60 / 120
def timestamp():   
    cur_ts = 0.0 + beat_in_seconds
    cur_a.append(cur_ts)
    sumc = sum(cur_a)
    current_sum.append(sumc)
    if len(cur_a) >= bars*2:
        cur_a.clear()
    return sumc

#print("current =",current)

def timestamp_array(): 
    times = []   
    for i in range(bars*2):
        ts = timestamp()
        times.append(ts)
    return times

print("timestamparray =",timestamp_array())
timestamp_a = timestamp_array()
print("timestamp_a =",timestamp_a)

power = math.log(95,5)
point_in_time = time.time()
input("what's the time right now?\n")
count = time.time() - point_in_time
powerp = 0.18*count
chance = 5**(2.8-powerp)

def step_ativated():   
        for i in range(bars):
                r = randrange(1,100)
        #int(input("CHANCE\n"))
        #print("r=",r) 
        if chance > r:
            x = 1
        else:
            x = 0
        return x 

event_list = []
select_instrument = ["playkick","playhihat","playsnare"]
for inst in range(len(select_instrument)):
    for i in range(bars):
        ts = timestamp()-0.5
        events = createEvent(select_instrument[inst],step_ativated(),ts)
        event_list.append(events)


print("event_list = ",event_list)    
#enumerate
def pop():  
    ts = timestamp_a.pop(0)
    print("timestamp_a =",timestamp_a)
    print("tss =",ts)
    return ts

def counter():
    point_in_time = time.time()
    tspop = pop()
    while True:
        count = time.time() - point_in_time
        for event in event_list:
            if count >= tspop and timestamp_a and event['active']==1 and event['instrument'] == "playhihat": 
                #print("times[i] =",times[i])     
                playhihat.play() 
                tspop = pop()              
            if count >= bars:
                break
  
counter()