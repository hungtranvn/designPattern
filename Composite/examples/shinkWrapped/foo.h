#ifndef _FOO_H_
#define _FOO_H_

#include "pimpl.h"

class Foo {
  class Impl;
  Pimpl<Impl> Impl;
}
#endif // _FOO_H_
