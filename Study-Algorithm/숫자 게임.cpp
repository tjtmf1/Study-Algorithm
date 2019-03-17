//https://algospot.com/judge/problem/read/NUMBERGAME
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<vector<vector<int>>> dp;
int dfs(int turn, int start, int end)
{
	if (start > end)
		return 0;
	if (dp[turn][start][end] != 987654321)
		return dp[turn][start][end];
	vector<int> temp;
	if (end - start >= 1)
	{
		temp.push_back(-dfs(!turn, start + 2, end));
		temp.push_back(-dfs(!turn, start, end - 2));
	}
	temp.push_back(v[start] - dfs(!turn, start + 1, end));
	temp.push_back(v[end] - dfs(!turn, start, end - 1));
	int value = temp[0];
	for (int i = 1; i < temp.size(); i++)
		value = max(value, temp[i]);
	return dp[turn][start][end] = value;
}
int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		v = vector<int>(n);
		dp = vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(n, 987654321)));
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cout << dfs(0, 0, n - 1) << endl;
	}
	return 0;
}