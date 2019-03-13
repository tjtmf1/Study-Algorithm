//https://www.acmicpc.net/problem/13458
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int b, c;
	cin >> b >> c;

	long long cnt = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] -= b;
		cnt += 1;
		if (a[i] > 0)
			cnt += a[i] / c + !!(a[i] % c);
	}
	cout << cnt << endl;
	return 0;
}