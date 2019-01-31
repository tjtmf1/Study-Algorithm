//https://algospot.com/judge/problem/read/ROUTING
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
const double INF = 1.79e308;
int main(void)
{
	cout.precision(10);
	int c;
	cin >> c;
	while (c--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, double>>> e(n, vector<pair<int, double>>());
		for (int i = 0; i < m; i++)
		{
			int a, b;
			double value;
			cin >> a >> b >> value;

			e[a].push_back(pair<int, double>(b, value));
			e[b].push_back(pair<int, double>(a, value));
		}
		vector<double> dis(n, INF);
		dis[0] = 1;
		priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> p;
		p.push(pair<double, int>(1, 0));
		while (!p.empty())
		{
			double distance = p.top().first;
			int node = p.top().second;
			p.pop();
			for (int i = 0; i < e[node].size(); i++)
			{
				int des = e[node].at(i).first;
				double new_dis = distance * e[node].at(i).second;
				if (dis[des] > new_dis)
				{
					dis[des] = new_dis;
					p.push(pair<double, int>(new_dis, des));
				}
			}
		}
		cout << fixed << dis[n - 1] << endl;
	}
	return 0;
}