import gpiozero  # We are using GPIO pins
from signal import pause
import bluetooth
import json

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
f = open('config.json')
conf = json.load(f)
print(conf)

sock.connect((conf["address"],int(conf["port"])))

def pressedHandler(number = ""):
    def onPressed():
        print(number)
        sock.send(number)
    return onPressed
 
button1 = gpiozero.Button(18) # GPIO17 connects to button 
button2 = gpiozero.Button(2)
button3 = gpiozero.Button(3)
  
button1.when_pressed = pressedHandler(number = "1")
button2.when_pressed = pressedHandler(number = "2")
button3.when_pressed = pressedHandler(number = "3")

pause()