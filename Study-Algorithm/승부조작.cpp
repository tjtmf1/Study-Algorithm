//https://algospot.com/judge/problem/read/MATCHFIX
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> capacity, flow;
vector<int> win;
int source, sink, temp;
int networkflow()
{
	int totalFlow = 0;
	while (true)
	{
		vector<int> route(n + m + 3, -1);
		route[n + m] = n + m;
		queue<int> q;
		q.push(n + m);
		while (!q.empty() && route[sink] == -1)
		{
			int here = q.front();
			q.pop();
			for (int i = 0; i < n + m + 3; i++)
			{
				if (capacity[here][i] - flow[here][i] > 0 && route[i] == -1)
				{
					q.push(i);
					route[i] = here;
				}
			}
		}
		if (route[sink] == -1)
			break;
		int here = sink;
		int before = route[sink];
		int minFlow = 987654321;
		while (here != source)
		{
			if (capacity[before][here] - flow[before][here] < minFlow)
				minFlow = capacity[before][here] - flow[before][here];
			here = before;
			before = route[here];
		}
		here = sink;
		before = route[sink];
		while (here != source)
		{
			flow[before][here] += minFlow;
			flow[here][before] -= minFlow;
			here = before;
			before = route[here];
		}
		totalFlow += minFlow;
	}
	return totalFlow;
}
bool isPossible(int winCnt)
{
	int needToWin = winCnt - win[0];
	capacity[m + 0][sink] = needToWin;
	capacity[temp][sink] = m - needToWin;
	for (int i = 1; i < n; i++)
	{
		if (winCnt <= win[i])
			return false;
		capacity[m + i][temp] = winCnt - 1 - win[i];
	}
	flow = vector<vector<int>>(n + m + 3, vector<int>(n + m + 3, 0));
	if (networkflow() != m)
		return false;
	return true;
}
int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		win = vector<int>(n);
		//0~m-1: game     m~m+n-1:player   m+n: source    m+n+1: temp   m+n+2: sink
		source = m + n;
		temp = m + n + 1;
		sink = m + n + 2;
		capacity = vector<vector<int>>(n + m + 3, vector<int>(n + m + 3, 0));
		int curMax = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> win[i];
			if (curMax < win[i])
				curMax = win[i];
		}
		if (win[0] != curMax)
			curMax++;
		int canWin = 0;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			capacity[i][m + a] = 1;
			capacity[i][m + b] = 1;
			capacity[source][i] = 1;
			if (a == 0 || b == 0)
				canWin++;
		}
		bool flag = true;
		for (int i = curMax; i <= win[0] + canWin; i++)
		{
			if (isPossible(i))
			{
				flag = false;
				cout << i << endl;
				break;
			}
		}
		if (flag)
			cout << -1 << endl;
	}

	return 0;
}