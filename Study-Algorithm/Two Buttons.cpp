//http://codeforces.com/problemset/problem/520/B
#include <iostream>
using namespace std;
int main(void)
{
	int a, b;
	cin >> a >> b;
	int cnt = 0;
	while (a != b)
	{
		cnt++;
		if (a < b && (b % 2 == 0))
			b /= 2;
		else
			b++;
	}
	cout << cnt << endl;
	return 0;
}