//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V4A46AdIDFAWu&categoryId=AV5V4A46AdIDFAWu&categoryType=CODE
#include <iostream>
#include <vector>
using namespace std;
int n, m, c;
vector<int> b;
int maxValue = 0;
void dfs(vector<int> &v, int index, int sum)
{
	if (index == m)
	{
		int temp = 0;
		for (int i = 0; i < b.size(); i++)
		{
			temp += b[i] * b[i];
		}
		if (maxValue < temp)
			maxValue = temp;
	}
	else
	{
		dfs(v, index + 1, sum);
		if (v[index] + sum <= c)
		{
			b.push_back(v[index]);
			dfs(v, index + 1, sum + v[index]);
			b.pop_back();
		}
	}
}
int maximum(vector<int> &v)
{
	maxValue = 0;
	dfs(v, 0, 0);
	return maxValue;
}
int main(void)
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		cin >> n >> m >> c;

		int map[10][10];
		int max[10][10];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> map[i][j];
		}
		for (int i = 0; i < n; i++)
		{
			vector<int> v;
			for (int k = 0; k < m; k++)
				v.push_back(map[i][k]);
			for (int j = 0; j < n - m + 1; j++)
			{
				max[i][j] = maximum(v);
				if (j != n - m)
				{
					v.erase(v.begin());
					v.push_back(map[i][j + m]);
				}
			}
		}
		int row = n;
		int col = n - m + 1;
		maxValue = 0;
		for (int i = 0; i < row * col; i++)
		{
			int temp = 0;
			for (int j = (i / col == (i + m) / col) ? i + m : (i / col + 1)*col; j < row*col; j++)
			{
				temp = max[i / col][i%col] + max[j / col][j%col];
				if (temp > maxValue)
					maxValue = temp;
			}
		}
		cout << "#" << t << " " << maxValue << endl;
	}

	return 0;
}