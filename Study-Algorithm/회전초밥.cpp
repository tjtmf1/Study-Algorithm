//https://algospot.com/judge/problem/read/SUSHI

#include <iostream>
using namespace std;
int main(void)
{
	int c;
	cin >> c;
	for (int test = 0; test < c; test++)
	{
		int n, budget;
		cin >> n >> budget;
		budget /= 100;
		int price[20];
		int preference[20];
		for (int i = 0; i < n; i++)
		{
			cin >> price[i] >> preference[i];
			price[i] /= 100;
		}
		int *dp = new int[budget + 1];
		for (int i = 0; i < budget + 1; i++)
		{
			int max = 0;
			for (int j = 0; j < n; j++)
			{
				if (i - price[j] >= 0)
				{
					if (dp[i - price[j]] + preference[j] > max)
						max = dp[i - price[j]] + preference[j];
				}
			}
			dp[i] = max;
		}
		cout << dp[budget] << endl;
		delete[] dp;
	}

	return 0;
}