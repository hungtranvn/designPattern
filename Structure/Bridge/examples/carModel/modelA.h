#ifndef _MODEL_A_H_
#define _MODEL_A_H_

#include "icar.h"
#include "icolor.h"
#include <memory>

class ModelA : public ICar {
  IColor* _color;
public:
  ModelA(IColor* color);
  std::string model();
};
#endif // _MODEL_A_H_
