#include "encoder.h"
#include "motor.h"

#define MOTOR_PWM 9
#define HBRIDGE_1 5
#define HBRIDGE_2 6

#define SIG_1 2
#define SIG_2 3

Encoder encoder(SIG_1, SIG_2);
PWM_HBRIDGE_Motor motor(HBRIDGE_1, HBRIDGE_2, MOTOR_PWM, false);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Hello, World");
  Serial.println(encoder.read());
}
