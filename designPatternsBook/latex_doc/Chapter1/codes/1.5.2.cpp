#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>
using namespace std;

int main()
{
    int a1[]={1,2,3,4,5,6,7,8,9,10};

    stack <int> s1;

    stack <int> s2(s1);

    deque <int> d1(a1, a1+10);
    stack <int> s3(d1);
    
    stack<int, list <int> > s4;
    stack<int, vector <int> > s5;

    return 0;
}
