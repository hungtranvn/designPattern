/*
 * explicit type conversion do not allow 
 * when using explicit for constructor: 1 is int type not A object
 * 1 cant not pushed back in v1
 */
#include <vector>
#include <iostream>

using namespace std;

class A {
  int number;
public:
  explicit A(int _number) : number(_number) {} // user-defined
};

int main() {
  vector <A> v1;
  v1.push_back(1); // try with A(1) and build
                   // 1 here is int but v1 is array of A object
  return 0;
}
