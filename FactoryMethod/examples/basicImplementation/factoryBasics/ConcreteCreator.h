#ifndef CONCRETE_CREATOR_H
#define CONCRETE_CREATOR_H
#include "Creator.h"
class ConcreteCreator : public Creator {
public:
	Product* Create() override;
};
#endif
