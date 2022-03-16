from random import random, randrange 

note_duration = list()

#this is a function that's executed depending on how many instruments i wanna use, the outcome should be a different list per time it's being executed 
while True:
    r = randrange(0.5,4.0,0.5) # from 0.5 to 4 with 0.5 max difference 
    note_duration.append(r)
    #TODO make randrange work with floating numbers 
    note_duration_sum = sum(note_duration)
    if note_duration_sum >= 4: #uppertimesig
        break  
#note_duration.sort()
print("note_duration =",note_duration)

#TODO convert this to real time 
quarter_note_duration = 60.0/120 

time_duration = list()
for note_dur in note_duration:
    time_duration.append(note_dur*quarter_note_duration) 

print("time_duration =",time_duration)



