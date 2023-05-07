#include "motor.h"

PWM_HBRIDGE_Motor::PWM_HBRIDGE_Motor(int hbridge1, int hebridge2, int pwm_port, bool reversed):
    pwm_port(pwm_port), hbridge1(hbridge1), hbridge2(hbridge2), reversed(reversed) {
        pinMode(pwm_port, OUTPUT);
        pinMode(hbridge1, OUTPUT);
        pinMode(hbridge2, OUTPUT);
    }
void PWM_HBRIDGE_Motor::set(double velocity) {
    if (reversed)
        velocity *=-1;
    int power = abs(velocity*255);
    MotorDirection d;
    if (velocity > -.01 && velocity < .01) {
        d = Stop;
    }
    else if (velocity > 0) {
        d = Forward;
    }
    else if (velocity < 0) {
        d = Backward;
    }
    set_power(power);
    set_direction(d);
}
void PWM_HBRIDGE_Motor::set_power(uint8_t power) {
    analogWrite(pwm_port, power);
}
void PWM_HBRIDGE_Motor::set_direction(MotorDirection dir) {
    switch (dir) {
        case Stop:
            digitalWrite(hbridge1, LOW);
            digitalWrite(hbridge2, LOW);
            break;
        case Forward:
            digitalWrite(hbridge1, HIGH);
            digitalWrite(hbridge2, LOW);
            break;
        case Backward:
            digitalWrite(hbridge1, LOW);
            digitalWrite(hbridge2, HIGH);
            break;
        default:
            break;
    }
}
