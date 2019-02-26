//https://www.acmicpc.net/problem/15683
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int> > map;
vector<pair<int, int> > cctv;
int cnt;
void setMapDir(int y, int x, int dir, int val)
{
	switch (dir)
	{
	case 0:
		for (int i = x; i < m; i++)
		{
			if (map[y][i] == 6)
				break;
			if (map[y][i] <= 0)
				map[y][i] -= val;
		}
		break;
	case 1:
		for (int i = y; i < n; i++)
		{
			if (map[i][x] == 6)
				break;
			if (map[i][x] <= 0)
				map[i][x] -= val;
		}
		break;
	case 2:
		for (int i = x; i >= 0; i--)
		{
			if (map[y][i] == 6)
				break;
			if (map[y][i] <= 0)
				map[y][i] -= val;
		}
		break;
	case 3:
		for (int i = y; i >= 0; i--)
		{
			if (map[i][x] == 6)
				break;
			if (map[i][x] <= 0)
				map[i][x] -= val;
		}
		break;
	}
}
void setMap(int y, int x, int type, int dir, int val)
{
	switch (type)
	{
	case 1:
		setMapDir(y, x, dir, val);
		break;
	case 2:
		setMapDir(y, x, dir, val);
		setMapDir(y, x, (dir + 2) % 4, val);
		break;
	case 3:
		setMapDir(y, x, dir, val);
		setMapDir(y, x, (dir + 1) % 4, val);
		break;
	case 4:
		setMapDir(y, x, dir, val);
		setMapDir(y, x, (dir + 1) % 4, val);
		setMapDir(y, x, (dir + 2) % 4, val);
		break;
	case 5:
		setMapDir(y, x, dir, val);
		setMapDir(y, x, (dir + 1) % 4, val);
		setMapDir(y, x, (dir + 2) % 4, val);
		setMapDir(y, x, (dir + 3) % 4, val);
		break;
	}
}
void dfs(int num)
{
	if (num == cctv.size())
	{
		int value = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 0)
					value++;
		if (value < cnt)
			cnt = value;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		setMap(cctv[num].first, cctv[num].second, map[cctv[num].first][cctv[num].second], i, 1);
		dfs(num + 1);
		setMap(cctv[num].first, cctv[num].second, map[cctv[num].first][cctv[num].second], i, -1);
	}
}
int main(void)
{
	cin >> n >> m;
	map = vector<vector<int> >(n, vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
			{
				cctv.push_back(make_pair(i, j));
			}
		}
	}
	cnt = n * m;
	dfs(0);
	cout << cnt << endl;
	return 0;
}