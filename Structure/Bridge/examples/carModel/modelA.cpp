#include "modelA.h"

ModelA::ModelA(IColor* color) : _color(color) {
}

std::string ModelA::model() {
  return "This is model A " + _color->color();
}
