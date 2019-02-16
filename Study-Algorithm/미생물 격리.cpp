//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl&categoryId=AV597vbqAH0DFAVl&categoryType=CODE
#include <iostream>
#include <vector>
using namespace std;
const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
class micro
{
public:
	int row, column;
	int count;
	int direction;
	int maxCount;
	bool isExist;
};
int main(void)
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<micro> vMicro(k);
		for (int i = 0; i < k; i++)
		{
			cin >> vMicro[i].row >> vMicro[i].column >> vMicro[i].count >> vMicro[i].direction;
			vMicro[i].isExist = true;
			vMicro[i].maxCount = vMicro[i].count;
		}
		for (int i = 0; i < m; i++)
		{
			vector<vector<int>> newMap(n, vector<int>(n, -1));
			for (int j = 0; j < k; j++)
			{
				if (!vMicro[j].isExist)
					continue;
				int newRow = vMicro[j].row;
				int newCol = vMicro[j].column;
				switch (vMicro[j].direction)
				{
				case UP:
					newRow--;
					break;
				case DOWN:
					newRow++;
					break;
				case LEFT:
					newCol--;
					break;
				case RIGHT:
					newCol++;
					break;
				}
				if (newMap[newRow][newCol] == -1)
				{
					newMap[newRow][newCol] = j;
					vMicro[j].row = newRow;
					vMicro[j].column = newCol;
					if (vMicro[j].row == 0 || vMicro[j].row == n - 1 || vMicro[j].column == 0 || vMicro[j].column == n - 1)
					{
						switch (vMicro[j].direction)
						{
						case UP:
							vMicro[j].direction = DOWN;
							break;
						case DOWN:
							vMicro[j].direction = UP;
							break;
						case LEFT:
							vMicro[j].direction = RIGHT;
							break;
						case RIGHT:
							vMicro[j].direction = LEFT;
							break;
						}
						vMicro[j].count /= 2;
					}
				}
				else
				{
					int index = newMap[newRow][newCol];
					if (vMicro[index].maxCount < vMicro[j].count)
					{
						vMicro[index].direction = vMicro[j].direction;
						vMicro[index].maxCount = vMicro[j].count;
					}
					vMicro[index].count += vMicro[j].count;
					vMicro[j].isExist = false;
				}
			}
			for (int j = 0; j < k; j++)
			{
				vMicro[j].maxCount = vMicro[j].count;
			}
		}
		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			if (vMicro[i].isExist)
				sum += vMicro[i].count;
		}
		cout << "#" << test + 1 << " " << sum << endl;
	}

	return 0;
}