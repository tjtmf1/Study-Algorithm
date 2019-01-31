//http://codeforces.com/problemset/problem/519/B
#include <iostream>
using namespace std;

int main(void)
{
	int n, *a, *b, *c;
	cin >> n;

	a = new int[n];
	b = new int[n - 1];
	c = new int[n - 2];

	for (int i = 0; i<n; i++)
		cin >> a[i];
	for (int i = 0; i<n - 1; i++)
		cin >> b[i];
	for (int i = 0; i<n - 2; i++)
		cin >> c[i];

	int mask = 0;

	for (int i = 0; i<n; i++)
		mask ^= a[i];
	for (int i = 0; i<n - 1; i++)
		mask ^= b[i];

	cout << mask;
	mask = 0;
	for (int i = 0; i<n - 1; i++)
		mask ^= b[i];
	for (int i = 0; i<n - 2; i++)
		mask ^= c[i];

	cout << " " << mask;

	return 0;
}