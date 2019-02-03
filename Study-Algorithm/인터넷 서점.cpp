//https://algospot.com/judge/problem/read/BOOKSTORE
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class book
{
public:
	int price;
	int point;
	bool operator<(book &b) const
	{
		if (point == b.point)
		{
			return price < b.price;
		}
		return point > b.point;
	}
};
int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<book>> v(m, vector<book>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> v[j][i].price >> v[j][i].point;
			}
		}
		vector<int> cost(m, 0);
		int answer = 0;
		for (int i = 0; i < m; i++)
		{
			sort(v[i].begin(), v[i].end());
			int p = 0;
			for (int j = 0; j < n; j++)
			{
				if (v[i][j].price >= p)
				{
					cost[i] += v[i][j].price - p;
					p = 0;
				}
				else
				{
					p -= v[i][j].price;
				}
				p += v[i][j].point;
			}
			if (cost[answer] > cost[i])
				answer = i;
		}
		cout << cost[answer] << endl;

	}
	return 0;
}