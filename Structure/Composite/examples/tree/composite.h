#ifndef _COMPOSITE_H_
#define _COMPOSITE_H_
#include "component.h"
#include <list>

class Composite : public Component {
protected:
  std::list<Component*> _children;
public:
  void add(Component* component) override;
  void remove(Component* component) override;
  bool isComposite() const override;
  std::string operation() const override;
};
#endif // _COMPOSITE_H_
