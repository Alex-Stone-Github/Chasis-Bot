#include "encoder.h"
#include "motor.h"

#define MS1_EN 2
#define MS1_SIGA 3
#define MS1_SIGB 4
#define MS1_ENCA1 42
#define MS1_ENCB1 43
//#define MS1_ENCA2 
//#define MS1_ENCB2

#define MS2_EN 8
#define MS2_SIGA 9
#define MS2_SIGB 10
#define MS2_ENCA1 32
#define MS2_ENCB1 33
//#define MS2_ENCA2
//#define MS2_ENCB2


Encoder front_left_encoder(MS1_ENCA1, MS1_ENCB1);
//Encoder back_left_encoder(MS1_ENCA2, MS1_ENCB2);
PWM_HBRIDGE_Motor left_group(MS1_SIGA, MS1_SIGB, MS1_EN);
Encoder front_right_encoder(MS2_ENCA1, MS2_ENCB1);
//Encoder back_right_encoder(MS2_ENCA2, MS2_ENCB2);
PWM_HBRIDGE_Motor right_group(MS2_SIGA, MS2_SIGB, MS2_EN);

double speed = .4;

void setup() {
  Serial.begin(9600);
}
void loop() {
  if (millis() % 1000 == 0) {
    Serial.print("Left: ");
    Serial.print(front_left_encoder.read());
    Serial.print(", ");
    Serial.print("Right: ");
    Serial.print(front_right_encoder.read());
    Serial.println();
  }
  front_left_encoder.service();
  front_right_encoder.service();
}
