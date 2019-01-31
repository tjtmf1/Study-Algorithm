//http://codeforces.com/problemset/problem/61/D
#include <iostream>
#include <vector>
using namespace std;
bool isVisted[100001] = { 0 };
vector<int> edge[100001];
vector<int> weight[100001];
long long _max = 0;
void dfs(int node, long long cost)
{
	isVisted[node] = true;
	bool chk = false;
	for (int i = 0; i < edge[node].size(); i++)
	{
		if (!isVisted[edge[node].at(i)])
		{
			chk = true;
			dfs(edge[node].at(i), cost + weight[node].at(i));
		}
	}
	if (!chk)
	{
		if (_max < cost)
			_max = cost;
	}
}
int main(void)
{
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back(b);
		edge[b].push_back(a);
		weight[a].push_back(c);
		weight[b].push_back(c);
		sum += c * 2;
	}
	dfs(1, 0);
	sum -= _max;
	cout << sum << endl;
	return 0;
}