#ifndef CONCRETE_DECORATOR_B_H
#define CONCRETE_DECORATOR_B_H

#include "Component.h"
#include "Decorator.h"

class ConcreteDecoratorB : public Decorator
{
public:
  using Decorator::Decorator;
  void Operation() override;
};

#endif
