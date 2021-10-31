#include "icolor.h"
#include "icar.h"
#include "redcolor.h"
#include "bluecolor.h"
#include "modelA.h"
#include "modelB.h"

#include <iostream>

int main() {
  IColor* red = new RedColor();
  IColor* blue = new BlueColor();

  ICar* modelA = new ModelA(red);
  ICar* modelB = new ModelB(blue);
  
  std::cout << modelA->model() << std::endl;
  std::cout << modelB->model() << std::endl;
  
  delete red;
  delete blue;

  return 0;
}
