//http://codeforces.com/problemset/problem/339/D
#include <iostream>
#include <cmath>
using namespace std;
void cal(int *a, int index, int size, int height)
{
	if (index * 2 < size)
	{
		cal(a, index * 2, size, height + 1);
		cal(a, index * 2 + 1, size, height + 1);
	}
	if (height % 2 == 0)
	{
		//XOR
		a[index] = a[index * 2] ^ a[index * 2 + 1];
	}
	else
	{
		//OR
		a[index] = a[index * 2] | a[index * 2 + 1];
	}
}

void cal2(int *a, int index)
{
	bool flagOR = true;
	while (index /= 2)
	{
		if (flagOR)
			a[index] = a[index * 2] | a[index * 2 + 1];
		else
			a[index] = a[index * 2] ^ a[index * 2 + 1];
		flagOR = !flagOR;
	}
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	int *a = new int[(int)pow(2.0, (double)(n + 1))];

	for (int i = pow(2.0, (double)n); i < (int)pow(2.0, (double)(n + 1)); i++)
	{
		cin >> a[i];
	}
	cal(a, 1, (int)pow(2.0, (double)n), n % 2);

	for (int i = 0; i < m; i++)
	{
		int p, b;
		cin >> p >> b;
		int index = (int)pow(2.0, (double)n) + p - 1;
		if (a[index] == b)
		{
			cout << a[1] << endl;
			continue;
		}
		a[index] = b;
		cal2(a, index);
		cout << a[1] << endl;
	}
	delete[] a;
	return 0;
}