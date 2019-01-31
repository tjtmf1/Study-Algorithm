//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu&categoryId=AV5VwAr6APYDFAWu&categoryType=CODE
#include <iostream>
#include <vector>
using namespace std;
int n;
int map[20][20];
int t;
int solution = -1;
vector<int> v;
void dfs(int x, int y, int dx, int dy, bool left = true)	//x,y �� ������ǥ 
{															//dx,dy�� ���� �������� �̵�Ƚ��, �Ʒ������� �̵�Ƚ��
	int i = 0;												//left�� �ѹ��������ΰ��⸦ �׸��θ� ���̻� ���� ���ϵ��� ������ �÷���

	if (x - dx - 1 >= 0 && y + dx + 1 < n && left)			//�����������κ��� ���ʾƷ��� ���� ���
	{
		int item = map[y + dx + 1][x - dx - 1];
		for (i = 0; i < v.size(); i++)
		{
			if (v[i] == item)
				break;
		}
		if (i == v.size())
		{
			v.push_back(item);
			dfs(x, y, dx + 1, dy);
			v.pop_back();
		}
	}
	if (y + dx + dy + 1 < n && x - dx + dy + 1 < n && dx != 0)	//���ʾƷ��������� �����ʾƷ��� ���� ���
	{
		int item = map[y + dx + dy + 1][x - dx + dy + 1];
		for (i = 0; i < v.size(); i++)
		{
			if (v[i] == item)
				break;
		}
		if (i == v.size())
		{
			v.push_back(item);
			dfs(x, y, dx, dy + 1, false);
			v.pop_back();
		}
	}
	if (dx != 0 && dy != 0 && solution < (dx + dy) * 2)			//�����������κ��� �밢������ ���������� �����ϸ�
	{															//������ ������ �ߺ��Ǵ��� Ȯ�� �� solution ������ ����.
		if (x + dy >= n)
			return;
		else
		{
			int count = 0;
			for (int i = 1; i < dy; i++)
			{
				int item = map[y + i][x + i];
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i] == item)
					{
						for (int i = 0; i < count; i++)
							v.pop_back();
						return;
					}
				}
				v.push_back(item);
				count++;
			}
			for (int i = 0; i < dx; i++)
			{
				int item = map[y + dy + i][x + dy - i];
				for (int i = 0; i < v.size(); i++)
				{
					if (v[i] == item)
					{
						for (int i = 0; i < count; i++)
							v.pop_back();
						return;
					}
				}
				v.push_back(item);
				count++;
			}
			if (solution < (dx + dy) * 2)
				solution = v.size();
			for (int i = 0; i < count; i++)
				v.pop_back();
			return;
		}
	}
}
int main(void)
{
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		cin >> n;
		solution = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				v.clear();
				v.push_back(map[i][j]);
				dfs(j, i, 0, 0);		//��� ĭ���� dfs�� ����
			}
		}
		cout << "#" << test << " " << solution << endl;
	}
	return 0;
}