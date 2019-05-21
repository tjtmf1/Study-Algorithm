//http://codeforces.com/contest/1141/problem/E
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	long long H;
	int n;
	cin >> H >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++)
		cin >> d[i];
	long long sum = 0, min = 0;
	for (int i = 0; i < n; i++)
	{
		sum += d[i];
		if (sum < min)
			min = sum;
	}
	if (sum >= 0 && -H < min)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		long long answer = 0;
		if (H > -min)
		{
			answer = ((H + min) / -sum) + (bool)((H + min) % -sum);
			H += answer * sum;
			answer *= n;
		}
		for (int i = 0; H > 0; i++)
		{
			H += d[i];
			answer++;
		}
		cout << answer << endl;
	}
	return 0;
}