import time 
import simpleaudio as sa 
from random import random, randrange
import requests, json
import math 

api_key = "022a5abf0f1cbd43ab0366d03b13e346" #sleutel 
base_url = "http://api.openweathermap.org/data/2.5/weather?" 
city_name = input("Enter city name : ")
complete_url = base_url + "appid=" + api_key + "&q=" + city_name + "&units=metric" #link voor info over weer

response = requests.get(complete_url)#krijgt weer door 
x = response.json() #stopt de info in x 
if x["cod"] != "404": #als cod in x niet gelijk is aan 404 (404 is een foutmelding dus een foutmelding)
 
    y = x["main"] #dit specificeerd verdere info die je uit x wil halen 
 
    temp_min = y["temp_min"] #tempratuur 
 
    temp_max = y["temp_max"] #pressure 

    temp_cur = round(y["temp"]) 

    temp_feel = y["feels_like"]

    z = x["sys"] 

    sunrise = z["sunrise"]

    sunset = z["sunset"]

    a = x["wind"] 

    wind_speed = a["speed"]

else:
    print("city not found")

daylight = round((((sunset - sunrise)/60)/60)+0.5)
print("sunset",sunset,"sunrise =",sunrise,"daylight =",daylight)

print("wind_speed =",wind_speed)
#hoe langer de zon heeft geschenen hoe langer de beat is 
print("temp_min cel=",temp_min,"temp_max cel=",temp_max,"temp_cur cel=",temp_cur,"temp_feel cel=",temp_feel)



def createEvent(instrument, duration,active,timestamp):
    return {
        'instrument' : instrument,
        'duration' : duration,
        'active' : active,
        'timestamp' : timestamp, 
    } #hier creer ik de evenementen 

#math.log(max_bpm,lowest_bpm)
#zo reken ik de macht uit die lowest_bpm nodig heeft om bij max_bpm te komen
m= math.log(300,60)
print("m =",m)
#m is ongeveer 1.4, om de windkracht te meten word de schaal van beaufort gebruikt
#de schaal van beaufort is van 0 t/m 12, als het windstil is en de schaal 0 aangeeft wil ik dat er alsnog een bpm wordt gegenereerd dat geen nul is
#mijn laagste bpm is 60 en 60 tot de macht van 1 = 60
#daarom doe ik 1.4 - 0.4 en deel ik 0.4 door 12 
#het resultaat is 0.033 dit kan ik nu keer de winspeed doen en dan krijg ik een macht
log_scale = 1 + (0.033*wind_speed)
#als ik dat + 1 de 1 doe die ik eerder had afgetrokken krijg ik een logaritmische schaal 
#dit doe ik dan tot de macht van 60 en dit genereerd een bpm dat bij de wind past 
bpm = round((60**log_scale)+0.5)
print("culcu =",log_scale,"bpm =",bpm)
light_scale = 36/24
bars =  round((light_scale * daylight)+0.5) 
print("bars =",bars)
if (temp_cur % 2) == 0:
    upper_timesig = randrange(2,16,2)
else:
    upper_timesig = randrange(1,16,2)
print("upper_timesig =",upper_timesig)
 #int(input("HOW MANY BEATS IN EACH BAR?\n"))
sum_temp_feel=sum(temp_feel)
print("sum_temp_feel =",sum_temp_feel)
lower_timesig = 2**4#deze kan ik wortel trekken, een berekening die 1,2,3 of 4 als resultaat heeft via temp (kan ook andere parameter gebruiken) 

time_per_beat = upper_timesig/lower_timesig #krijg ik de duratie van een noot dus bij 4/4=1 4/8=0.5

beat_in_seconds = 60 / bpm
total_beats = upper_timesig * bars
drum_loop_dur = beat_in_seconds * total_beats
single_note_dur = (drum_loop_dur / lower_timesig) / upper_timesig

print("drum_loop_dur=",drum_loop_dur)
print("single_note_dur=",single_note_dur)

def step_ativated():
    for i in range(total_beats): 
        r = randrange(0,100)
        chance = 50 #int(input("CHANCE\n"))
        print("r=",r) 
        if chance > r:
            x = 1
        else:
            x = 0
    return x 

event_list = []
while True:     
    select_instrument = input("SELECT INSTRUMENT KICK/SNARE/HIHAT\n")
    for i in range(total_beats): 
        events = createEvent(select_instrument,single_note_dur,step_ativated(),i+1)
        event_list.append(events)
    print("event_list =", event_list) 
    #de event list reset als ik hem door laat lopen, ik moet dus een manier vinden om 2 event lists bij elkaar op te tellen of achter elkaar te zetten
    another_inst = input("DO YOU WANT TO SELECT ANOTHER INSTRUMENT Y/N\n")
    if another_inst == "Y" or another_inst == "y" or another_inst == "yes":
        pass
    else:
        break
        
#enumerate 

def counter():
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
            for event in event_list:
                if event['active'] == 1 and event['instrument'] == "kick" and event['timestamp'] == count:
                    print("kickplayed") 
                if event['active'] == 1 and event['instrument'] == "snare" and event['timestamp'] == count:
                    print("snareplayed")
                if event['active'] == 1 and event['instrument'] == "hihat" and event['timestamp'] == count:
                    print("hihatplayed")
            if count >= upper_timesig:
                #count = 0
                bar = + bar + 1
            if bar > bars:
                break
  
counter()