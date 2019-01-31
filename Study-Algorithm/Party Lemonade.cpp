//http://codeforces.com/contest/913/problem/C
#include <iostream>
#include <list>
using namespace std;
class bottle
{
public:
	int l, cost;
	bottle(int _l, int _cost)
	{
		l = _l;
		cost = _cost;
	}
	double getEff()
	{
		return (double)cost / l;
	}
	void operator=(const bottle &b)
	{
		l = b.l;
		cost = b.cost;
	}
	bool operator<(bottle &b)
	{
		if (getEff() == b.getEff())
			return l < b.l;
		else
			return getEff() < b.getEff();
	}
};
list<bottle> li;
long long solution(int l)
{
	long long min = 9223372036854775807;
	for (auto i = li.begin(); i != li.end(); i++)
	{
		if (i->l > l && min > i->cost)
			min = i->cost;
	}
	for (auto i = li.begin(); i != li.end(); i++)
	{
		if (i->l <= l)
		{
			long long quo = l / i->l;
			long long rem = l % i->l;
			if (rem == 0)
				return (min < i->cost * quo) ? min : i->cost * quo;
			else
			{
				long long a = i->cost * (quo + 1);
				long long b = i->cost * quo + solution(rem);
				if (min > a)
					min = a;
				if (min > b)
					min = b;
				return min;
			}
		}
	}
}
int main(void)
{
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		int cost;
		cin >> cost;
		li.push_back(bottle(1 << i, cost));
	}
	li.sort();
	long long a = solution(l);
	cout << a;
	return 0;
}