//http://codeforces.com/contest/1006/problem/B
#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a, int b)
{
	return a > b;
}
int main(void)
{
	int n, k;
	int dif[2000];
	int copy[2000];
	int count[2000] = { 0 };
	int index[2000];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> dif[i];
		copy[i] = dif[i];
	}
	sort(dif, dif + n, compare);
	int sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += dif[i];
		for (int j = 0; j < n; j++)
		{
			if (copy[j] == dif[i])
			{
				copy[j] = -1;
				index[i] = j + 1;
				break;
			}
		}
	}
	sort(index, index + k);
	cout << sum << endl;
	int last = 0;
	for (int i = 0; i < k - 1; i++)
	{
		cout << index[i] - last << " ";
		last = index[i];
	}
	cout << n - last << endl;
	return 0;
}