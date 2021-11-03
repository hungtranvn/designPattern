#include "square.h"

Square::Square() : a{0} {
}

Square::Square(int a) : a{a} {
}

int Square::getEdge() const {
  return a;
}

int Square::area() const{
  return a*a;
}
