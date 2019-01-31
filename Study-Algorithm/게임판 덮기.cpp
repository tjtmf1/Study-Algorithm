//https://algospot.com/judge/problem/read/BOARDCOVER
#include <iostream>
#include <vector>
using namespace std;
bool block[4][2][2] = {
	{ 0,1,1,1 },{ 1,0,1,1 },{ 1,1,0,1 },{ 1,1,1,0 }
};
vector<vector<bool>> map;
int h, w;
int answer;
bool canPutIn(int x, int y, int blockType)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (block[blockType][i][j] && !map[y + i][x + j])
				return false;
		}
	}
	return true;
}
void setMap(int x, int y, int blockType, int value)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (block[blockType][i][j])
				map[y + i][x + j] = value;
		}
	}
}
bool checkAllClear()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (map[i][j])
				return false;
		}
	}
	return true;
}
void dfs(int x, int y)
{
	if (y == h)
	{
		if (checkAllClear())
			answer++;
		return;
	}
	if (!map[y][x])
	{
		dfs((x + 1) % w, y + (x + 1) / w);
		if (canPutIn(x, y, 0))
		{
			setMap(x, y, 0, false);
			dfs((x + 1) % w, y + (x + 1) / w);
			setMap(x, y, 0, true);
		}
	}
	else
		for (int i = 1; i < 4; i++)
		{
			if (canPutIn(x, y, i))
			{
				setMap(x, y, i, false);
				dfs((x + 1) % w, y + (x + 1) / w);
				setMap(x, y, i, true);
			}
		}
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> h >> w;
		map = vector<vector<bool>>(h + 1, vector<bool>(w + 1, false));
		answer = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				char ch;
				cin >> ch;
				if (ch == '#')
				{
					map[i][j] = false;
				}
				else if (ch == '.')
				{
					map[i][j] = true;
				}
			}
		}
		dfs(0, 0);
		cout << answer << endl;
	}
	return 0;
}