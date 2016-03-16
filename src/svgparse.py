#This file is test file for www.github.com/bqlabs/DeLePeHost
#Jaime García Villena - elgambitero@gmail.com
#This file parses an svg file from Slic3r
#And gives it to the display module to test if it performs well.




import xml.etree.ElementTree as ET
import display as d
import time

tree = ET.parse('dualhollows.svg')
root = tree.getroot()
model=()

for layer in root:
    laytuple=()

    for contour in layer:
        contuple=()

        if contour.attrib['{http://slic3r.org/namespaces/slic3r}type'] is 'contour':
            contuple=contuple+(1)
        elif contour.attrib['{http://slic3r.org/namespaces/slic3r}type'] is 'hole':
            contuple=contuple+(0)
        coordinates=contour.attrib['points'].split()

        Xlist=[]
        Ylist=[]

        for coordinate in cordinates:
            Xlist.append = float(coordinates.split(',')[0])
            Ylist.append = float(coordinates.split(',')[1])

        contuple = contuple + Xlist
        contuple = contuple + Ylist

        laytuple = laytuple + contuple

    model = model + laytuple

d.init()

for layer in model:
    time.sleep(0.5)
    d.expose(layer)
    time.sleep(0.5)
    d.blank()

d.finish()
