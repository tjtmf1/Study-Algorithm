//https://algospot.com/judge/problem/read/NUMB3RS
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		int n, d, p;
		cin >> n >> d >> p;
		vector<vector<int>> edge(n, vector<int>(n));
		vector<int> edgeCnt(n);
		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				cin >> edge[i][j];
				sum += edge[i][j];
			}
			edgeCnt[i] = sum;
		}
		vector<double> probability(n, 0);
		probability[p] = 1;
		for (int i = 0; i < d; i++)
		{
			vector<double> newProbability(n, 0);
			for (int j = 0; j < n; j++)
			{
				for(int k=0; k<n; k++)
					newProbability[j] += probability[k] * edge[k][j] * (1.0 / edgeCnt[k]);
			}
			probability = newProbability;
		}
		int t;
		cin >> t;
		vector<int> q(t);
		for (int i = 0; i < t; i++)
			cin >> q[i];
		cout.precision(8);
		for (int i = 0; i < t; i++)
			cout << fixed << probability[q[i]] << " ";
		cout << endl;
	}
	return 0;
}