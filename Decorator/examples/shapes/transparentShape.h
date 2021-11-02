#ifndef _TRANSPARENT_SHAPE_H_
#define _TRANSPARENT_SHAPE_H_

#include "shape.h"

class TransparentShape : public Shape {
  Shape& shape;
  uint8_t transparency;
public:
  TransparentShape(Shape& shape, const uint8_t transparency);
  std::string str() const override;
};
#endif // _TRANSPARENT_SHAPE_H_
