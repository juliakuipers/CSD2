import time
from random import randrange 

def createEvent(instrument,timestamp):
    return{
        'instrument' : instrument,
        'timestamp' : timestamp,
    }

def timestamp():
    return randrange(1,5)

select_instrument = ["kick","hihat","snare"]
for inst in range(len(select_instrument)):
    for i in range(4):#uppertimesig
        event = createEvent(select_instrument[inst],timestamp())
        print("event =",event)
#in this function i create multiple dictionary's that arent hardcoded 

ts = event['timestamp'].pop(0)

start_time = time.time()
def playEvent():
    while True:
        count = time.time() - start_time
        if count >= ts:
            print("instplayed")
            ts = event['timestamp'].pop(0)


