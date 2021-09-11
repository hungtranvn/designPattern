#include "SharedObject.h"
#include <iostream>

void SharedObject::Reset() {
  std::cout << "Resetting the state\n";
}

void SharedObject::MethodA() {
  std::cout << "MethodA\n";
}

void SharedObject::MethodB() {
  std::cout << "MethodB\n";
}

SharedObject::~SharedObject() {
  std::cout << "SharedObject::~SharedObject()\n";
}
