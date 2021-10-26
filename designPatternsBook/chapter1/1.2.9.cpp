#include <vector>
#include <iostream>

using namespace std;

class A {
//public:
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
  vector <A> v1(1);
  cout << "\n";
  v1.push_back(1);
  cout << "\n";
  v1[0] = 10; // auto comversion type occur here: 10 (int) converts to A object by Normal constructor
              // and assignment operator invole
  //cout << v1[0].number1 << " " << v1[0].number2 << "\n";
  cout << "\n";  
  vector <A> v2(v1);

  return 0;
}
