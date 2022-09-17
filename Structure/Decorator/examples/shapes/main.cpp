#include <iostream>
#include "coloredShape.h"
#include "circle.h"
#include "transparentShape.h"

int main() {
  Circle c{0.5f};
  ColoredShape redC{c, "red"};
  std::cout << redC.str();
  
  TransparentShape myC{redC, 34};
  //TransparentShape myC{new ColoredShape{new Circle{23}, "green"}, 64};

  std::cout << myC.str();
  return 0;
}
