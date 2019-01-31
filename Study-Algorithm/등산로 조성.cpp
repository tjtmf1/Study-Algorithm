//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq&categoryId=AV5PoOKKAPIDFAUq&categoryType=CODE

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int **map;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
priority_queue<int> *dis;
vector<int> ans;
class Point
{
public:
	int x, y;
	Point() {};
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
	void operator= (const Point &p)
	{
		x = p.x;
		y = p.y;
	}
};
void dfs(int y, int x, int value, int k, int d, vector<Point> v)
{
	bool chk = false;
	for (int i = 0; i < 4; i++)
	{
		bool chk2 = false;
		for (int j = 0; j < v.size(); j++)
		{
			if (y + dy[i] == v[j].y && x + dx[i] == v[j].x)
			{
				chk2 = true;
				break;
			}
		}
		if (chk2)
			continue;
		if (value > map[y + dy[i]][x + dx[i]])
		{
			vector<Point> new_v = v;
			new_v.push_back(Point(x + dx[i], y + dy[i]));
			dfs(y + dy[i], x + dx[i], map[y + dy[i]][x + dx[i]], k, d + 1, new_v);
			chk = true;
		}
		else if (k > map[y + dy[i]][x + dx[i]] - value)
		{
			vector<Point> new_v = v;
			new_v.push_back(Point(x + dx[i], y + dy[i]));
			dfs(y + dy[i], x + dx[i], value - 1, 0, d + 1, new_v);
			chk = true;
		}
	}
	if (!chk)
		dis->push(d);
}
vector<Point> v;
int main(void)
{
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		dis = new priority_queue<int>;
		int n, k;
		cin >> n >> k;
		map = new int*[n + 2];
		for (int i = 0; i < n + 2; i++)
		{
			map[i] = new int[n + 2];
		}
		priority_queue<int> *heap = new priority_queue<int>;
		for (int i = 0; i < n + 2; i++)
		{
			for (int j = 0; j < n + 2; j++)
			{
				if (i == 0 || j == 0 || i == n + 1 || j == n + 1)
				{
					map[i][j] = 30;
					continue;
				}
				cin >> map[i][j];
				heap->push(map[i][j]);
			}
		}
		int max = heap->top();
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 0; j < n + 1; j++)
			{
				if (map[i][j] == max)
					v.push_back(Point(j, i));
			}
		}
		delete heap;
		for (int i = 0; i < v.size(); i++)
		{
			vector<Point> new_v;
			new_v.push_back(Point(v[i].x, v[i].y));
			dfs(v[i].y, v[i].x, map[v[i].y][v[i].x], k, 1, new_v);
		}
		ans.push_back(dis->top());
		delete dis;
		for (int i = 0; i < n + 2; i++)
			delete[] map[i];
		delete[] map;
		v.clear();
	}
	for (int i = 0; i < t; i++)
	{
		cout << "#" << i + 1 << " " << ans[i] << endl;
	}
	return 0;
}