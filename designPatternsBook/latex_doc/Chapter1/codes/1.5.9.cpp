#include <queue>
#include <deque>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int a1[]={1,2,3,4,5,6,7,8,9,10};

    queue <int> s1(a1, a1+10);

    queue<int, vector <int> > s2(s1);

    deque <int> d1(a1, a1+10);
    queue<int, vector <int> > s3(d1);

    return 0;
}
