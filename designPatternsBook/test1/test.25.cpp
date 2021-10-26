#include <stack>
#include <deque>
#include <iostream>

using namespace std;

int main()
{
	int t[] = {1, 5, 3, 4, 2};
	deque<int>	d(t, t+5);
	stack<int> s(d);
	cout<<s.top()<<" ";
	d.push_front(6);
	cout<<s.top()<<endl;
	return 0;
}
