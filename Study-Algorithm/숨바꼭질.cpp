//https://www.acmicpc.net/problem/1697
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<bool> v(100001, false);
	v[n] = true;
	queue<pair<int, int> > q;
	q.push(make_pair(n, 0));
	while (!q.empty())
	{
		pair<int, int> p = q.front(); q.pop();
		if (p.first == k)
		{
			cout << p.second << endl;
			return 0;
		}
		else
		{
			if (p.first - 1 >= 0 && !v[p.first - 1])
			{
				q.push(make_pair(p.first - 1, p.second + 1));
				v[p.first - 1] = true;
			}
			if (p.first + 1 <= 100000 && !v[p.first + 1])
			{
				q.push(make_pair(p.first + 1, p.second + 1));
				v[p.first + 1] = true;
			}
			if (p.first * 2 <= 100000 && !v[p.first * 2])
			{
				q.push(make_pair(p.first * 2, p.second + 1));
				v[p.first * 2] = true;
			}
		}
	}
	return 0;
}