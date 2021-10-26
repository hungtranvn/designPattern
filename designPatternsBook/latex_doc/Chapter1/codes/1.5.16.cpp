#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int a1[]={1,2,3,4,5,6,7,8,9,10};
    
    priority_queue<int>  q1(a1, a1+10);
    priority_queue<int>  q2;

    q1 = q2;
    cout<<q1.size()<<":"<<q2.size()<<endl;
    
    priority_queue<int, deque <int> > q3;

    q3 = q2;
    priority_queue<int, vector <int>, greater <int> > q4;
    
    q4 = q1;
    return 0;
}
