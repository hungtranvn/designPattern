#ifndef _COMPUTER_FACADE_H_
#define _COMPUTER_FACADE_H_
#include "cpu.h"
#include "memory.h"
#include "hardDriver.h"
class ComputerFacade {
public:
 ComputerFacade();
 ~ComputerFacade();
 void start();
private:
  CPU* _cpu;
  Memory* _memory;
  HardDriver* _hd;
};
#endif // _COMPUTER_FACADE_H_
