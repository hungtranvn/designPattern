#ifndef CONCRETE_PRODUCT_H
#define CONCRETE_PRODUCT_H
#include "Product.h"
class ConcreteProduct :
	public Product
{

public:
	void Operation() override;
};
#endif
