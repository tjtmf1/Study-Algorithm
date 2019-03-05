//https://www.acmicpc.net/problem/2156
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> drink(n);
	for (int i = 0; i < n; i++)
		cin >> drink[i];
	if (n == 1)
		cout << drink[0] << endl;
	else
	{
		vector<vector<int> > dp(2, vector<int>(n + 1, 0));
		dp[0][1] = drink[0];
		for (int i = 2; i < n + 1; i++)
		{
			dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + drink[i - 1];
			if (i >= 3)
				dp[0][i] = max(dp[0][i], max(dp[0][i - 3], dp[1][i - 3]) + drink[i - 1]);
			dp[1][i] = dp[0][i - 1] + drink[i - 1];
		}
		cout << max(dp[0][n], max(dp[1][n], dp[1][n - 1])) << endl;
	}
	return 0;
}