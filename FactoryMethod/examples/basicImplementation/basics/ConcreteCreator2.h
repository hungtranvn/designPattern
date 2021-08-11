#ifndef CONCRETE_CREATOR2_H
#define CONCRETE_CREATOR2_H
#include "Creator.h"
class ConcreteCreator2 :
	public Creator
{

public:
	Product* Create() override;
};
#endif
