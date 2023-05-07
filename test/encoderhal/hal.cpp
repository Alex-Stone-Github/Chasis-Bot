#include "../common/faker.h"
#include "hal.h"

Encoder::Encoder(int clkpin, int dtpin): clkpin(clkpin), dtpin(dtpin) {}
void Encoder::read() {
    return count;
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