import requests
import time
import json
import serial
import threading

def online():
    while True:
        time.sleep(.1)
        responce = requests.get("http://localhost:8000")
        body = responce.json()
        print(body)



def arduino():
    arduino_port = serial.Serial("/dev/ttyACM0", baudrate=9600)
    print(arduino_port.name)
    while True:
        res = arduino_port.read()
        print(res)