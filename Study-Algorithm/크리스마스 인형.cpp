//https://algospot.com/judge/problem/read/CHRISTMAS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int n, k;
		cin >> n >> k;
		vector<int> d(n);
		vector<int> sd(n + 1);
		for (int i = 0; i < n; i++)
		{
			cin >> d[i];
		}
		sd[0] = 0;
		vector<int> cnt(k, 0);
		cnt[0] = 1;
		for (int i = 1; i < n + 1; i++)
		{
			sd[i] = sd[i - 1] + d[i - 1];
			sd[i] %= k;
			cnt[sd[i]]++;
		}
		long long a1 = 0;
		for (int i = 0; i < k; i++)
		{
			if (cnt[i] >= 2)
			{
				a1 += ((cnt[i] * (long long)(cnt[i] - 1)) / 2);
				a1 %= 20091101;
			}
		}
		vector<int> dp(n + 1, 0);
		vector<int> prev(k, -1);
		dp[0] = 0;
		prev[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = dp[i - 1];
			int loc = prev[sd[i]];
			if (loc != -1)
				dp[i] = max(dp[i], dp[loc] + 1);
			prev[sd[i]] = i;
		}
		cout << a1 << " " << dp[n] << endl;
	}

	return 0;
}