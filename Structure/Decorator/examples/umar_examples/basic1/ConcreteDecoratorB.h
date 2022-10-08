#ifndef CONCRETE_DECORATOR_B_H
#define CONCRETE_DECORATOR_B_H
#include "Component.h"

class ConcreteDecoratorB : public Component
{
  Component *m_ptr {};
public:
  ConcreteDecoratorB(Component* ptr) : m_ptr{ptr} {}
  void Operation() override;
};

#endif
