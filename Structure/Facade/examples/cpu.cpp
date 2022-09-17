#include "cpu.h"
#include <iostream>

void CPU::freeze() {
  std::cout << "call freeze function\n";
}

void CPU::jump(long position) {
  std::cout << "call jump function\n";
}

void CPU::execute() {
  std::cout << "call execute function\n";
}
