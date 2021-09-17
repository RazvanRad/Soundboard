import gpiozero  # We are using GPIO pins
from signal import pause

button_pressed="-1" 

def pressed1():
    button_pressed = 1
    print(button_pressed)
    
def pressed2():
    button_pressed = 2
    print(button_pressed)

def pressed3():
    button_pressed = 3
    print(button_pressed)
 
button1 = gpiozero.Button(18) # GPIO17 connects to button 
button2 = gpiozero.Button(2)
button3 = gpiozero.Button(3)
  
button1.when_pressed = pressed1
button2.when_pressed = pressed2
button3.when_pressed = pressed3

pause()
