#include <vector>
#include <deque>
#include <iostream>

using namespace std;

template <class C>
void print1 (const C& container) {
  for (unsigned i = 0; i < container.size(); i++) {
    cout << container[i] << " ";
  }
  cout << endl;
}

template <class C>
void print2 (const C& container) {
  for (unsigned i = 0; i < container.size(); i++) {
    cout << container.at(i) << " ";
  }
  cout << endl;
}

int main() {
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  vector<int> v(10);
  deque<int> d(10);

  for (unsigned i = 0; i < 10; ++i) {
    d[i] = a[i];
    v[i] = a[i];
  }
  cout << "Accessing by operator []" << endl;
  print1 (v);
  print1 (d);
  cout << "Accessing out of range element: \n";
  cout << v[10] << " " << d[10] << endl << endl;
  
  cout << "Accessing by operator at()" << endl;
  print2 (v);
  print2 (d);
  cout << "Accessing out of range element: \n";
  try {
    cout << v.at(10) << endl;
  }
  catch (out_of_range & ex) {
    cout << ex.what() << endl;
  }

  try {
    cout << d.at(10) << endl;
  }
  catch (out_of_range & ex) {
    cout << ex.what() << endl;
  }
  return 0;
}
