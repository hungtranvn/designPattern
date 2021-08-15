#ifndef CONCRETE_CREATOR1_H
#define CONCRETE_CREATOR1_H
#include "Creator.h"
class ConcreteCreator1 : public Creator {
public:
	Product* Create() override;
};
#endif
