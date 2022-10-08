#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
  public:
    virtual void Operation() = 0;
    virtual ~Component() = default;
};
#endif
