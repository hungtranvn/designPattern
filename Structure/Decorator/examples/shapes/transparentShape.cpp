#include "transparentShape.h"
#include <sstream>

TransparentShape::TransparentShape(Shape& shape, const uint8_t transparency)
  : shape{shape}, transparency{transparency} {
}

std::string TransparentShape::str() const {
  std::ostringstream oss;
  oss << shape.str() << " has " << static_cast<float>(transparency) / \
    255.f * 100.f << "% transparency\n";
  return oss.str();
}
