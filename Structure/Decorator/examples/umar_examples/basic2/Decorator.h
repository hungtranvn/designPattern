#ifndef DECORATOR_H
#define DECORATOR_H

#include "Component.h"

class Decorator : public Component
{
  Component *m_ptr{};
public:
  Decorator(Component* ptr) : m_ptr{ptr} {}
  void Operation() override = 0;
};

// If client instantiate this class => there are nothing to do here
// => prevent the instantiation of this class.
// There are two ways: make constructor protected or Operation() = 0
#endif
