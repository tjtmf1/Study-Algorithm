//https://www.acmicpc.net/problem/14003
#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int *num = new int[n];
	int *arr = new int[n];
	int *arrIndex = new int[n];
	int size = 0;
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++)
	{
		if (size == 0 || arr[size - 1] < num[i])
		{
			arr[size] = num[i];
			arrIndex[i] = size;
			size++;
		}
		else
		{
			int low = 0, high = size - 1;
			int index = (low + high) / 2;
			while (low <= high)
			{
				if (arr[index] < num[i])
					low = index + 1;
				else if (arr[index] > num[i])
					high = index - 1;
				else
					break;
				index = (low + high) / 2;
			}
			if (arr[index] < num[i])
				index++;
			arrIndex[i] = index;
			arr[index] = num[i];
		}
	}
	//cout << size << endl;
	int value = size - 1;
	int *seq = new int[size];
	for (int i = n - 1; i >= 0; i--)
	{
		if (arrIndex[i] == value)
		{
			seq[value] = num[i];
			value--;
			if (value < 0)
				break;
		}
	}
	cout << size << endl;
	for (int i = 0; i < size; i++)
		cout << seq[i] << " ";

	delete[] seq;
	delete[] num;
	delete[] arr;
	delete[] arrIndex;
	return 0;
}