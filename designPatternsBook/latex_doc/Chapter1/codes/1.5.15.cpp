#include <deque>
#include <list>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main()
{
    int a1[]={1,2,3,4,5,6,7,8,9,10};
    vector<int>    v1(a1,a1+10);
    
    priority_queue<int>  q1(v1);
    
    priority_queue<int, list <int> > q2;

    priority_queue<int, greater <int> > q3;

    priority_queue<int>  q4(greater<int>());
    return 0;
}
