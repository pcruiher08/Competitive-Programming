import time
from grovepi import *

boton = 4
sensor = 0
pinMode(boton,"INPUT")
setText("Pablo,Humberto,Juan")
setRGB(0,0,255)
while True:
	try:
		if digitalRead(boton):
            setRGB(0,255,0)
            setText("Temp = " + grovepi.temperatura(sensor,'1.1') + " C")
		else:		
            setRGB(255,0,0)
            setText("Presiona el boton")
	except KeyboardInterrupt:
		break
	except (IOError,TypeError) as e:
		print("Error")
