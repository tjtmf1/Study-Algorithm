//http://codeforces.com/problemset/problem/476/B

#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int factorial(int n)
{
	int value = 1;
	for (int i = n; i >= 1; i--)
		value *= i;
	return value;
}
void getCount(string str, int *plus, int *minus, int *unknown)
{
	int p = 0, m = 0, u = 0;
	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '+':
			p++;
			break;
		case '-':
			m++;
			break;
		case '?':
			u++;
			break;
		}
	}
	*plus = p;
	*minus = m;
	*unknown = u;
}
int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	int plus, minus, unknown;
	int correct;
	getCount(str1, &plus, &minus, &unknown);
	correct = plus - minus;
	getCount(str2, &plus, &minus, &unknown);
	int temp = correct - (plus - minus);
	if (unknown == 0)
	{
		if (temp == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
		return 0;
	}
	int k = (temp + unknown) / 2;
	cout.precision(12);
	cout << fixed << factorial(unknown) / factorial(unknown - k) / factorial(k) * pow(0.5, unknown) << endl;
	return 0;
}