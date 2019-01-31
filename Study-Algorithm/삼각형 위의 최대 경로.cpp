//https://algospot.com/judge/problem/read/TRIANGLEPATH
//https://algospot.com/judge/problem/read/TRIPATHCNT
#include <iostream>
using namespace std;
int main(void)
{
	int c;
	cin >> c;
	int arr[100][100];
	int sum[100][100];
	int cnt[100][100] = { 0, };
	for (int test = 0; test < c; test++)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> arr[i][j];
			}
		}
		sum[0][0] = arr[0][0];
		cnt[0][0] = 1;
		for (int i = 1; i < n; i++)
		{
			sum[i][0] = sum[i - 1][0] + arr[i][0];
			cnt[i][0] = cnt[i - 1][0];
			for (int j = 1; j < i; j++)
			{
				if (sum[i - 1][j - 1] > sum[i - 1][j])
				{
					sum[i][j] = sum[i - 1][j - 1] + arr[i][j];
					cnt[i][j] = cnt[i - 1][j - 1];
				}
				else if (sum[i - 1][j - 1] < sum[i - 1][j])
				{
					sum[i][j] = sum[i - 1][j] + arr[i][j];
					cnt[i][j] = cnt[i - 1][j];
				}
				else
				{
					sum[i][j] = sum[i - 1][j] + arr[i][j];
					cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1];
				}
			}
			sum[i][i] = sum[i - 1][i - 1] + arr[i][i];
			cnt[i][i] = cnt[i - 1][i - 1];
		}
		int max = -1;
		int max_cnt = -1;
		for (int i = 0; i < n; i++)
		{
			if (sum[n - 1][i] > max)
			{
				max = sum[n - 1][i];
				max_cnt = cnt[n - 1][i];
			}
			else if (sum[n - 1][i] == max)
			{
				max_cnt += cnt[n - 1][i];
			}
		}
		cout << max << endl;
		//cout << max_cnt << endl;
	}

	return 0;
}