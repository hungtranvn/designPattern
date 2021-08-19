#ifndef CREATOR_H
#define CREATOR_H
#include "Point.h"
class Creator {
  Point* m_pPoint;
public:
  void operation();
  virtual Point* create() {return nullptr;};
};
#endif
