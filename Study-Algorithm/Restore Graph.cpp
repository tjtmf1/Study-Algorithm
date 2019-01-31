//http://codeforces.com/problemset/problem/404/C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class node
{
public:
	int num;
	int dis;
	node(int _num, int _dis)
	{
		num = _num;
		dis = _dis;
	}
	node operator=(node n)
	{
		num = n.num;
		dis = n.dis;
		return n;
	}
	bool operator<(node n)
	{
		return dis < n.dis;
	}
};
int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<node> v;
	vector<int> edge;
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		v.push_back(node(i, a));
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	int cur_dis = 1;
	int first_index = 1;
	int cur_index = 0;
	int cur_edge = 0;
	if (k == 1 && n > 2)
	{
		cout << -1 << endl;
		return 0;
	}
	if (v[0].dis != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (v[i].dis == cur_dis)
		{
			cnt++;
			edge.push_back(v[cur_index].num);
			edge.push_back(v[i].num);
			cur_edge++;
			if ((v[i].dis != 1 && cur_edge >= k - 1) || (cur_edge == k && v[i].dis == 1))
			{
				cur_edge = 0;
				cur_index++;
			}
		}
		else if (v[i].dis == cur_dis + 1)
		{
			cnt = 1;
			cur_index = first_index;
			first_index = i;
			edge.push_back(v[cur_index].num);
			edge.push_back(v[i].num);
			cur_edge = 1;
			cur_dis++;
		}
		else
		{
			cout << -1 << endl;
			return 0;
		}
		if (cur_index == first_index)
		{
			cnt = 0;
			cur_dis++;
			cur_edge = 0;
			cur_index = first_index;
			first_index = i + 1;
		}
	}
	cout << n - 1 << endl;
	for (int i = 0; i < edge.size(); i += 2)
		cout << edge[i] << " " << edge[i + 1] << endl;
	return 0;
}