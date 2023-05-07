#pragma once

#include <Arduino.h>

class Encoder {
public:
    Encoder(int clkpin, int dtpin);
    int read();
    void service();
private:
    int clkpin;
    int dtpin;
    int cnt;
    bool last_clk;
    double conversion_factor;
};
