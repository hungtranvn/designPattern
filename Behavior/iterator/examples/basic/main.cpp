#include <iostream>
#include "iterator.h"
#include "concreteAggregate.h"
#include "concreteIterator.h"

int main() {
  ConcreteAggregate *cag = new ConcreteAggregate(10);
  cag->addItem(99);

  Iterator* it = cag->creteIterator();
  for ( ; !it->isDone(); it->next()) {
    std::cout << "Item value: " << it->currentItem() << std::endl;
  }

  return 0;
}
