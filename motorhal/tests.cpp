#include "hal.h"

#include <iostream>


int main() {
  std::cout << "Hello, World" << std::endl;

  PWM_HBRIDGE_Motor motor(1, 2, 3, false);
  motor.set(.2);
  motor.set(-.2);
  motor.set(.002);
  return 0;
}