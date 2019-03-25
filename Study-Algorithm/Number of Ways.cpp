//http://codeforces.com/problemset/problem/466/C
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<long long> accSum(n);
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
		accSum[i] = sum;
	}
	if (sum % 3 != 0)
	{
		cout << 0 << endl;
		return 0;
	}
	sum /= 3;
	long long cnt = 0;
	long long answer = 0;
	for (int i = 0; i < n; i++)
	{
		if (accSum[i] == sum)
			cnt++;
		if (accSum[i] == sum * 2)
			answer += cnt;
	}
	if (sum == 0)
		cout << ((cnt - 1) * (cnt - 2)) / 2 << endl;
	else
		cout << answer << endl;
	return 0;
}