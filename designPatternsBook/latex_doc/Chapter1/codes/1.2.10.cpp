#include <vector>
#include <iostream>

using namespace std;

class A {
  int number1;
  int number2;
public:
  A(int _number) : number1(_number), number2(0) {
    cout << "Normal constructor\n";
  }
  
  A() {
    cout << "Default constructor\n";
  }
  
  explicit A(const A& source) {
    number1 = source.number1;
    number2 = source.number2;
    cout << "Copy constructor\n";
  }

  A & operator=(const A& source) {
    number1 = source.number1;
    number2 = source.number2;
    cout << "Assignment operator\n";
    return *this;
  }
};

int main() {
  vector <A> v1;
  v1.push_back(1);
  cout << "First ready!\n";
  vector <A> v2(v1);
  cout << "Second ready!\n";
  vector <A> v3;
  v3 = v2; 
  vector <A> v4(2);
  v4 = v2;
  return 0;
}
