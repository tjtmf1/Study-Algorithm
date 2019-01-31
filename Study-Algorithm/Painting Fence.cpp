//https://codeforces.com/problemset/problem/448/C
#include <iostream>
using namespace std;
int minHeight(int *arr, int cnt)
{
	int minValue = arr[0];
	for (int i = 1; i < cnt; i++)
		if (minValue > arr[i])
			minValue = arr[i];
	return minValue;
}
int recursive(int *arr, int cnt)
{
	if (cnt == 1)
		return 1;
	int minValue = minHeight(arr, cnt);
	int rest = 0;
	int count = 0;
	int start = 0;
	for (int i = 0; i < cnt; i++)
	{
		arr[i] -= minValue;
		if (arr[i] == 0)
		{
			if (count == 0)
			{
				start = i + 1;
				continue;
			}
			else
			{
				rest += recursive(arr + start, count);
				start = i + 1;
				count = 0;
			}
		}
		else
			count++;
	}
	if (count != 0)
		rest += recursive(arr + start, count);
	if (minValue + rest < cnt)
		return minValue + rest;
	else
		return cnt;
}
int main(void)
{
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << recursive(a, n) << endl;
	delete[] a;
	return 0;
}