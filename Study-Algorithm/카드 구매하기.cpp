//https://www.acmicpc.net/problem/11052
#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int cost[10001];
	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
	}
	int dp[1001] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		int max = dp[i - 1] + cost[1];
		for (int j = 2; j <= n; j++)
		{
			if (i - j >= 0 && max < dp[i - j] + cost[j])
			{
				max = dp[i - j] + cost[j];
			}
		}
		dp[i] = max;
	}

	cout << dp[n] << endl;
	return 0;
}