//http://codeforces.com/problemset/problem/839/C
#include <iostream>
#include <vector>
using namespace std;
int n;
bool check[100001];
vector<int> edge[100001];
vector<double> solution;
void dfs(int node, int dis, double pro, bool first = false)
{
	bool chk = false;
	for (int i = 0; i < edge[node].size(); i++)
	{
		if (!check[edge[node].at(i)])
		{
			chk = true;
			check[edge[node].at(i)] = true;
			if (!first)
				dfs(edge[node].at(i), dis + 1, pro / (edge[node].size() - 1));
			else
				dfs(edge[node].at(i), dis + 1, pro / edge[node].size());
			check[edge[node].at(i)] = false;
		}
	}
	if (!chk)
		solution.push_back(dis * pro);
}

int main(void)
{
	cin >> n;
	for (int i = 1; i < n + 1; i++)
		check[i] = false;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	check[1] = true;
	dfs(1, 0, 1, true);
	double sum = 0;
	for (int i = 0; i < solution.size(); i++)
		sum += solution[i];
	cout << fixed;
	cout.precision(15);
	cout << sum << endl;
	return 0;
}