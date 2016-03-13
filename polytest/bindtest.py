import display as d

#One simple harcoded layer
layer=(2,((4,1,[40,0,0,40],[40,40,0,0]),(4,0,[10,10,30,30],[10,30,30,10])))

#init the display and show the layer for 2 seconds.
d.init()
d.blank()
sleep(1)
d.expose(layer)
sleep(2)
d.blank()
sleep(1)
d.finish()
