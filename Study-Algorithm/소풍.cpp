//https://algospot.com/judge/problem/read/PICNIC
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<bool>> v;
vector<bool> person;
int answer;
void dfs(int num)
{
	if (num == n)
	{
		answer++;
		return;
	}
	if (person[num])
	{
		dfs(num + 1);
	}
	else
	{
		for (int i = num + 1; i < n; i++)
		{
			if (v[num][i] && !person[i])
			{
				person[i] = true;
				dfs(num + 1);
				person[i] = false;
			}
		}
	}
}
int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		answer = 0;
		cin >> n >> m;
		person = vector<bool>(n, false);
		v = vector<vector<bool>>(n, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			v[a][b] = true;
			v[b][a] = true;
		}
		dfs(0);
		cout << answer << endl;
	}

	return 0;
}