#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  vector<int> v;
  deque<int> d;
  list<int> l;
  cout << "Size of vector, deque, list: " << v.size() << " " \
       << d.size() << " " <<  l.size() << " " << endl;
  if (v.empty()) {
    v.resize(10);
  }
  if (d.empty()) {
    d.resize(10);
  }
  if (l.empty()) {
    l.resize(10);
  }
  cout << "Size of vector, deque, list: " << v.size() << " " \
       << d.size() << " " <<  l.size() << " " << endl;

}
