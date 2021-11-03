#include "adapter.h"

Adapter::Adapter(Square& s) : Square(s) {
}

int Adapter::width() const {
  return this->getEdge();
}

int Adapter::height() const {
  return this->getEdge();
}

int Adapter::area() const {
  return this->area();
}
