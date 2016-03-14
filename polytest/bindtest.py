import display as d
import time

#Harcoded layers
layer=((1,[800.0,200.0,200.0,800.0],[800.0,800.0,200.0,200.0]),
        (0,[400.0,400.0,600.0,600.0],[400.0,600.0,600.0,400.0]))
        
layer2=((1,[800.0,200.0,200.0,800.0],[600.0,600.0,200.0,200.0]))

#init the display and show the layer for 2 seconds.
d.init()
for i in range(0,3):
    d.blank()
    time.sleep(1)
    d.expose(layer)
    time.sleep(2)
    d.blank()
    time.sleep(1)
d.finish()
