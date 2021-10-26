#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  //containers
  vector <int> v(10);
  deque <int> d(10);
  list <int> l(10);

  int i = 1;
  //vector
  vector <int> :: iterator itv;
  for (itv = v.begin(); itv != v.end(); ++itv, ++i) {
    *itv = i;
  }

  for (vector <int> :: reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  
  //deque
  i = 1;
  deque <int> :: iterator itd = d.begin();
  for (itd = d.begin(); itd != d.end(); ++itd, ++i) {
    *itd = i;
  }
  for (deque <int> :: reverse_iterator it = d.rbegin(); it != d.rend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;

  //list
  i = 1;
  list <int> :: iterator itl = l.begin();
  for (; itl != l.end(); ++itl, ++i) {
    *itl = i;
  }

  for (list <int> :: reverse_iterator it = l.rbegin(); it != l.rend(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
  return 0;
}
