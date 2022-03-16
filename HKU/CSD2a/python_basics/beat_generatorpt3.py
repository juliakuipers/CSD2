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
 
            y = x["main"] #dit specificeerd verdere info die je uit x wil halen 
            temp_min = y["temp_min"] 
            temp_max = y["temp_max"] 
            temp_cur = round(y["temp"])+0.5 
            temp_feel = round(y["feels_like"])+0.5

            z = x["sys"] 
            sunrise = z["sunrise"]
            sunset = z["sunset"]
            time_zone = x["timezone"]

            a = x["wind"] 
            wind_speed = a["speed"]
 
            return temp_min, temp_max, temp_cur, temp_feel, sunrise, sunset, time_zone, wind_speed

        else:
            print("city not found")
            pass

weather = weatherdef()
temp_min = weather[0]
temp_max = weather[1]
temp_cur = weather[2]
temp_feel = weather[3]
sunrise = weather[4]
sunset = weather[5]
time_zone = weather[6]
wind_speed = weather[7]

daylight = round((((sunset - sunrise)/60)/60)+0.5)
#calculates how long the sun is/was shining 
print("sunset",sunset,"sunrise =",sunrise,"daylight =",daylight)
print("timezone =",time_zone)
print("wind_speed =",wind_speed)
#hoe langer de zon heeft geschenen hoe langer de beat is 
print("temp_min cel=",temp_min,"temp_max cel=",temp_max,"temp_cur cel=",temp_cur,"temp_feel cel=",temp_feel)

def createEvent(instrument,active,timestamp):
    return {
        'instrument' :instrument,
        'active' : active,
        'timestamp' : timestamp, 
    } #hier creer ik de evenementen 

def sample(instrument):
    return {
        'instrument':instrument
    }

def bpm():
    #zo reken ik de macht uit die lowest_bpm nodig heeft om bij max_bpm te komen
    #math.log(max_bpm,lowest_bpm)
    power= math.log(300,60)
    print("power =",power)
    #m is ongeveer 1.4, om de windkracht te meten word de schaal van beaufort gebruikt
    #de schaal van beaufort is van 0 t/m 12, als het windstil is en de schaal 0 aangeeft wil ik dat er alsnog een bpm wordt gegenereerd dat geen nul is
    #mijn laagste bpm is 60 en 60 tot de macht van 1 = 60
    #daarom doe ik 1.4 - 0.4 en deel ik 0.4 door 12 
    #het resultaat is 0.033 dit kan ik nu keer de winspeed doen en dan krijg ik een macht
    bpm_scale = 1 + (0.033*wind_speed)
    print("bpm_scale =",bpm_scale)
    #als ik dat + 1 de 1 doe die ik eerder had afgetrokken krijg ik een logaritmische schaal 
    #dit doe ik dan tot de macht van 60 en dit genereerd een bpm dat bij de wind past 
    bpm = round((60**bpm_scale)+0.5)
    return bpm_scale

#light_scale = 36/24
#bars =  round((light_scale * daylight)+0.5) 
##round checken 
#
#if (temp_cur % 2) == 0:
#    upper_timesig = randrange(2,16,2)
#else:
#    upper_timesig = randrange(1,16,2)
#    upper_timesig = randrange(1,16,2)


print("bpm =",bpm())
bars = 4
#print("bars =",bars)
upper_timesig = 4
 #int(input("HOW MANY BEATS IN EACH BAR?\n"))
lower_timesig = 4#2**randrange(1,4)#deze kan ik wortel trekken, een berekening die 1,2,3 of 4 als wortel heeft via temp (kan ook andere parameter gebruiken) 

#print("lower_timesig =",lower_timesig)

time_per_beat = upper_timesig/lower_timesig #krijg ik de duratie van een noot dus bij 4/4=1 4/8=0.5
total_beats = upper_timesig * bars
#print("total_beats =",total_beats)
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
        ts = timestamp()-0.5
        times.append(ts)
    return times

print("timestamparray =",timestamp_array())
timestamp_a = timestamp_array()
print("timestamp_a =",timestamp_a)

print("temp_min cel=",temp_min,"temp_max cel=",temp_max,"temp_cur cel=",temp_cur,"temp_feel cel=",temp_feel)
def step_ativated():
    for i in range(bars):
        if timestamp_a[i] == 0:
            r = randrange(0,100)
            chance = 90
        if timestamp_a[i] == bars/2:
            r = randrange(0,100)
            chance = 75 
        else:
            chance = 30  
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
    i = 0   
    for i in range(bars):
        ts = timestamp()-0.5
        events = createEvent(select_instrument[inst],step_ativated(),ts)
        event_list.append(events)


#print("event_list = ",event_list)    
#enumerate
def pop():  
    tss = timestamp_a.pop(0)
    print("timestamp_a =",timestamp_a)
    print("tss =",tss)
    return tss

for e in event_list:
    print("event =",event_list[e]['instrument'])

def counter():
    point_in_time = time.time()
    tspop = pop()
    while True:
        #print("count=",count)
        #print("bars =",bars)
        #print("tspop =",tspop)
        count = time.time() - point_in_time
        if count >= tspop and timestamp_a: 
            #print("times[i] =",times[i])     
            event_list['instrument'].play() 
            tspop = pop()              
        if count >= bars:
            break
            #print('instrument_played')
#            if count >= bars:
#                point_in_time = time.time()
  
counter()