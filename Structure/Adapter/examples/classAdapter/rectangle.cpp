#include "rectangle.h"

Rectangle::Rectangle() : a{0}, b{0} {
}

Rectangle::Rectangle(int a, int b) : a{a}, b{b} {
}

int Rectangle::width() const {
  return a;
}

int Rectangle::height() const {
  return b;
}

int Rectangle::area() const {
  return a*b;
}
