import time;

for i in range(10):
    wait = 1
    ticks = time.time()
    print("tick:",ticks)
    time.sleep(wait)

    ticks2 = time.time()
    print("ticks2:",ticks2)
    print("tick:",ticks)

    time.sleep(wait)
    time_dif = ticks2 - ticks
    print("time difference = :",time_dif) 
    time_count = time_dif + i 
    print("count : ", time_count)