#include "Point.h"
#include <math.h>

Point Point::MakePointCartesian(double x, double y) {
  return {x,y};
}

Point Point::MakePointPolar(double rho, double theta) {
  return {rho*cos(theta), rho*sin(theta)};
}
