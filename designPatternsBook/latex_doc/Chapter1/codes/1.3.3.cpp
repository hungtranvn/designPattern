#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  vector <int> v(10);
  deque <int> d(10);
  list <int> l(10);

  int i = 1;

  vector <int> :: iterator itv;
  for (itv = v.begin(); itv != v.end(); ++itv, ++i) {
    *itv = i;
  }

  for (itv = v.begin(); itv != v.end(); ++itv) {
    cout << *itv << " ";
  }
  cout << endl;

  deque <int> :: iterator itd = d.begin();
  for (itd = d.begin(); itd != d.end(); ++itd, ++i) {
    *itd = i;
  }

  for (itd = d.begin(); itd !=d.end(); ++itd) {
    cout << *itd << " ";
  }
  cout << endl;

  list <int> :: iterator itl = l.begin();
  for (itl = l.begin(); itl != l.end(); ++itl, ++i) {
    *itl = i;
  }

  for (itl = l.begin(); itl != l.end(); ++itl) {
    cout << *itl << " ";
  }
  cout << endl;
  return 0;
}
