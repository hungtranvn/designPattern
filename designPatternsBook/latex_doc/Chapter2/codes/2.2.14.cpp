#include <set>
#include <iostream>
#include <functional>

using namespace std;

template <class T> void print(T start, T end) {
        for ( ;start != end; ++start) {
                std::cout << *start << " ";
        }
    }

int main()
{
    int t[]={1, 10, 8, 4, 5, 6, 3, 9, 7, 2};
    set <int> s1(t,t+10);
    cout<<"S1: ";     print(s1.begin(), s1.end());cout<<endl;
    cout<<"Finding range [4,6]:\n";
    set<int>::iterator it1 = s1.lower_bound(4);
    set<int>::iterator it2 = s1.upper_bound(6);
    print(it1,it2); cout<<endl<<endl;
    cout<<"Finding single value range using equal_bounds\n";
    pair<set<int>::iterator, set<int>::iterator> p = s1.equal_range(4);
    print(p.first, p.second); cout<<endl;
    return 0;
}

