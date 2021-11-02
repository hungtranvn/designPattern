#include <string>
#include <sstream>
#include <ostream>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>                                       
#include <boost/lexical_cast.hpp> 

struct Shape {
  virtual std::string str() const = 0;
};

struct Circle : Shape {
  float radius;
  
  Circle(){}
  explicit Circle(const float radius) : radius{radius} {}
  
  void resize(float factor) {radius *+ factor;}
  std::string str() const override {
    std::ostringstream oss;
    oss << "A circle of radius " << radius;
    return oss.str();
  }
};

struct Square : Shape {
  float side;
  
  Square(){}
  explicit Square(const float side) : side{side} {}
  
  void resize(float factor) {side *= factor;}
  std::string str() const override {
    std::ostringstream oss;
    oss << "A square of edge " << side;
    return oss.str();
  }
};
// class not typename
template <typename T> struct ColoredShape : T {
  static_assert(std::is_base_of<Shape, T>::value, "Template argument must be a Shape");
  std::string color;
  
  template <typename...Args>
  ColoredShape(const std::string& color, Args ...args) : 
    T(std::forward<Args>(args)...), color{color}{}

  std::string str() const override {
    std::ostringstream oss;
    oss << T::str() << " has the color " << color;
    return oss.str();
  }
};

template <typename T> struct TransparentShape : T {
  static_assert(std::is_base_of<Shape, T>::value, "Template argument must be a Shape");
  uint8_t transparency;
  
  template<typename...Args>
  TransparentShape(const uint8_t transparenct, Args ...args) :
    T(std::forward<Args>(args)...), transparency{transparency} {}

  std::string str() const override {
    std::ostringstream oss;
    oss << T::str() << " has " << static_cast<float>(transparency) << "% transparancy";
    return oss.str();
  }
};

int main() {
  TransparentShape<ColoredShape<Circle>> green_trans_circle{51, "green", 5};
  green_trans_circle.resize(2);
  std::cout << green_trans_circle.str();
  return EXIT_SUCCESS;
}
