//https://www.oncoder.com/developer/practice/list
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
vector<vector<int> > capacity, flow;
vector<vector<int> > edge;
int row, col;
int nodeCnt;
int source, sink;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int networkFlow()
{
	int maxFlow = 0;
	while (true)
	{
		vector<int> prev(nodeCnt, -1);
		queue<int> q;
		prev[source] = source;
		q.push(source);
		while (!q.empty() && prev[sink] == -1)
		{
			int curNode = q.front();
			q.pop();
			for (int i = 0; i < edge[curNode].size(); i++)
			{
				int node = edge[curNode][i];
				if (capacity[curNode][node] - flow[curNode][node] > 0 && prev[node] == -1)
				{
					prev[node] = curNode;
					q.push(node);
				}
			}
		}
		if (prev[sink] == -1)
			break;
		int curNode = sink;
		while (curNode != source)
		{
			flow[curNode][prev[curNode]] -= 1;
			flow[prev[curNode]][curNode] += 1;
			curNode = prev[curNode];
		}
		maxFlow += 1;
	}

	return maxFlow;
}
class Solution {
public:
	int solution(vector<string> board) {
		col = board.size();
		row = board[0].size();
		nodeCnt = col * row * 2 + 2;
		capacity = vector<vector<int> >(nodeCnt, vector<int>(nodeCnt, 0));
		flow = vector<vector<int> >(nodeCnt, vector<int>(nodeCnt, 0));
		edge = vector<vector<int> >(nodeCnt);
		source = nodeCnt - 2;
		sink = nodeCnt - 1;
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (board[i][j] != '.')
					continue;
				int node = i * row + j;
				if ((i + j) % 2 == 1)
				{
					if (i % 2 == 0)
					{
						capacity[source][node] = 1;
						edge[source].push_back(node);
						edge[node].push_back(source);
						for (int k = 0; k < 4; k++)
						{
							if (i + dy[k] < 0 || i + dy[k] >= col || j + dx[k] < 0 || j + dx[k] >= row)
								continue;
							int newNode = (i + dy[k]) * row + (j + dx[k]);
							if (board[i + dy[k]][j + dx[k]] == '.')
							{
								capacity[node][newNode] = 1;
								edge[node].push_back(newNode);
								edge[newNode].push_back(node);
							}
						}
					}
					else
					{
						capacity[node][sink] = 1;
						edge[node].push_back(sink);
						edge[sink].push_back(node);
						for (int k = 0; k < 4; k++)
						{
							if (i + dy[k] < 0 || i + dy[k] >= col || j + dx[k] < 0 || j + dx[k] >= row)
								continue;
							int newNode = (col * row) + (i + dy[k]) * row + (j + dx[k]);
							if (board[i + dy[k]][j + dx[k]] == '.')
							{
								capacity[newNode][node] = 1;
								edge[newNode].push_back(node);
								edge[node].push_back(newNode);
							}
						}
					}
				}
				else
				{
					capacity[node][col * row + node] = 1;
					edge[node].push_back(col * row + node);
					edge[col * row + node].push_back(node);
				}
			}
		}
		return networkFlow();
	}
};
int main(void)
{
	Solution s;
	vector<string> v;
	//for (int i = 0; i < 3; i++)
	//	v.push_back("...");
	v.push_back("..X.");
	v.push_back(".XX.");
	v.push_back("X...");
	v.push_back("...X");
	v.push_back("X...");
	v.push_back("....");
	cout << s.solution(v) << endl;
	return 0;
}