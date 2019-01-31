//http://codeforces.com/problemset/problem/492/B
#include<iostream>
using namespace std;


void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}
int main(void)
{

	int n, l, *a;
	cin >> n >> l;
	a = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i<n; i++)
	{
		int min = i;
		for (int j = i; j<n; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		swap(a[i], a[min]);
	}
	int max;
	if (a[0] != 0)
		max = a[0] * 2;
	if ((a[n - 1] != l)&(max < (l - a[n - 1]) * 2))
		max = (l - a[n - 1]) * 2;
	for (int i = 1; i<n; i++)
	{
		if (a[i] - a[i - 1] > max)
			max = a[i] - a[i - 1];
	}

	cout.precision(10);
	cout << fixed << max / 2.0;


	return 0;

}