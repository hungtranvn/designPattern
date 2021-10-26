#include <set>
#include <iostream>
#include <functional>

using namespace std;

template <class T> void print(T start, T end) {
        while (start != end) {
                std::cout << *start << " "; start++;
        }
    }

int main()
{
    int t[]={1, 10, 8, 4, 6, 5, 3, 9, 7, 2};
    set <int> s1;
    set <int> s2(t, t+10);
    print(s2.begin(), s2.end()); cout<<endl;
    set <int> s3(s2);
    print(s3.begin(), s3.end()); cout<<endl;
    
    set<int, greater<int> > s4 (t,t+10);
    print(s4.begin(), s4.end()); cout<<endl;

    set <int> s6;
    s6 = s3;
    print(s6.begin(), s6.end()); cout<<endl;
    return 0;
}





#include <set>
#include <iostream>
#include <functional>

using namespace std;

template <class T> void print(T start, T end) {
        while (start != end) {
                std::cout << *start << " "; start++;
        }
    }


int main()
{
    int t[]={2, 10, 8, 4, 5, 5, 3, 10, 7, 2};
    multiset <int> s1;
    multiset <int> s2(t, t+10);
    print(s2.begin(), s2.end()); cout<<endl;
    multiset <int> s3(s2);
    print(s3.begin(), s3.end()); cout<<endl;
    
    multiset<int, greater <int> > s4 (t,t+10);
    print(s4.begin(), s4.end()); cout<<endl;
    
    multiset <int> s6;
    s6 = s3;
    print(s6.begin(), s6.end()); cout<<endl;
    return 0;
}
