//http://codeforces.com/contest/1141/problem/A
#include <iostream>
using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	if (m % n != 0)
	{
		cout << -1 << endl;
		return 0;
	}
	m /= n;
	int cnt = 0;
	while (m != 1)
	{
		if (m % 2 == 0)
		{
			cnt++;
			m /= 2;
		}
		else if (m % 3 == 0)
		{
			cnt++;
			m /= 3;
		}
		else
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << cnt << endl;
	return 0;
}