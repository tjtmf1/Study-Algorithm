//http://codeforces.com/problemset/problem/510/B

#include <iostream>
#include <stack>
#include <list>
using namespace std;
class point
{
public:
	int x, y;

	point() {}
	point(int input_y, int input_x)
	{
		x = input_x;
		y = input_y;
	}
	point operator=(point p)
	{
		x = p.x;
		y = p.y;
	}
	bool operator==(point p)
	{
		if (x == p.x && y == p.y)
			return true;
		else
			return false;
	}
};
char **map;
bool **check;
int n, m;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool is_cycle = false;
stack<point> st;
list<int> li;
void Exit()
{
	for (int i = 0; i < n + 2; i++)
	{
		delete[] map[i];
		delete[] check[i];
	}
	delete[] map;
	delete[] check;
	if (is_cycle)
	{
		cout << "Yes";
	}
	else
		cout << "No";
	return;
}

int main(void)
{

	cin >> n >> m;
	map = new char*[n + 2];
	check = new bool*[n + 2];
	for (int i = 0; i < n + 2; i++)
	{
		map[i] = new char[m + 2];
		check[i] = new bool[m + 2];
	}
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
			{
				check[i][j] = true;
				map[i][j] = 0;
				continue;
			}
			cin >> map[i][j];
			check[i][j] = false;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			if (!check[i][j])
			{
				check[i][j] = true;
				for (int k = 0; k < 4; k++)
				{
					if (!check[i + dy[k]][j + dx[k]] && map[i + dy[k]][j + dx[k]] == map[i][j])
					{
						st.push(point(i + dy[k], j + dx[k]));
					}
				}
				li.push_back(i*m + j);
				while (!st.empty())
				{
					point cur = st.top();
					st.pop();
					check[cur.y][cur.x] = true;
					for (int k = 0; k < 4; k++)
					{
						if (!check[cur.y + dy[k]][cur.x + dx[k]] && map[cur.y + dy[k]][cur.x + dx[k]] == map[i][j])
						{
							st.push(point(cur.y + dy[k], cur.x + dx[k]));
						}
					}
					li.push_back(cur.y * m + cur.x);
				}
				li.sort();
				int before = li.size();
				li.unique();
				if (before - li.size() > 0)
				{
					is_cycle = true;
					Exit();
					return 0;
				}
			}
		}
	}
	Exit();
	return 0;
}