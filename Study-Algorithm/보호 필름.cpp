//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu&categoryId=AV5V1SYKAaUDFAWu&categoryType=CODE
#include <iostream>
#include <vector>
using namespace std;
class c
{
public:
	int position, value;
	c(int _position, int _value)
	{
		position = _position;
		value = _value;
	}
	void operator=(c n)
	{
		position = n.position;
		value = n.value;
	}
};
int	d, w, k, test;
int solution[100];
int film[13][20];

bool testing()
{
	for (int i = 0; i < w; i++)
	{
		int cnt = 1;
		int cur = film[0][i];
		for (int j = 1; j < d; j++)
		{
			if (film[j][i] == cur)
			{
				cnt++;
				if (cnt == k)
					break;
			}
			else
			{
				cnt = 1;
				cur = film[j][i];
				if (d - j < k)
					j = d - 1;
			}
			if (j == d - 1)
			{
				return false;
			}
		}
	}
	return true;
}
void dfs(int depth, int cnt, bool pass = false)
{
	int temp[20];
	if (solution[test] <= cnt)
		return;
	if (!pass && testing())
	{
		solution[test] = cnt;
	}
	if (depth >= d)
		return;
	for (int i = 0; i < w; i++)
	{
		temp[i] = film[depth][i];
		film[depth][i] = 0;
	}
	dfs(depth + 1, cnt + 1);
	for (int i = 0; i < w; i++)
	{
		film[depth][i] = 1;
	}
	dfs(depth + 1, cnt + 1);
	for (int i = 0; i < w; i++)
		film[depth][i] = temp[i];
	dfs(depth + 1, cnt, true);
}
int main(void)
{
	int t;
	cin >> t;
	for (test = 0; test < t; test++)
	{
		cin >> d >> w >> k;
		solution[test] = k;
		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
				cin >> film[i][j];
		if (k == 1)
		{
			solution[test] = 0;
			continue;
		}
		dfs(0, 0);
	}
	for (int i = 0; i < t; i++)
		cout << "#" << i + 1 << " " << solution[i] << endl;
	return 0;
}