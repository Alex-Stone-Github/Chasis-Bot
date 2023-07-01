#pragma once

#include <Arduino.h>
#include <Adafruit_MPU6050.h>

class MPUWrapper {
public:
    MPUWrapper(double dt_in_millis);
    void begin();
    void calibrate(); // takes 1 second
    double get_x_orientation();
    double get_y_orientation();
    double get_z_orientation();
    void service();
private:
    Adafruit_MPU6050 mpu;
    double service_calls_per_second;
    double gyx, gyy, gyz;
    double calx, caly, calz;
};
