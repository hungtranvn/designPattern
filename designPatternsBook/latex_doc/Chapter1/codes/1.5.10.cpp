#include <iostream>
#include <queue>
#include <deque>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int a1[]={1,2,3,4,5,6,7,8,9,10};
    deque <int> d1(a1, a1+10);
    queue <int>s1;
    queue <int> s2(d1);

    s1 = s2;
    cout<<s1.size()<<":"<<s2.size()<<endl;
    
    queue<int, vector <int> > s3;

    return 0;
}
