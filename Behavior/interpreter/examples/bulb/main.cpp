#include "bulb.h"
#include "turnOn.h"
#include "turnOff.h"
#include "remote.h"
#include <memory>

int main() {
  std::shared_ptr<Bulb> bulb = std::make_shared<Bulb>();

  std::shared_ptr<TurnOn> turnOn = std::make_shared<TurnOn>(bulb);
  std::shared_ptr<TurnOff> turnOff = std::make_shared<TurnOff>(bulb);

  Remote remote;
  remote.submit(turnOn);
  remote.submit(turnOff);

  return 0;
}
