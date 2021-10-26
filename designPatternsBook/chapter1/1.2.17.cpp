#include <deque>
#include <iostream>

using namespace std;

int main() {
  int a1[] = {1,2,3,4,5,6,7,8,9,10};
  deque <int> d1(a1,a1+10);
  cout << "Size (d1): " << d1.size() << endl;
  for (unsigned i = 0; i < d1.size(); ++i) {
    cout << d1[i] << " ";
  }
  cout << endl;
  deque <int> d2(d1);
  cout << "Size (d2): " << d2.size() << endl;
  return 0;
}
