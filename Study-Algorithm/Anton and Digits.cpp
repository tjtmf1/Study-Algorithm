//http://codeforces.com/problemset/problem/734/B
#include <iostream>
using namespace std;

int main(void)
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int sum = 0;
	while (a>0 & c>0 & d>0)
	{
		sum += 256;
		a--;
		c--;
		d--;
	}

	while (a>0 & b>0)
	{
		sum += 32;
		a--;
		b--;
	}

	cout << sum;
	return 0;
}