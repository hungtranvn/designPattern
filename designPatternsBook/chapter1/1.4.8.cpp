#include <vector>
#include <deque>
#include <list>
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
  vector<int> v(a, a+10);
  list<int> l(a, a+10);
  deque<int> d(a, a+10);

  vector<int>::iterator it = v.insert(v.begin()+5, 100);
  list<int>::iterator it1 = l.insert(l.begin(), 100);
  deque<int>::iterator it2 = d.insert(d.begin(), 100);


  print(v.begin(), v.end());
  cout << "Inserted element: " << *it << endl;
  cout << "Size: " << v.size() << endl;
  vector<int> v2;
  v2.insert(v2.begin(), v.rbegin(), v.rend());
  print(v2.begin(), v2.end());

  vector<int> v3(v.begin(), v.begin() + 5);
  v3.insert(v3.end(), 3, 100);
  print(v3.begin(), v3.end());
  
  list<int> l1;
  l1.insert(l1.begin(), l.begin(), l.end());
  return 0;
}
