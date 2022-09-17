#include "component.h"

Component::~Component() {
}

void Component::setParent(Component* parent) {
  this->_parent = parent;
}

void Component::add(Component* component) {
}

void Component::remove(Component* component) {
}

Component* Component::getParent() const {
  return this->_parent;
}

bool Component::isComposite() const {
  return false;
}
