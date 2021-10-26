#include <deque>
#include <iostream>

using namespace std;

int main() {
  int a1[] = {1,2,3,4,5,6,7,8,9,10};
  deque <int> d1(a1, a1+10);
  for (unsigned i = 0; i < d1.size(); ++i) {
    cout << d1[i] << " ";
  }
  cout << endl;
  return 0;
}
