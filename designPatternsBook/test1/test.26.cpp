#include <vector>
#include <iostream>

using namespace std;

template<typename T> ostream & print(T & start, T & end)
{
	for(; start != end; ++start)
	{
		cout<< *start<< " ";
	}
	return cout;
}

int main()
{
	int tab[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v1(tab, tab+10);
	vector<int> v2;
	vector<int>::iterator it;
	for(it = v1.begin(); it != v1.end(); ++it)
	{
		v2.push_back(v1[v1.end()-it-1]);	//LINE I
	}
	print(v2.rbegin(), v2.rend()) << endl;	//LINE II
	return 0;
}
