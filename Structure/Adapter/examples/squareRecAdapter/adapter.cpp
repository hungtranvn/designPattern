#include "adapter.h"

Adapter::Adapter(Square& s) : s{s}{
}

int Adapter::width() const {
  return s.getEdge();
}

int Adapter::height() const {
  return s.getEdge();
}

int Adapter::area() const {
  return s.area();
}
