//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf&categoryId=AV4suNtaXFEDFAUf&categoryType=CODE

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
void dfs(int **map, int num, int connected, int cost);
class core
{
public:
	int connect;
	int cost;
	core() {}
	core(int _connect, int _cost)
	{
		connect = _connect;
		cost = _cost;
	}
	void operator=(const core &c1)
	{
		connect = c1.connect;
		cost = c1.cost;
	}
	bool operator<(const core &c) const
	{
		if (connect < c.connect)
			return true;
		else if (connect > c.connect)
			return false;
		else
			return cost > c.cost;
	}
};
int n;
vector<int> *x;
vector<int> *y;
priority_queue<core> *q;
vector<int> answer;
int main(void)
{
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		cin >> n;
		int **map = new int*[n + 2];
		for (int i = 0; i < n + 2; i++)
			map[i] = new int[n + 2];
		x = new vector<int>;
		y = new vector<int>;
		q = new priority_queue<core>;
		for (int i = 0; i < n + 2; i++)
		{
			for (int j = 0; j < n + 2; j++)
			{
				if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
					map[i][j] = -1;
				else
					cin >> map[i][j];
				if (map[i][j] == 1)
				{
					x->push_back(j);
					y->push_back(i);
				}
			}
		}
		dfs(map, 0, 0, 0);
		answer.push_back(q->top().cost);
		delete x;
		delete y;
		delete q;
		for (int i = 0; i < n + 2; i++)
			delete[] map[i];
		delete[] map;
	}
	for (int i = 1; i <= t; i++)
		cout << "#" << i << " " << answer[i - 1] << endl;
	return 0;
}
bool con_possible(int **map, int x, int y, int dir)
{
	switch (dir)
	{
	case UP:
		for (int i = y - 1; i > 0; i--)
		{
			if (map[i][x] != 0)
				return false;
		}
		return true;
		break;
	case DOWN:
		for (int i = y + 1; i < n + 1; i++)
		{
			if (map[i][x] != 0)
				return false;
		}
		return true;
		break;
	case LEFT:
		for (int i = x - 1; i > 0; i--)
		{
			if (map[y][i] != 0)
				return false;
		}
		return true;
		break;
	case RIGHT:
		for (int i = x + 1; i < n + 1; i++)
		{
			if (map[y][i] != 0)
				return false;
		}
		return true;
		break;
	}
}
void dfs(int **map, int num, int connected, int cost)
{
	if (num >= n)
	{
		q->push(core(connected, cost));
		return;
	}
	if (x->at(num) == 1 || x->at(num) == n || y->at(num) == 1 || y->at(num) == n)
	{
		dfs(map, num + 1, connected + 1, cost);
		return;
	}
	int **new_map = new int*[n + 2];
	for (int i = 0; i < n + 2; i++)
		new_map[i] = new int[n + 2];
	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < n + 2; j++)
			new_map[i][j] = map[i][j];
	dfs(new_map, num + 1, connected, cost);
	if (con_possible(map, x->at(num), y->at(num), UP))
	{
		for (int i = y->at(num) - 1; i > 0; i--)
			new_map[i][x->at(num)] = 1;
		dfs(new_map, num + 1, connected + 1, cost + y->at(num) - 1);
		for (int i = y->at(num) - 1; i > 0; i--)
			new_map[i][x->at(num)] = 0;
	}
	if (con_possible(map, x->at(num), y->at(num), DOWN))
	{
		for (int i = y->at(num) + 1; i < n + 1; i++)
			new_map[i][x->at(num)] = 1;
		dfs(new_map, num + 1, connected + 1, cost + n - y->at(num));
		for (int i = y->at(num) + 1; i < n + 1; i++)
			new_map[i][x->at(num)] = 0;
	}
	if (con_possible(map, x->at(num), y->at(num), LEFT))
	{
		for (int i = x->at(num) - 1; i > 0; i--)
			new_map[y->at(num)][i] = 1;
		dfs(new_map, num + 1, connected + 1, cost + x->at(num) - 1);
		for (int i = x->at(num) - 1; i > 0; i--)
			new_map[y->at(num)][i] = 0;
	}
	if (con_possible(map, x->at(num), y->at(num), RIGHT))
	{
		for (int i = x->at(num) + 1; i < n + 1; i++)
			new_map[y->at(num)][i] = 1;
		dfs(new_map, num + 1, connected + 1, cost + n - x->at(num));
		for (int i = x->at(num) + 1; i < n + 1; i++)
			new_map[y->at(num)][i] = 0;
	}
	for (int i = 0; i < n + 2; i++)
		delete[] new_map[i];
	delete[] new_map;
}