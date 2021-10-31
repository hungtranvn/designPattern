#ifndef _ADAPTER_H_
#define _ADAPTER_H_
#include "rectangle.h"
#include "square.h"
class Adapter : public Rectangle, private Square{
public:
  Adapter(Square& s);
  int width() const override;
  int height() const override;
  int area() const override;
};
#endif // _ADAPTER_H_
