//http://codeforces.com/contest/1141/problem/B
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
	a.insert(a.end(), a.begin(), a.end());
	a.push_back(0);
	int cnt = 0;
	int max = 0;
	for (int i = 0; i < a.size(); i++)
	{
		switch (a[i])
		{
		case 0:
			if (max < cnt)
				max = cnt;
			cnt = 0;
			break;
		case 1:
			cnt++;
			break;
		}
	}
	cout << max << endl;
	return 0;
}