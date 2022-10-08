#include <iostream>
#include "ConcreteComponent.h"
#include "ConcreteDecoratorA.h"
#include "ConcreteDecoratorB.h"

// we cant pass any object in this function
// client do not identify the component obj
// add more function to Decorator class
void Operate(Component *c)
{
  c->Operation();
}

int main() 
{
  ConcreteComponent component{};
  ConcreteDecoratorA decoratorA(&component);
  decoratorA.Operation();

  return 0;
}
