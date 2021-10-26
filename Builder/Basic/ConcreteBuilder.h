#ifndef CONCRETE_BUILDER_H
#define CONCRETE_BUILDER_H
#include "Builder.h"
class Product;
class ConcreteBuilder : public Builder {
	Product *product;
public:
	ConcreteBuilder();
	void BuildPart() override;
	Product * GetResult();
};
#endif
