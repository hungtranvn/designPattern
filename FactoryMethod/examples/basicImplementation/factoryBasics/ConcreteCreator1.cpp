#include "ConcreteCreator1.h"
#include "ConcreteProduct1.h"
Product* ConcreteCreator1::Create() {
	return new ConcreteProduct1{};
}
