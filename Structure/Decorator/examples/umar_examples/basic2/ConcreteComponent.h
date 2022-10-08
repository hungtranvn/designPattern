#ifndef CONCRETE_COMPONENT_H
#define CONCRETE_COMPONENT_H
#include "Component.h"
class ConcreteComponent : public Component 
{
  public:
    void Operation() override;
};
#endif
