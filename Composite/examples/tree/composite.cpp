#include "composite.h"

void Composite::add(Component* component) {
  this->_children.push_back(component);
  component->setParent(this);
}

void Composite::remove(Component* component) {
  _children.remove(component);
  component->setParent(nullptr);
}

bool Composite::isComposite() const {
  return true;
}

std::string Composite::operation() const {
  std::string result;
  for(const Component* c : _children) {
    if(c == _children.back()) {
      result += c->operation();
    }
    else {
      result += c->operation() + "+";
    }
  }

  return "Branch(" + result + ")";
}
