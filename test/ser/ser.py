import serial

port = serial.Serial(port="/dev/ttyACM0")

while True:
    res = port.readline()
    print(res)