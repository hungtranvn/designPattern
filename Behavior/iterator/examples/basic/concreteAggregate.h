#ifndef _CONCRETE_AGGREGATE_H_
#define _CONCRETE_AGGREGATE_H_
#include "aggregate.h"
#include <vector>
class ConcreteAggregate : public Aggregate {
public:
  ConcreteAggregate(int n);
  ~ConcreteAggregate() = default;
  int getItem(int i);
  unsigned int getSize();
  void addItem(int obj);
private:
  std::vector<int> obj_;
};
#endif // _CONCRETE_AGGREGATE_H_
