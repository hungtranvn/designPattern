#ifndef _PERSON_H_
#define _PERSON_H_

#include <string>
#include <memory>

struct Person {
  class PersonImpl;
  unique_ptr<PersonImpl> m_imp; // Bridge not necessaruly inner class, can vary
  string m_name;
  
  Person();
  ~Person();

  void greet();

private:
  // secret data members or methods are in `PersonImpl` not here
  // as we are going to expose this class to client
}
#endif // _PERSON_H_
