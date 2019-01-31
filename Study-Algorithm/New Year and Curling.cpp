//http://codeforces.com/contest/908/problem/C
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
	int n, r;
	cin >> n >> r;
	int x[1000];
	double y[1000] = { r };
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 1; i < n; i++)
	{
		vector<int> v;
		double max = r;
		for (int j = 0; j < i; j++)
		{
			if (abs(x[i] - x[j]) <= 2 * r)
				v.push_back(j);
		}
		while (v.size() != 0)
		{
			int search = v.back();
			v.pop_back();
			double height = abs(sqrt(4 * r*r - (x[search] - x[i])*(x[search] - x[i])) + y[search]);
			if (height > max)
				max = height;
		}
		y[i] = max;
	}
	cout.precision(11);
	cout << fixed;
	for (int i = 0; i < n; i++)
		cout << y[i] << " ";
	return 0;
}