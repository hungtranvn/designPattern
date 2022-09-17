/*
 * C++ Design Pattern: Proxy
 * Author: Hung Tran
 * 2021
 * */

#ifndef _SUBJECT_H_
#define _SUBJECT_H_

/*
 * Define the common interface for RealSubject and Proxy
 * so that a Proxy can be used anywhere a RealSubject is expected.
 * */

class Subject {
public:
  virtual ~Subject() = default;
  virtual void request(void) = 0;
};
#endif // _SUBJECT_H_
