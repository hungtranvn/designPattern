#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

template <class I>
void print(const I& start, const I& end) {
  I it;
  for (it = start; it != end; ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  int a[] = {1,2,3,4,5,6,7,8,9,10};
  vector<int> v1(a,a+5);
  list<int> l1(a,a+5);
  deque<int> d1(a,a+5);
  
  vector<int> v2(a+5, a+10);
  list<int> l2(a+5,a+10);
  deque<int> d2(a+5,a+10);

  v1.swap(v2);
  l1.swap(l2);
  d1.swap(d2);

  return 0;

}
