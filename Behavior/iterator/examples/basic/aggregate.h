#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_
#include "iterator.h"
class Aggregate {
public:
  virtual ~Aggregate() = default;
  virtual Iterator* createIterator() = 0;
};
#endif // _AGGREGATE_H_
