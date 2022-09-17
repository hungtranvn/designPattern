#ifndef _CONCRETE_ITERATOR_H_
#define _CONCRETE_ITERATOR_H_

#include "iterator.h"
#include "concreteAggregate.h"

class ConcreteIterator : public Iterator {
public:
  ConcreteIterator(ConcreteAggregate *ag);
  void first();
  void next();
  bool isDone();
  int currentItem();
  Iterator* creteIterator() override;
private:
  ConcreteAggregate *cag_;
  int index_;
};
#endif // _CONCRETE_ITERATOR_H_
