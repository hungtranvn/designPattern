#ifndef _COLORED_SHAPE_H_
#define _COLORED_SHAPE_H_

#include "shape.h"

class ColoredShape : public Shape {
  Shape& shape;
  std::string color;
public:
  ColoredShape(Shape& shape, const std::string& color);
  std::string str() const override;
};
#endif // _COLORED_SHAPE_H_
