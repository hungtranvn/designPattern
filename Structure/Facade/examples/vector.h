#ifndef _VECTOR_H_
#define _VECTOR_H_
#include "line.h"
struct Vector {
  virtual std::vector<Line>::iterator begin() = 0;
  virtual std::vector<Line>::iterator end() = 0;
};
#endif // _VECTOR_H_
