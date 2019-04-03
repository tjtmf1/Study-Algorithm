//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14vXUqAGMCFAYD&categoryId=AV14vXUqAGMCFAYD&categoryType=CODE
#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
int main(void)
{
	int t = 10;
	while (t--)
	{
		vector<string> board(16);
		int num;
		cin >> num;
		int startX, startY;
		for (int i = 0; i < 16; i++)
		{
			cin >> board[i];
			for (int j = 0; j < 16; j++)
			{
				if (board[i][j] == '2')
				{
					startY = i;
					startX = j;
				}
			}
		}
		stack<pair<int, int>> s;
		s.push(make_pair(startY, startX));
		while (!s.empty())
		{
			int y = s.top().first;
			int x = s.top().second;
			s.pop();
			bool flag = false;
			for (int i = 0; i < 4; i++)
			{
				if (board[y + dy[i]][x + dx[i]] == '0')
				{
					s.push(make_pair(y + dy[i], x + dx[i]));
					board[y + dy[i]][x + dx[i]] = '1';
				}
				if (board[y + dy[i]][x + dx[i]] == '3')
				{
					s.push(make_pair(y + dy[i], x + dx[i]));
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (s.empty())
			cout << "#" << num << " " << 0 << endl;
		else
			cout << "#" << num << " " << 1 << endl;
	}

	return 0;
}
