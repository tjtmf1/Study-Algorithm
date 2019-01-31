//http://codeforces.com/problemset/problem/189/A
#include <iostream>
#include <queue>
using namespace std;
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}
int QuickSort(int *num, int left, int right)
{
	if (left >= right)
		return 0;

	int pivot = left;
	int l = left + 1, r = right;

	while (l <= r)
	{
		if ((num[l] > num[pivot]) && (num[r] < num[pivot]))
		{
			Swap(num[l], num[r]);
		}

		if (num[l] <= num[pivot])
			l++;
		if (num[r] >= num[pivot])
			r--;

	}
	Swap(num[pivot], num[r]);

	QuickSort(num, left, r - 1);
	QuickSort(num, r + 1, right);

	return 1;
}
int main(void)
{
	int n, num[3];
	int max = 0;
	cin >> n >> num[0] >> num[1] >> num[2];
	QuickSort(num, 0, 2);
	for (int i = n / num[0]; i >= 0; i--)
	{
		for (int j = (n - i * num[0]) / num[1]; j >= 0; j--)
		{
			for (int k = (n - i * num[0] - j * num[1]) / num[2]; k >= 0; k--)
			{
				if (i + j + k <= max)
					break;
				if (i*num[0] + j * num[1] + k * num[2] == n)
					max = i + j + k;
			}
		}
	}
	cout << max << endl;
	return 0;
}