//https://algospot.com/judge/problem/read/LIS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		vector<int> temp(1, -1);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (temp.back() < arr[i])
				temp.push_back(arr[i]);
			else
				*lower_bound(temp.begin(), temp.end(), arr[i]) = arr[i];
		}
		cout << temp.size() - 1 << endl;
	}
	return 0;
}