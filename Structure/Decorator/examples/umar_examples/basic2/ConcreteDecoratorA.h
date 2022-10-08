#ifndef CONCRETE_DECORATOR_A_H
#define CONCRETE_DECORATOR_A_H

#include "Component.h"
#include "Decorator.h"

class ConcreteDecoratorA : public Decorator
{
public:
  //using Decorator::Decorator; // inheritence feature cpp17
  ConcreteDecoratorA(Component* ptr) : Decorator{ptr} {}
  void Operation() override;
};

#endif
