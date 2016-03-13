import display as d
import time

#One simple harcoded layer
layer=(2,((4,1,[400.0,360.0,360.0,400.0],[400.0,400.0,360.0,360.0]),(4,0,[370.0,370.0,390.0,390.0],[370.0,390.0,390.0,370.0])))

#init the display and show the layer for 2 seconds.
d.init()
d.blank()
time.sleep(1)
d.expose(layer)
time.sleep(2)
d.blank()
time.sleep(1)
d.finish()
