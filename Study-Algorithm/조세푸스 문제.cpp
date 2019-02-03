//https://algospot.com/judge/problem/read/JOSEPHUS
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, k;
		cin >> n >> k;
		queue<int> q;
		for (int i = 0; i < n; i++)
			q.push(i + 1);
		int cnt = k;
		while (n != 2)
		{
			if (cnt == k)
			{
				cnt = 1;
				q.pop();
				n--;
			}
			else
			{
				cnt++;
				q.push(q.front());
				q.pop();
			}
		}
		int a = q.front();
		q.pop();
		int b = q.front();
		if (a < b)
			cout << a << " " << b << endl;
		else
			cout << b << " " << a << endl;
	}
	return 0;
}