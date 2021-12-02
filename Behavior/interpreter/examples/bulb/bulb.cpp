#include "bulb.h"
#include <iostream>

void Bulb::turnOn() {
  std::cout << "Bulb has been lit." << std::endl;
}

void Bulb::turnOff() {
  std::cout << "Darkness!" << std::endl;
}
