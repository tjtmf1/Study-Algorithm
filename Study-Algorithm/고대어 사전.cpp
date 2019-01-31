//https://algospot.com/judge/problem/read/DICTIONARY
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<bool>> adj;
vector<bool> visited;
vector<int> order;
void dfs(int node)
{
	visited[node] = true;
	for (int i = 0; i < 26; i++)
	{
		if (adj[node][i] && !visited[i])
		{
			dfs(i);
		}
	}
	order.push_back(node);
}
void dfsAll()
{
	visited = vector<bool>(26, false);
	for (int i = 0; i < 26; i++)
	{
		if (!visited[i])
			dfs(i);
	}
}
int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		string s, prev;
		cin >> prev;
		adj = vector<vector<bool>>(26, vector<bool>(26, false));
		order.clear();
		for (int i = 1; i < n; i++)
		{
			cin >> s;
			for (int j = 0; j < min(s.length(), prev.length()); j++)
			{
				if (prev[j] != s[j])
				{
					adj[s[j] - 'a'][prev[j] - 'a'] = true;
					break;
				}
			}
			prev = s;
		}
		dfsAll();
		bool flag = true;
		for (int i = 0; i < 26; i++)
		{
			if (flag)
				for (int j = i + 1; j < 26; j++)
				{
					if (adj[order[i]][order[j]])
					{
						cout << "INVALID HYPOTHESIS" << endl;
						flag = false;
						break;
					}
				}
		}
		if (flag)
		{
			for (int i = 0; i < 26; i++)
				cout << (char)('a' + order[i]);
			cout << endl;
		}
	}

	return 0;
}