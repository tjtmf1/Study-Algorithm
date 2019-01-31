//http://codeforces.com/problemset/problem/467/B

#include <iostream>
#include <string>
using namespace std;
string binary_expression(int num, int n)
{
	string str = "";
	while (num)
	{
		switch (num % 2)
		{
		case 0:
			str.insert(0, "0");
			break;
		case 1:
			str.insert(0, "1");
			break;
		}
		num /= 2;
	}
	for (int i = str.length(); i < n; i++)
	{
		str.insert(0, "0");
	}
	return str;
}

int binary_difference(string a, string b)
{
	int dif = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i])
			dif++;
	}


	return dif;
}

int main(void)
{
	int n, m = 0, k = 0;
	int fri = 0;
	cin >> n >> m >> k;
	int *army = new int[m];
	int fedor_army;
	for (int i = 0; i < m; i++)
		cin >> army[i];
	cin >> fedor_army;

	for (int i = 0; i < m; i++)
	{
		if (binary_difference(binary_expression(army[i], n), binary_expression(fedor_army, n)) <= k)
			fri++;
	}
	cout << fri;
	cin >> fri;

	return 0;
}