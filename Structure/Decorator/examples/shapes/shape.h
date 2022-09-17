#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <string>

class Shape {
public:
  virtual std::string str() const = 0;
};
#endif // _SHAPE_H_
