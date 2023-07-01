  #include "gy.h"

MPUWrapper::MPUWrapper(double dt_in_millis): service_calls_per_second(1000.0/dt_in_millis) {}
void MPUWrapper::begin() {
  if (!mpu.begin()) {
    Serial.println("Fail mpu fail fail fail");
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}
double MPUWrapper::get_x_orientation() {return gyx;}
double MPUWrapper::get_y_orientation() {return gyy;}
double MPUWrapper::get_z_orientation() {return gyz;}
void MPUWrapper::service() {
    sensors_event_t a, g, t;
    mpu.getEvent(&a, &g, &t);
    gyx += (g.gyro.x+calx) * 1.0/service_calls_per_second;
    gyy += (g.gyro.y+caly) * 1.0/service_calls_per_second;
    gyz += (g.gyro.z+calz) * 1.0/service_calls_per_second;
}
void MPUWrapper::calibrate() {
  double totalx = 0, totaly = 0, totalz = 0;
  double total_time = 1000.0;
  double checks = 20;
  for (int i = 0; i < checks; i ++) {
    sensors_event_t a, g, t;
    mpu.getEvent(&a, &g, &t);
    totalx += g.gyro.x;
    totaly += g.gyro.y;
    totalz += g.gyro.z;
    delay(total_time/checks);
  }
  double xavgdevia = totalx / checks;
  double yavgdevia = totaly / checks;
  double zavgdevia = totalz / checks;
  calx = -xavgdevia;
  caly = -yavgdevia;
  calz = -zavgdevia;
}
