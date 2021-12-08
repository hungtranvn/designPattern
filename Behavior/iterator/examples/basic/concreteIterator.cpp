#include "concreteIterator.h"

ConcreteIterator::ConcreteIterator(ConcreteAggregate *ag) : \
    cag_(ag), index_(0) {
}

void ConcreteIterator::first() {
  index_ = 0;
}

void ConcreteIterator::next() {
  ++index_;
}

bool ConcreteIterator::isDone() {
  return index_ >= cag_->getSize();
}

int ConcreteIterator::currentItem() {
  return cag_->getItem(index_);
}

Iterator* ConcreteIterator::creteIterator() {
  return new ConcreteIterator(this);
}
