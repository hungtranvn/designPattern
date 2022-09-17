#include "computerFacade.h"

ComputerFacade::ComputerFacade() {
  _cpu = new CPU();
  _hd = new HardDriver();
  _memory = new Memory();
}

ComputerFacade::~ComputerFacade() {
  delete _cpu;
  delete _hd;
  delete _memory;
}

void ComputerFacade::start() {
  _cpu->freeze();
  _memory->load(1, "string");
  _cpu->execute();
}
