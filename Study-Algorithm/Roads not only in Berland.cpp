//http://codeforces.com/problemset/problem/25/D
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<int> edge[1001];
	stack<int> visit;
	vector<int> root;
	vector<int> bedge;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int cnt = 0;
	bool isVisited[1001] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		if (!isVisited[i])
		{
			cnt++;
			root.push_back(i);
			visit.push(i);
		}
		while (visit.size() != 0)
		{
			int cur = visit.top();
			visit.pop();
			while (edge[cur].size() != 0)
			{
				int node = edge[cur].at(0);
				if (!isVisited[node])
				{
					visit.push(node);
					isVisited[node] = true;
				}
				else
				{
					bedge.push_back(cur);
					bedge.push_back(node);
				}
				edge[cur].erase(edge[cur].begin());
				for (int k = 0; k < edge[node].size(); k++)
				{
					if (edge[node].at(k) == cur)
					{
						edge[node].erase(edge[node].begin() + k);
						break;
					}
				}
			}
		}
	}
	cout << cnt - 1 << endl;
	for (int i = 0; i < cnt - 1; i++)
	{
		cout << bedge[i * 2] << " " << bedge[i * 2 + 1] << " " << root[i] << " " << root[i + 1] << endl;
	}
	return 0;
}