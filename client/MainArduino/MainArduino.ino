#include <Arduino.h>

#include "encoder.h"
#include "motor.h"
#include "okl.h"
#include "gy.h"

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

OdometryLayer odometry(22.0);
KinematicsLayer kinematics(22.0);
MPUWrapper mpu(50); ///// could be the source of a bug

const double max_speed = 5; // cm / s
unsigned long counter = 0;

void setup() {
  Serial.begin(9600);
  mpu.begin();
  Serial.println("Hello, world!");
  Serial.println("Gyro Calibrating");
  mpu.calibrate();
  Serial.println("Gyro Calibrated");

  front_left_encoder.set_ticks_per_unit(23.9);
  front_right_encoder.set_ticks_per_unit(-23.9);
  odometry.update(WheelStateType{0.0, 0.0}, 0.0);
  odometry.reset(Pose{0.0, 0.0, 0.0});
}
void loop() {
  // updates and servicing
  {
    delay(50);
    front_left_encoder.service();
    front_right_encoder.service();
    mpu.service();
    // update odometry
    double current_angle = mpu.get_z_orientation(); // this could be another source of a bug
    WheelStateType wheels{
      front_left_encoder.read(), //left
      front_right_encoder.read() // right
    };
    odometry.update(wheels, current_angle);
  }

  // Whatever ------------------------------------------
  counter ++;
  if (counter % 6 == 0) {
  Pose p = odometry.get_pose();
  Serial.print("x: ");
  Serial.print(p.x);
  Serial.print(", y: ");
  Serial.print(p.y);
  Serial.print(", angledegrees: ");
  Serial.print(p.a/3.1415*180);
  Serial.print(", actual: ");
  Serial.print(mpu.get_z_orientation()/3.1415*180);
  Serial.println();
  }
}
