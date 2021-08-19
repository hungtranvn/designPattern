#include "PolarCreator.h"
#include "PointPolar.h"
Point* PolarCreator::create() {
  return new PointPolar{};
}
