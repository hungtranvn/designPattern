#ifndef POINT_H
#define POINT_H
class Point {
private:
  Point() = default;
public:
  double _x;
  double _y;
  static Point MakePointCartesian(double x, double y);
  static Point MakePointPolar(double rho, double theta);
};
#endif
