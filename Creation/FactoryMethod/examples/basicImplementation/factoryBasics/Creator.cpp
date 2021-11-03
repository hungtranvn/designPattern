#include "Creator.h"
#include "Product.h"
void Creator::AnOperation() {
	m_pProduct = Create();
	m_pProduct->Operation();
}
