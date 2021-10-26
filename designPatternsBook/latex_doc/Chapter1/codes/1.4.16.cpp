#include <list>
#include <iostream>

using namespace std;

template<class I>
void print(const I& start, const I& end) {
  for (I it = start; it != end; ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

bool compareInt(double v1, double v2) {
  if ((int)v1 == (int)v2) {
    return true;
  }
  return false;
}

int main() {
  int a[] = {1,2,1,3,2,3,4,3,4,7,8,9,6,6,5,8,9,10};

  list<int> l1(a,a+18);
  list<int> l2(a,a+18);
  print(l1.begin(), l1.end());

  cout << "Deleting all subsequent duplicates:" << endl;
  l1.unique();
  print(l1.begin(), l1.end());

  cout << "Deleting all subsequent duplicates from sorted list:" << endl;
  l2.sort();
  l2.unique();
  print(l2.begin(), l2.end());

  cout << "Test function with double type";
  double b[] = {1.6,2.3,1.4,3.1,2.4,3.5,4.9,3.2,4.7,7.8,8,9.1,6.2,6.8,\
    5.5,8.4,9.2,10};
  list<double> l3(b,b+18);
  list<double> l4(b,b+18);

  print(l3.begin(), l3.end());
  cout << "Deleting all subsequent duplicates - int comparison" << endl;
  l1.unique(compareInt);
  print(l3.begin(), l3.end());

  cout << "Deleting all subsequent dublicates - int comparison - sorted" << endl;
  l4.sort();
  l4.unique(compareInt);
  print(l4.begin(), l4.end());

  return 0;
}
