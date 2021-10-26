#include <list>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int main() {
  //containers
  vector <int> v;
  deque <int> d;
  list <int> l;

  //iterators
  vector <int> :: iterator it1; // read/write iterator type
  vector <int> :: const_iterator it2; // read-only iterator type 
  vector <int> :: reverse_iterator it3; // reverse iterator type
  vector <int> :: const_reverse_iterator it4; // as above but read-only

  deque <int> :: iterator it5;
  deque <int> :: const_iterator it6;
  deque <int> :: reverse_iterator it7;
  deque <int> :: const_reverse_iterator it8;

  list <int> :: iterator it9;
  list <int> :: const_iterator it10;
  list <int> :: reverse_iterator it11;
  list <int> :: const_reverse_iterator it12;
}
