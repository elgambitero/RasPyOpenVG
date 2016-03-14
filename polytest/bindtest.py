import display as d
import time

#Harcoded layers
layer=(2,((4,1,[400.0,360.0,360.0,400.0],[400.0,400.0,360.0,360.0]),(4,0,[370.0,370.0,390.0,390.0],[370.0,390.0,390.0,370.0])))
layer2=(1,((4,1,[800.0,200.0,200.0,800.0],[600.0,600.0,200.0,200.0])))

#init the display and show the layer for 2 seconds.
d.init()
d.blank()
time.sleep(1)
d.expose(layer)
time.sleep(2)
d.blank()
time.sleep(1)
d.finish()
