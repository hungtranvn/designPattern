#include <vector>
#include <iostream>

using namespace std;

int main(){
  int a1[] = {1,2,3,4,5,6,7,8,9,10};

  vector<int> v1(a1, a1+10);
  cout << "Size (v1): " << v1.size() << endl;
  for (unsigned i = 0; i < v1.size(); ++i){
    cout << v1[i] << " ";
  }
  cout << endl;

  vector<int> v2(a1+5, a1+10);
  cout << "Size (v2): " << v2.size() << endl;
  for (unsigned i = 0; i < v2.size(); ++i){
    cout << v2[i] << " ";
  }
  cout << endl;
  return 0;
}
