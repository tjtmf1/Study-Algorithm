//http://codeforces.com/problemset/problem/118/D
#include <iostream>
using namespace std;
int n1, n2, k1, k2;
long long dp[2][101][101];		//dp[0] : footman  dp[1] : horseman
long long function(int footman, int horseman, int flag)
{
	if (footman < 0 || horseman < 0)
		return 0;
	if (dp[flag][footman][horseman] != -1)
		return dp[flag][footman][horseman];

	long long solution = 0;
	if (flag == 0)
		for (int i = 1; i <= k1; i++)
			solution += function(footman - i, horseman, !flag & 1) % 100000000;
	else
		for (int i = 1; i <= k2; i++)
			solution += function(footman, horseman - i, !flag & 1) % 100000000;

	dp[flag][footman][horseman] = solution;
	return solution;
}
int main(void)
{
	cin >> n1 >> n2 >> k1 >> k2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 101; j++)
			for (int k = 0; k < 101; k++)
			{
				if (j == 0)
				{
					if (k <= k2)
						dp[i][j][k] = 1;
					else
						dp[i][j][k] = 0;
					continue;
				}
				if (k == 0)
				{
					if (j <= k1)
						dp[i][j][k] = 1;
					else
						dp[i][j][k] = 0;
					continue;
				}
				dp[i][j][k] = -1;
			}

	long long solution = function(n1, n2, 0);
	solution += function(n1, n2, 1);

	cout << solution % 100000000 << endl;
	return 0;
}