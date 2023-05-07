#include "encoder.h"

Encoder::Encoder(int clkpin, int dtpin): clkpin(clkpin), dtpin(dtpin) {}
int Encoder::read() {
    return cnt;
}
void Encoder::service() {
    bool clk = digitalRead(clkpin)==HIGH;
    bool dt = digitalRead(dtpin)==HIGH;
    if (clk != last_clk) {
        // we have a change
        if (clk != dt) {
            cnt ++;
        }
        if (clk == dt) {
            cnt --;
        }
    }
}
