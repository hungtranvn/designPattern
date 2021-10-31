#include "person.h"

struct PersonImpl {
  void greet(std::string& name) {
    std::cout << "Hello " << name << std::endl;
  }
};

Person::Person() {
  static_assert(sizeof(impl) >= sizeof(PersonImpl));
  new(&impl) PersonImpl;
}

Person::~Person() {
  reinterpret_casr<PersonImpl*> (&impl)->~PersonImpl();
}

Person::~Person() {
  reinterpret_cast<PersonImpl*>(&impl)->~PersonImpl();
}

void Person::greet() {
  reinterpret_cast<PersonImpl*>(&impl)->greet(name);
}
