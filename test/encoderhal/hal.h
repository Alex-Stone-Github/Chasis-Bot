#pragma once

class Encoder {
public:
    Encoder(int clkpin, int dtpin);
    void read();
    void service();
private:
    int clkpin;
    int dtpin;
    int cnt;
    bool last_clk;
    double conversion_factor;
}}
