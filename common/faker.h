#pragma once

#include <iostream>

enum s {
    HIGH,
    LOW,
    INPUT,
    OUTPUT,
};
void digitalWrite(int pin,s state) {
    std::cout << "setting " << pin << " to " << (state==HIGH) << std::endl;
}
void pinMode(int pin, s state) {
    std::cout << "Mode of " pin << " is " << (state==OUTPUT)? "OUTPUT": "INPUT" << std::endl;
}
void analogWrite(int pin , int pwr) {
    std::cout << "setting " << pin << " to " << pwr << std::endl;
}
s digitalRead(int pin) {
    return LOW;
}
