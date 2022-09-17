#include "coloredShape.h"
#include <sstream>

ColoredShape::ColoredShape(Shape& shape, const std::string& color) : \
  shape{shape}, color{color}{
}

std::string ColoredShape::str() const {
  std::ostringstream oss;
  oss << shape.str() << " has the color " << color << "\n";
  return oss.str();
}
