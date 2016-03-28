import display as d
import time
import math

def generate(size):
    Xlist=[640+200*math.cos(2*math.pi*x/size) for x in range(size)]
    Ylist=[400+200*math.sin(2*math.pi*x/size) for x in range(size)]
    layertuple=((1,Xlist,Ylist),)
    return layertuple

d.init()
for i in range(0,10):
    d.expose(generate(i))
    time.sleep(0.5)
    d.blank()
    time.sleep(0.5)
