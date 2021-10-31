#include "person.h"

/* PIMPL implementation*/

struct Person::PersonImpl {
  void greet(Person* p) {
    std::cout << "Helllo" << p->name.c_str() << std::endl;
  }
};

Person::Person() : m_impl(new PersonImpl){
}

Person::~Person() {
  delete m_impl;
}

void Person::greet() {
  m_impl->greet(this);
}
