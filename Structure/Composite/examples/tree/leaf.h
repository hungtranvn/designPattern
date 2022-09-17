#ifndef _LEAF_H_
#define _LEAF_H_
#include "component.h"

class Leaf : public Component {
public:
  std::string operation() const override;
};
#endif
