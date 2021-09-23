import gpiozero  # We are using GPIO pins
from signal import pause
import bluetooth

sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
#TODO add address and port in config
sock.connect(("48:51:B7:1D:6E:2D",1))

button_pressed="-1" 

def pressed1():
    button_pressed = 1
    print(button_pressed)
    sock.send("1")
    
def pressed2():
    button_pressed = 2
    print(button_pressed)
    sock.send("2")

def pressed3():
    button_pressed = 3
    print(button_pressed)
    sock.send("3")
 
button1 = gpiozero.Button(18) # GPIO17 connects to button 
button2 = gpiozero.Button(2)
button3 = gpiozero.Button(3)
  
button1.when_pressed = pressed1
button2.when_pressed = pressed2
button3.when_pressed = pressed3

pause()
