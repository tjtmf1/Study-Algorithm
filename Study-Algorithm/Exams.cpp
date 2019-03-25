//http://codeforces.com/problemset/problem/479/C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	sort(v.begin(), v.end());
	int answer = min(v[0].first, v[0].second);
	for (int i = 1; i < n; i++)
	{
		if (v[i].second >= answer)
			answer = v[i].second;
		else
			answer = v[i].first;
	}
	cout << answer << endl;
	return 0;
}