#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "vector.h"
#include "line.h"
#include <vector>

struct Rectangle : Vector {
  Rectangle();
  Rectangle(int x, int y, int width, int height);
  std::vector<Line>::iterator begin() override;
  std::vector<Line>::iterator end() override;
private:
  std::vector<Line> lines;
}
#endif // _RECTANGLE_H_
