#ifndef CONCRETE_DECORATOR_A_H
#define CONCRETE_DECORATOR_A_H
#include "Component.h"

class ConcreteDecoratorA : public Component
{
  Component *m_ptr {};
public:
  ConcreteDecoratorA(Component* ptr) : m_ptr{ptr} {}
  void Operation() override;
};

#endif
