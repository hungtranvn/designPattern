#include "concreteAggregate.h"

ConcreteAggregate::ConcreteAggregate(int n) {
  for (int i = 0; i < n; i++) {
    obj_.emplace_back(i);
  }
}

int ConcreteAggregate::getItem(int i) {
  return obj_.at(i);
}

unsigned int ConcreteAggregate::getSize() {
  return obj_.size();
}

void ConcreteAggregate::addItem(int obj) {
  return obj_.emplace_back(obj);
}
