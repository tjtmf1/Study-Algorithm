//https://algospot.com/judge/problem/read/ITES
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(void)
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int k, n;
		cin >> k >> n;
		int cnt = 0;
		int sum = 0;
		unsigned int seed = 1983;
		queue<int> q;
		for (int i = 0; i < n;)
		{
			if (sum < k)
			{
				q.push(seed % 10000 + 1);
				i++;
				seed = seed * 214013u + 2531011u;
				sum += q.back();
			}
			else if (sum > k)
			{
				sum -= q.front();
				q.pop();
			}
			else
			{
				cnt++;
				sum -= q.front();
				q.pop();
			}
		}
		if (sum == k)
			cnt++;
		cout << cnt << endl;
	}

	return 0;
}