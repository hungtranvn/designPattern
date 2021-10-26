#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  vector <int> v;
  deque <int> d;
  list <int> l;

  vector <int> :: iterator it1;
  vector <int> :: const_iterator it2;
  vector <int> :: reverse_iterator it3;
  vector <int> :: const_reverse_iterator it4;

  deque <int> :: iterator it5;
  deque <int> :: const_iterator it6;
  deque <int> :: reverse_iterator it7;
  deque <int> :: const_reverse_iterator it8;

  list <int> :: iterator it9;
  list <int> :: const_iterator it10;
  list <int> :: reverse_iterator it11;
  list <int> :: const_reverse_iterator it12;
}
