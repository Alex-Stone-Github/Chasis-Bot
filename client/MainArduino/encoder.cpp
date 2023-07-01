#include "encoder.h"

Encoder::Encoder(int clkpin, int dtpin): clkpin(clkpin), dtpin(dtpin) {
  pinMode(clkpin, INPUT);
  pinMode(dtpin, INPUT);
}
void Encoder::service() {
    bool clk = digitalRead(clkpin)==HIGH;
    bool dt = digitalRead(dtpin)==HIGH;
    // test for a change
    if (clk != last_clk) {
        // Si
        if (clk != dt) {
            cnt ++;
        }
        // no
        if (clk == dt) {
            cnt --;
        }
    }
    last_clk = clk; // this line right here almost killed me
}
void Encoder::set_ticks_per_unit(double ratio) {
    ticks_per_unit = ratio;
}
double Encoder::read() {
    return (double)cnt / ticks_per_unit;
}
