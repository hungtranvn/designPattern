#include <iostream>

using namespace std;

class Box {
private:
  double length;
  double breadth;
  double height;
};

int main(void) {
  Box *pBox = new Box();
  delete pBox;
  return 0;
}
