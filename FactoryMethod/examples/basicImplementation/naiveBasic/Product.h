#ifndef PRODUCT_H
#define PRODUCT_H
class Product
{
public:
	virtual void Operation() = 0;
	virtual ~Product() = default;
};
#endif
