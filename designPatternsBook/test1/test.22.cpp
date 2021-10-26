#include <queue>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
	int t[] = {1, 5, 3, 4, 2};
	deque<int>	d(t, t+5);
	queue<int> q(d);
	cout<<q.front()<<" "<<q.back()<<" ";
	q.pop();
	cout<<q.front()<<" "<<q.back()<<endl;
	return 0;
}
