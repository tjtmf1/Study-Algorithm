//https://algospot.com/judge/problem/read/CANADATRIP

#include <iostream>

using namespace std;

int l[5000], m[5000], g[5000];
int n, k;

int decision(int d)
{
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (l[i] <= d)
		{
			cnt += (m[i] / g[i]) + 1;
		}
		else if (l[i] - m[i] <= d)
		{
			cnt += (d - (l[i] - m[i])) / g[i] + 1;
		}
	}
	if (cnt < k)
		return 1;
	else if (cnt == k)
		return 0;
	else if (cnt > k)
		return -1;
}

int main(void)
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> l[i] >> m[i] >> g[i];
		int low = 0;
		int high = 8030000;
		int mid = (low + high) / 2;
		while (low + 1 < high)
		{
			int v = decision(mid);
			if (v == -1 || v == 0)
			{
				high = mid;
			}
			else if (v == 1)
			{
				low = mid;
			}
			mid = (low + high) / 2;
		}
		cout << high << endl;
	}

	return 0;
}