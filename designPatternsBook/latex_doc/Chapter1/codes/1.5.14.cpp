#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    int a1[]={1,2,3,4,5,6,7,8,9,10};

    priority_queue<int>  s1;

    priority_queue<int>  s2(s1);

    vector<int>  v1(a1, a1+10);
    priority_queue<int>  s3(v1.begin(), v1.end());
    
    priority_queue<int, deque <int> > s4;

    priority_queue<int, vector<int>, greater <int> > s5;
    return 0;
}
