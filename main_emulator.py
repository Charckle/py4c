import pyxinput
import serial
import time
import logging

#defaults
BAUD_RATE = 9600
SERIAL_PORT = "/dev/ttyUSB0"

logging.basicConfig(level=logging.DEBUG) #,filename='example.log')


def check_arduino_port():
    arduino = serial.Serial(SERIAL_PORT, BAUD_RATE)
    
    return arduino

def test_the_damn_thing():
    #for testing
    pyxinput.test_virtual()

def connect_virtual_controlers():
    v_controler_container = []
    while True:
        try:
            v_controler_container.append(pyxinput.vController())
            logging.debug(f'Controller {len(v_controler_container)} connected.')
        except:
            logging.debug(f'Controller FAILED connection.')
    
    return v_controler_container

def main_loop(arduino, v_controler_container):
    mainlook_going == True
    
    while mainlook_going == True:
        
    
        if datafromUser == '1':
            arduino.write(b'1')
            print("LED  turned ON")
        elif datafromUser == '0':
            arduino.write(b'0')
            print("LED turned OFF")





if __name__ == "__main__":
    
    #get arduino to read from
    arduino = check_arduino_port()
    
    #connect all the available controllers
    v_controler_container = connect_virtual_controlers()
    
    #start doing stuff
    main_loop(arduino, v_controler_container)
    
    
    
    


MyRead = pyxinput.rController(1) # For Controller 1

MyVirtual.set_value('BtnA', 1)
MyVirtual.set_value('AxisLx', -0.5)

print(MyRead.gamepad)
print(MyRead.buttons)


