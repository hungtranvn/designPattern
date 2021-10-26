#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T> ostream & print(const T & start, const T & end)
{
	T tmp = start;
	for(; tmp != end; ++tmp)
	{
		cout<< *tmp<< " ";
	}
	return cout;
}
class A
{
public:
	int a;
public:
	A(int a):a(a) {}
};

ostream & operator<<(ostream & c, const A & o)
{
	c<<o.a;
	return c;
}

void fill (const int table[], unsigned size, vector<A*> & v)
{
	for(unsigned i = 0; i < size; ++i)
	{
		v.push_back(new A(table[i]));			//LINE I
	}
}

void del(A * p)
{
	delete p;
}
int main()
{
	int tab[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<A*> v1;
	fill(tab, 10, v1);

	print(v1.rbegin(), v1.rend())<<endl;		//LINE II
	for_each(v1.begin(), v1.end(), del);
	return 0;
}

