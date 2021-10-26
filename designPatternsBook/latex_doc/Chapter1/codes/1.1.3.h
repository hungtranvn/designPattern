#ifndef ARRAY_H
#define ARRAY_H
#include <exception>
#include <iostream>

namespace CPP_course {
  class Array {
    int * _array;
    unsigned int _size;
  public:
    Array(unsigned size = 0);
    void add(int value);
    void delItem(unsigned index);
    virtual ~Array();
    unsigned int getSize() const;
    int & operator[](unsigned index);
  };
}
#endif
