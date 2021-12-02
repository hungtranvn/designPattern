#include "turnOff.h"

TurnOff::TurnOff(std::shared_ptr<Bulb> bulb) : bulb_(bulb) {}

void TurnOff::execute(void) {
  bulb_->turnOff();
}

void TurnOff::undo(void) {
  bulb_->turnOn();
}

void TurnOff::redo(void) {
  execute();
}
