#ifndef POINT_H
#define POINT_H
class Point {
private:
  double _x;
  double _y;
public:
  virtual ~Point() = default;
  virtual void anOperation() = 0;
};
#endif
