#pragma once

#include <Arduino.h>
#include <stdint.h>

enum MotorDirection {
    Stop,
    Forward,
    Backward,
};
class PWM_HBRIDGE_Motor {
public:
    PWM_HBRIDGE_Motor(int hbridge1, int hebridge2, int pwm_port);
    void set(double velocity);
private:
    void set_power(uint8_t power);
    void set_direction(MotorDirection dir);
    int hbridge1, hbridge2;
    int pwm_port;
};
