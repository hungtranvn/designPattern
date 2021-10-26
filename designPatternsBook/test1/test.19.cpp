#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int main()
{
	int t[] = {3, 5, 1, 4, 2};
	vector<int>	v(t, t+5);
	priority_queue<int> q(v.begin(), v.end());
	cout<<q.top()<<" ";
	q.push(0);
	cout<<q.top()<<endl;
	return 0;
}

