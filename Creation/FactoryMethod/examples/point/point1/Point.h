#ifndef POINT_H
#define POINT_H
enum class Coordinate{
  cartesian,
  polar
};

class Point {
private:
  double _x;
  double _y;
public:
  Point(double x, double y, Coordinate c);
};
#endif
