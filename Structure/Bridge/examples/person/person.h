#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>

class Person {
public:
  std::string name;
  class PersonImpl;
  PersonImpl* impl;

  Person();
  ~Person();
  void greet();
}

#endif // _PERSON_H_
