import simpleaudio as sa
import time 

playback = int(input("how many times do you want to play the kick\n"))
print("pick duration per kick")

dur = []
for i in range(playback):
    duration = float(input(""))
    dur.append(duration)

print("duration=",dur)

bpm = float(input("BPM?\n"))

beatspermin = 60/bpm

print("BPM=",beatspermin)

grid = []

for i in range(playback):
    sixteenth = beatspermin * grid[i] 
    grid.append(sixteenth)

print("grid=",grid)
