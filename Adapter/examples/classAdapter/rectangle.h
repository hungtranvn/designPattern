#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
class Rectangle {
  int a;
  int b;  
public:
  Rectangle();
  Rectangle(int a, int b);
  virtual int width() const;
  virtual int height() const;
  virtual int area() const;
};

#endif // _RECTANGLE_H_
