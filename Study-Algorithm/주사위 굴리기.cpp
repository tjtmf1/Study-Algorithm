//https://www.acmicpc.net/problem/14499
#include <iostream>
#include <vector>
using namespace std;
enum{EAST = 1, WEST, NORTH, SOUTH};
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void rotate(int &up, int &front, int &left, int dir)
{
	int temp = up;
	switch (dir)
	{
	case EAST:
		up = left;
		left = 5 - temp;
		break;
	case WEST:
		up = 5 - left;
		left = temp;
		break;
	case NORTH:
		up = front;
		front = 5 - temp;
		break;
	case SOUTH:
		up = 5 - front;
		front = temp;
		break;
	}
}
int main(void)
{
	int n, m, x, y, k;
	cin >> n >> m >> y >> x >> k;
	vector<vector<int> > map(n, vector<int>(m));
	vector<int> dice(6);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 6; i++)
		dice[i] = 0;
	int upIndex = 0;
	int frontIndex = 4;
	int leftIndex = 3;
	dice[5 - upIndex] = map[y][x];
	map[y][x] = 0;
	for (int i = 0; i < k; i++)
	{
		int query;
		cin >> query;
		if (x + dx[query - 1] < 0 || x + dx[query - 1] >= m || y + dy[query - 1] < 0 || y + dy[query - 1] >= n)
			continue;
		x += dx[query - 1];
		y += dy[query - 1];
		rotate(upIndex, frontIndex, leftIndex, query);
		if (map[y][x] == 0)
		{
			map[y][x] = dice[5 - upIndex];
		}
		else
		{
			dice[5 - upIndex] = map[y][x];
			map[y][x] = 0;
		}
		cout << dice[upIndex] << endl;
	}
	return 0;
}