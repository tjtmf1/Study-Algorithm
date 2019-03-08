//https://algospot.com/judge/problem/read/POLY
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> dp(101, vector<int>(101, -1));
int solve(int remainBlock, int top)
{
	int ret = 0;
	if (dp[remainBlock][top] != -1)
		return dp[remainBlock][top];
	else
	{
		for (int i = 1; i <= remainBlock- top; i++)
		{
			if (top == 0)
				ret += solve(remainBlock - top, i);
			else
				ret += solve(remainBlock - top, i) * (top + i - 1);
			ret %= 10000000;
		}
		return dp[remainBlock][top] = ret;
	}
}
int main(void)
{
	for (int i = 1; i <= 100; i++)
		dp[i][i] = 1;
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		cout << solve(n, 0) << endl;
	}
	return 0;
}