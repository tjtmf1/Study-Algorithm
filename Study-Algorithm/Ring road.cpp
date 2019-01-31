//http://codeforces.com/problemset/problem/24/A

#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
int n;
int cost = 0;
int sum = 0;
class edge
{
public:
	int m_start, m_end, m_cost;
	edge(int start, int end, int cost)
	{
		m_start = start;
		m_end = end;
		m_cost = cost;
	}
	void operator=(const edge &e)
	{
		m_start = e.m_start;
		m_end = e.m_end;
		m_cost = e.m_cost;
	}
	bool operator<(const edge &e) const
	{
		return m_cost > e.m_cost;
	}
};
unordered_map<int, int> map;
list<edge> e;
int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		e.push_back(edge(start, end, cost));
		sum += cost;
	}
	e.sort();
	edge select = e.front();
	e.pop_front();
	int find = select.m_end;
	for (int i = 0; i < n - 1; i++)
	{
		list<edge>::iterator it = e.begin();
		while (true)
		{
			if ((*it).m_start == find)
			{
				find = (*it).m_end;
				e.erase(it);
				break;
			}
			else if ((*it).m_end == find)
			{
				cost += (*it).m_cost;
				find = (*it).m_start;
				e.erase(it);
				break;
			}
			else
				it++;
		}
	}
	if (cost > sum - cost)
	{
		cout << sum - cost << endl;
	}
	else
		cout << cost << endl;

	return 0;
}