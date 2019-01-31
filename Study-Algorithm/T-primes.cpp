//http://codeforces.com/problemset/problem/230/B
#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	long long n, *x;
	cin >> n;
	x = new long long[n];
	for (int i = 0; i<n; i++)
		cin >> x[i];
	for (int i = 0; i<n; i++)
	{
		if (x[i] == 1)
		{
			cout << "NO" << endl;
			continue;
		}
		if (sqrt(x[i]) - (int)sqrt(x[i]) > 0)
		{
			cout << "NO" << endl;
			continue;
		}
		else
		{
			bool chk = true;
			int num = sqrt(x[i]);
			for (int j = 2; j <= sqrt(num); j++)
			{
				if (num % j == 0)
				{
					cout << "NO" << endl;
					chk = false;
					break;
				}
			}
			if (chk)
				cout << "YES" << endl;

		}
	}
	return 0;
}