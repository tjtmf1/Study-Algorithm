//http://codeforces.com/problemset/problem/545/C
#include <iostream>
using namespace std;
int main(void)
{
	int n;
	int x[100000], h[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> h[i];
	int count = 1;
	int last_pos = x[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (x[i] - h[i] > last_pos)
		{
			count++;
			last_pos = x[i];
			continue;
		}
		else if (x[i] + h[i] < x[i + 1])
		{
			count++;
			last_pos = x[i] + h[i];
			continue;
		}
		last_pos = x[i];
	}
	if (last_pos < x[n - 1])
		count++;
	cout << count << endl;

	return 0;
}