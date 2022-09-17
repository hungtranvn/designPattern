/*
 * C++ Design Patterns: Proxy
 * Author: Hung Tran
 * 2021
 * */

#ifndef _REAL_SUBJECT_H_
#define _REAL_SUBJECT_H_

#include "subject.h"

/*
 * Real Subject
 * define the real subject that the proxy represents
 * */
class RealSubject : public Subject {
public:
  void request(void);
};

#endif // _REAL_SUBJECT_H_
