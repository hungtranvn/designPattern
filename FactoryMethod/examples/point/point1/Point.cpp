#include "Point.h"
#include <math.h>
Point::Point(double x, double y, Coordinate c) {
  if (c == Coordinate::cartesian) {
    _x = x;
    _y = y;
  } 
  else if (c == Coordinate::polar) {
    _x = x*std::cos(y);
    _y = x*std::sin(y);
  }
  else {
    _x = 0;
    _y = 0;
  }
}
