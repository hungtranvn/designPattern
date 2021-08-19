#include "CartesianCreator.h"
#include "PointCartesian.h"
Point* CartesianCreator::create() {
  return new PointCartesian{};
}
