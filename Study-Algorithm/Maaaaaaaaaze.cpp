//https://www.acmicpc.net/problem/16985
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > plate[5][4];
vector<vector<vector<int> >*> maze(7);
int answer = 987654321;
int d[2] = { 1, -1 };
void dfs(int z, int y, int x, int step)
{
	if (15 - z - y - x + step >= answer)
		return;
	if (z == 5 && y == 5 && x == 5)
	{
		if (step < answer)
			answer = step;
		return;
	}

	maze[z]->at(y)[x] = -1;
	for (int i = 0; i < 2; i++)
	{
		if (maze[z + d[i]]->at(y)[x] == 1)
		{
			dfs(z + d[i], y, x, step + 1);
		}
		if (maze[z]->at(y + d[i])[x] == 1)
		{
			dfs(z, y + d[i], x, step + 1);
		}
		if (maze[z]->at(y)[x + d[i]] == 1)
		{
			dfs(z, y, x + d[i], step + 1);
		}
	}
	maze[z]->at(y)[x] = 1;
}
void solve()
{
	vector<int> arr(5);
	for (int i = 0; i < 5; i++)
		arr[i] = i;
	vector<vector<int> > wall(7, vector<int>(7, 0));
	maze[0] = &wall;
	maze[6] = &wall;
	do
	{
		for (int i = 0; i < 1024; i++)
		{
			int num = i;
			for (int j = 0; j < 5; j++)
			{
				maze[j + 1] = &plate[arr[j]][num % 4];
				num /= 4;
			}
			if (maze[1]->at(1)[1] == 1 && maze[5]->at(5)[5] == 1)
			{
				bool flag = false;
				for (int k = 1; k < 5; k++)
				{
					int sum = 0;
					for (int x = 1; x <= 5; x++)
					{
						for (int y = 1; y <= 5; y++)
						{
							sum += maze[k]->at(x)[y] & maze[k + 1]->at(x)[y];
						}
					}
					if (sum == 0)
					{
						flag = true;
						break;
					}
				}
				if(!flag)
					dfs(1, 1, 1, 0);
			}
		}
	} while (next_permutation(arr.begin(), arr.end()));
	if (answer == 987654321)
		cout << -1 << endl;
	else
		cout << answer << endl;

}
int main(void)
{
	for (int i = 0; i < 5; i++)
	{
		plate[i][0] = vector<vector<int> >(7, vector<int>(7, 0));
		for (int j = 1; j <= 5; j++)
		{
			for (int k = 1; k <= 5; k++)
			{
				cin >> plate[i][0][j][k];
			}
		}
		for (int r = 0; r < 3; r++)
		{
			plate[i][r+1] = vector<vector<int> >(7, vector<int>(7, 0));
			for (int j = 1; j <= 5; j++)
			{
				for (int k = 1; k <= 5; k++)
				{
					plate[i][r + 1][j][k] = plate[i][r][k][6 - j];
				}
			}
		}
	}
	solve();
	return 0;
}