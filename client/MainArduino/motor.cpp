#include "motor.h"

PWM_HBRIDGE_Motor::PWM_HBRIDGE_Motor(int hbridge1, int hbridge2, int pwm_port):
    pwm_port(pwm_port), hbridge1(hbridge1), hbridge2(hbridge2) {
        pinMode(pwm_port, OUTPUT);
        pinMode(hbridge1, OUTPUT);
        pinMode(hbridge2, OUTPUT);
    }
void PWM_HBRIDGE_Motor::set(double velocity) {
    uint8_t power = abs(velocity*255.0);
    MotorDirection d = Stop;
    if (velocity > 0.01) {
        d = Forward;
    }
    if (velocity < -0.01) {
        d = Backward;
    }
    set_power(power);
    set_direction(d);
}
void PWM_HBRIDGE_Motor::set_power(uint8_t power) {
    analogWrite(pwm_port, power);
}
void PWM_HBRIDGE_Motor::set_direction(MotorDirection dir) {
  switch(dir) {
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
    default: break;
  }
}
