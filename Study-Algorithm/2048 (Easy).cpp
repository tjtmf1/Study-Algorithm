//https://www.acmicpc.net/problem/12100
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int n;
int answer = 0;
enum {UP, DOWN, LEFT, RIGHT};
void dfs(vector<vector<int> > m, int dir, int cnt)
{
	if (cnt == 5)
	{
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (max < m[i][j])
					max = m[i][j];
			}
		}
		if (max > answer)
			answer = max;
		return;
	}
	stack<int> s;
	queue<int> q;
	vector<vector<int> > newMap(n, vector<int>(n, 0));
	switch (dir)
	{
	case UP:
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				q.push(m[j][i]);
			}
			int index = 0;
			int last = -1;
			while (!q.empty())
			{
				int num = q.front();
				q.pop();
				if (num == 0)
					continue;
				if (num == last)
				{
					newMap[index - 1][i] *= 2;
					last = -1;
				}
				else
				{
					newMap[index][i] = num;
					last = num;
					index++;
				}
			}
		}
		break;
	case DOWN:
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				s.push(m[j][i]);
			}
			int index = n - 1;
			int last = -1;
			while (!s.empty())
			{
				int num = s.top();
				s.pop();
				if (num == 0)
					continue;
				if (num == last)
				{
					newMap[index + 1][i] *= 2;
					last = -1;
				}
				else
				{
					newMap[index][i] = num;
					last = num;
					index--;
				}
			}
		}
		break;
	case LEFT:
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				q.push(m[i][j]);
			}
			int index = 0;
			int last = -1;
			while (!q.empty())
			{
				int num = q.front();
				q.pop();
				if (num == 0)
					continue;
				if (num == last)
				{
					newMap[i][index - 1] *= 2;
					last = -1;
				}
				else
				{
					newMap[i][index] = num;
					last = num;
					index++;
				}
			}
		}
		break;
	case RIGHT:
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				s.push(m[i][j]);
			}
			int index = n - 1;
			int last = -1;
			while (!s.empty())
			{
				int num = s.top();
				s.pop();
				if (num == 0)
					continue;
				if (num == last)
				{
					newMap[i][index + 1] *= 2;
					last = -1;
				}
				else
				{
					newMap[i][index] = num;
					last = num;
					index--;
				}
			}
		}
		break;
	}

	for (int i = 0; i < 4; i++)
		dfs(newMap, i, cnt + 1);

}

int main(void)
{
	cin >> n;
	vector<vector<int> > map(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
		dfs(map, i, 0);
	cout << answer << endl;
	return 0;
}