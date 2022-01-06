/*
 * C++ Design patterns: proxy
 * Author: Hung Tran
 * 2021
 * */

#ifndef _PROXY_H_
#define _PROXY_H_

#include "subject.h"
#include "realSubject.h"

/*
 * Proxy
 * maintains a reference that lets the proxy access the real subject.
 * */
class Proxy : public Subject{
public:
  Proxy(void);
  ~Proxy(void);
  void request(void);
private:
  RealSubject *pSubject;
};
#endif // _PROXY_H_
