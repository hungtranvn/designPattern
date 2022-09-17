#include "turnOn.h"

TurnOn::TurnOn(std::shared_ptr<Bulb> bulb) : bulb_(bulb) {}

void TurnOn::execute(void) {
  bulb_->turnOn();
}

void TurnOn::undo(void) {
  bulb_->turnOff();
}

void TurnOn::redo(void) {
  execute();
}
