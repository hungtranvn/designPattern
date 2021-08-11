#ifndef CREATOR_H
#define CREATOR_H
class Product;
class Creator {
	Product *m_pProduct;
public:
	void AnOperation();
	virtual Product * Create() {return nullptr;};
};
#endif
