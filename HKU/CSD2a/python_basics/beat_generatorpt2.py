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
        city_name = input("Enter city name : ")
        complete_url = base_url + "appid=" + api_key + "&q=" + city_name + "&units=metric" #link voor info over weer

        response = requests.get(complete_url)#krijgt weer door 
        x = response.json() #stopt de info in x 

        if x["cod"] != "404": #als cod in x niet gelijk is aan 404 (404 is een foutmelding)
 
            y = x["main"] #dit specificeerd verdere info die je uit x wil halen 
            temp_min = y["temp_min"] #tempratuur 
            temp_max = y["temp_max"] #pressure 
            temp_cur = round(y["temp"]) 
            temp_feel = round(y["feels_like"])

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


def bpm():
    #math.log(max_bpm,lowest_bpm)
    #zo reken ik de macht uit die lowest_bpm nodig heeft om bij max_bpm te komen
    m= math.log(300,60)
    print("m =",m)
    #m is ongeveer 1.4, om de windkracht te meten word de schaal van beaufort gebruikt
    #de schaal van beaufort is van 0 t/m 12, als het windstil is en de schaal 0 aangeeft wil ik dat er alsnog een bpm wordt gegenereerd dat geen nul is
    #mijn laagste bpm is 60 en 60 tot de macht van 1 = 60
    #daarom doe ik 1.4 - 0.4 en deel ik 0.4 door 12 
    #het resultaat is 0.033 dit kan ik nu keer de winspeed doen en dan krijg ik een macht
    bpm_scale = 1 + (0.033*wind_speed)
    #als ik dat + 1 de 1 doe die ik eerder had afgetrokken krijg ik een logaritmische schaal 
    #dit doe ik dan tot de macht van 60 en dit genereerd een bpm dat bij de wind past 
    bpm = round((60**bpm_scale)+0.5)
    return bpm

#light_scale = 36/24
#bars =  round((light_scale * daylight)+0.5) 
##round checken 
#
#if (temp_cur % 2) == 0:
#    upper_timesig = randrange(2,16,2)
#else:
#    upper_timesig = randrange(1,16,2)
#    upper_timesig = randrange(1,16,2)

bars = 8
#print("bars =",bars)
upper_timesig = 4
#print("upper_timesig =",upper_timesig)
 #int(input("HOW MANY BEATS IN EACH BAR?\n"))
lower_timesig = 4#2**randrange(1,4)#deze kan ik wortel trekken, een berekening die 1,2,3 of 4 als wortel heeft via temp (kan ook andere parameter gebruiken) 

#print("lower_timesig =",lower_timesig)

time_per_beat = upper_timesig/lower_timesig #krijg ik de duratie van een noot dus bij 4/4=1 4/8=0.5
total_beats = upper_timesig * bars
#print("total_beats =",total_beats)

# cur_ts = 0.0
# beat_in_seconds = 60 / 120
# def get_next_timestamp(cur_ts):
    
#         #print("beat_in_seconds =",beat_in_seconds)
#     print("cur_ts",cur_ts)        
#     return cur_ts + beat_in_seconds
      
#         #print("timestamp =",timestamp)
#         #drum_loop_dur = beat_in_seconds * total_beats
#         #single_note_dur = (drum_loop_dur / lower_timesig) / upper_timesig
#         #print("drum_loop_dur=",drum_loop_dur)
#         #print("single_note_dur=",single_note_dur)
#         #gebasseerd op de temratuur instrumenten, dus hoe hoger hoe meer hoge elementen en minder laag hoe lager hoe meer lage elementen en minder hoog

def step_ativated():
    for i in range(total_beats):
        r = randrange(0,100)
        chance = 50 
        #int(input("CHANCE\n"))
        #print("r=",r) 
        if chance > r:
            x = 1
        else:
            x = 0
    return x 

event_list = []
select_instrument = ["kick","hihat","snare"]
for inst in range(len(select_instrument)):
    i = 0   
    cur_ts = 0.0
    beat_in_seconds = 60 / 120
    for i in range(bars):
        events = createEvent(select_instrument[inst],step_ativated(),cur_ts)
        event_list.append(events)
        cur_ts = cur_ts + beat_in_seconds

 
print("event_list = ",event_list)
    #de event_list list reset als ik hem door laat lopen, ik moet dus een manier vinden om 2 event_list lists bij elkaar op te tellen of achter elkaar te zetten     
#enumerate 
point_in_time = time.time()
def counter():
    while True:
        count = time.time() - point_in_time
        bar = 0 
        print("count =",count) 
        if count >=event_list['timestampp']:  #idk of deze het doet       
            if event_list['active'] == 1 and event_list['instrument'] == "kick" and event_list['timestamp'] >= count:
                print("kickplayed")
                playkick.play() 
            if event_list['active'] == 1 and event_list['instrument'] == "snare" and event_list['timestamp'] >= count:
                print("snareplayed")
                playsnare.play()
            if event_list['active'] == 1 and event_list['instrument'] == "hihat" and event_list['timestamp'] >= count:
                print("hihatplayed")
                playhihat.play()
        if count >= upper_timesig:
            #de count weer resetten dan kan ik een duidelijk begin van de maat aangeven 
            count = 0
            bar = + bar + 1
        if bar > bars:
            break
  
counter()