//https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;

int n;
int **map;
int cnt = 0;
void setMap(int x, int y, bool plus)
{
	int value;
	if (plus)
		value = 1;
	else
		value = -1;
	for (int i = 1; y + i < n; i++)
		map[y + i][x] += value;
	for (int i = 1; (x + i < n) && (y + i < n); i++)
		map[y + i][x + i] += value;
	for (int i = 1; (x - i >= 0) && (y + i < n); i++)
		map[y + i][x - i] += value;
}
void dfs(int x, int y, int queen)
{
	if (y == n || queen < y)
	{
		return;
	}
	dfs((x + 1) % n, y + (x + 1) / n, queen);
	if (map[y][x] == 0)
	{
		if (queen == n - 1)
		{
			cnt++;
			return;
		}
		setMap(x, y, true);
		dfs(0, y + 1, queen + 1);
		setMap(x, y, false);
	}
}
int main(void)
{
	cin >> n;
	map = new int*[n];
	for (int i = 0; i < n; i++)
	{
		map[i] = new int[n];
		for (int j = 0; j < n; j++)
			map[i][j] = 0;
	}
	dfs(0, 0, 0);
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		delete[] map[i];
	delete[] map;
	return 0;
}