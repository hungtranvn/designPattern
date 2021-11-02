#ifndef _COMPONENT_H_
#define _COMPONENT_H_
#include <algorithm>
#include <string>
class Component {
protected:
  Component* _parent;
public:
  virtual ~Component();
  void setParent(Component* parent);
  Component* getParent() const;
  virtual void add(Component* component);
  virtual void remove(Component* component);
  virtual bool isComposite() const;
  virtual std::string operation() const = 0;
};
#endif // _COMPONENT_H_
