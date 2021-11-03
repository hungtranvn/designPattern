#include "rectangle.h"
Rectangle::Rectangle(int x, int y, int width, int height {
  lines.emplace_back(Line{Point{x, }, Point{x + width, y}});
  lines.emplace_back(Line{Point{x + width, y},Point {x + width, y  eight}});
  lines.emplace_back(Line{Point{x, y}, Point{x, y + height}});
  lines.emplace_back(Line{Point{x, y + height}, Point{x + width, y + height}});
}

std::vector<Line>::iterator begin() {
  return lines.begin();
}

std::vector<Line>::iterator end() {
  return lines.end();
}
