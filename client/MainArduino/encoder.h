#pragma once

#include <Arduino.h>

class Encoder {
public:
    Encoder(int clkpin, int dtpin);
    int read_raw();
    void service();
    void set_ticks_per_unit(double ratio);
    double read();
private:
    int clkpin;
    int dtpin;
    int cnt = 0;
    double ticks_per_unit = 1.0;
    bool last_clk;
};
