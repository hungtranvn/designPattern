#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"

class Circle : public Shape {
  float radius;
public:
  Circle(const float radius);
  void resize(float factor);
  std::string str() const override;
};
#endif // _CIRCLE_H_
