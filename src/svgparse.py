#This file is test file for www.github.com/bqlabs/DeLePeHost
#Jaime Garcia Villena - elgambitero@gmail.com
#This file parses an svg file from Slic3r
#And gives it to the display module to test if it performs well.




import xml.etree.ElementTree as ET
import display as d
import time

tree = ET.parse('/home/pi/Documents/RasPyOpenVG/tests/sapphotest.svg')
root = tree.getroot()
model=()

for layer in root:
    laytuple=()

    for contour in layer:
        contuple=()
#        print(contour.attrib['{http://slic3r.org/namespaces/slic3r}type'])
        if contour.attrib['{http://slic3r.org/namespaces/slic3r}type'] == 'contour':
            contuple=contuple+(1,)
        elif contour.attrib['{http://slic3r.org/namespaces/slic3r}type'] == 'hole':
            contuple=contuple+(0,)
        coordinates=contour.attrib['points'].split()

        Xlist=[]
        Ylist=[]

        for coordinate in coordinates:
            Xlist.append(float(coordinate.split(',')[0]))
            Ylist.append(float(coordinate.split(',')[1]))
	
	#HARDCODE a resize for 40 micron pixels
        XlistCorr=[640+25*x for x in Xlist]
	YlistCorr=[400+25*x for x in Ylist]

        contuple = contuple + (XlistCorr,)
        contuple = contuple + (YlistCorr,)
        print(len(Xlist))
        laytuple = laytuple + (contuple,)
    model = model + (laytuple,)

d.init()

for layer in model:
    print(len(layer[0]))
    d.expose(layer)

d.finish()
