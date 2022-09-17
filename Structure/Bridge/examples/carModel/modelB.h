#ifndef _MODEL_B_H_
#define _MODEL_B_H_
#include "icar.h"
#include "icolor.h"

class ModelB : public ICar {
  IColor* _color;
public:
  ModelB(IColor* color);
  std::string model();
};
#endif // _MODEL_B_H_
