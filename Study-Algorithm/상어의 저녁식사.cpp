//https://www.acmicpc.net/problem/1671
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, source, sink;
vector<vector<int> > capacity, flow;

int networkflow()
{
	int totalFlow = 0;
	while (true)
	{
		vector<int> route(2 * n + 2, -1);
		route[source] = source;
		queue<int> q;
		q.push(source);
		while (!q.empty() && route[sink] == -1)
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < 2 * n + 2; i++)
			{
				if (capacity[here][i] - flow[here][i] > 0 && route[i] == -1)
				{
					route[i] = here;
					q.push(i);
				}
			}
		}
		if (route[sink] == -1)
			break;
		else
		{
			int here = sink;
			int before = route[sink];
			while (here != source)
			{
				flow[before][here] += 1;
				flow[here][before] -= 1;
				here = before;
				before = route[here];
			}
			totalFlow += 1;
		}
	}
	return totalFlow;
}
int main(void)
{
	cin >> n;
	vector<int> size(n), speed(n), intelligence(n);
	source = 2 * n;
	sink = 2 * n + 1;
	capacity = vector<vector<int> >(2 * n + 2, vector<int>(2 * n + 2, 0));	//[2n] = source, [2n+1] = sink
	flow = vector<vector<int> >(2 * n + 2, vector<int>(2 * n + 2, 0));
	for (int i = 0; i < n; i++)
		cin >> size[i] >> speed[i] >> intelligence[i];

	for (int i = 0; i < n; i++)
	{
		capacity[source][i] = 2;
		capacity[n + i][sink] = 1;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (size[i] >= size[j] && speed[i] >= speed[j] && intelligence[i] >= intelligence[j])
			{
				if (size[i] == size[j] && speed[i] == speed[j] && intelligence[i] == intelligence[j] && i > j)
				{
					continue;
				}
				capacity[i][n + j] = 1;
			}
			
		}
	}

	int answer = n - networkflow();
	cout << answer << endl;
	return 0;
}