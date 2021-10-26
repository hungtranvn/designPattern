# Type comversion

A type cast is basically a conversion from one type to another.
There are two types of type conversion:
1. Implicit Type Conversion
(automatic type conversion)
-Done by the compiler on its own, without any external trigger from the user
-Generally takes place when is an expression more than one data type is present
-All the data types of variables are upggraded to the data type of the variable with largest data type
bool -> char -> short int -> int -> unsigned int -> long -> unsigned -> \
long long -> float -> double -> long double
-It is possible for implicit conversion to lose information, signs can be lost (signed -> unsigned), \
over flow can occur (long long is implicitly converted to float)
# Example:

#include<iostream>
using namespace std;

int main() {
  int x = 10;
  char y = 'a';
  
  x = x + y; // y implicitly converted to int
  
  float z = x + 1.0 // x is implicitly converted to float
  
  cout << x << " "<< y << " " << z << endl;
  return 0;
}

2. Explicit Type Conversion
(casting or user-defined)
There are two ways of casting
- converting by assignment:

#include <iostream>
using namespace std;
int main() {
  double x = 1.2;
  int sum = (int)x + 1;
  cout << sum << endl;
  return 0;
}
- conversion by using cast operator

#include <iostream> 
using namespace std;
int main() {
  float f = 3.5;
  int b = static_cast<int>(f);
  cout << b;
}
