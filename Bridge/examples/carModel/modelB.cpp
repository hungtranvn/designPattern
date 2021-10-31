#include "modelB.h"

ModelB::ModelB(IColor* color) : _color(color) {
}

std::string ModelB::model() {
  return "this is model B " + _color->color();
}
