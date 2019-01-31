//https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV6c6bgaIuoDFAXy&categoryId=AV6c6bgaIuoDFAXy&categoryType=CODE

#include <iostream>
#include <queue>
using namespace std;
int **where_desk;
class person
{
public:
	int num;
	int time;
	person() {}
	person(int _num, int _time)
	{
		num = _num;
		time = _time;
	}
	void operator= (person p)
	{
		num = p.num;
		time = p.time;
	}
	bool operator<(const person &p2) const
	{
		if (time > p2.time)
			return true;
		else if (time == p2.time)
		{
			if (where_desk[num][0] > where_desk[p2.num][0])
				return true;
		}
		return false;
	}
};

int main(void)
{
	int t;
	cin >> t;
	int *sum = new int[t];
	for (int i = 0; i < t; i++)
		sum[i] = 0;
	for (int test = 1; test <= t; test++)
	{
		int n, m, k, a, b;
		cin >> n >> m >> k >> a >> b;
		int *reception_time = new int[n];
		int *repair_time = new int[m];
		int *time = new int[k];
		where_desk = new int*[k];
		for (int i = 0; i < k; i++)
			where_desk[i] = new int[2];
		for (int i = 0; i < n; i++)
			cin >> reception_time[i];
		for (int i = 0; i < m; i++)
			cin >> repair_time[i];
		for (int i = 0; i < k; i++)
			cin >> time[i];
		priority_queue<person> *q = new priority_queue<person>;
		int *cur_time = new int[n];
		for (int i = 0; i < n; i++)
			cur_time[i] = 0;
		for (int i = 0; i < k; i++)
		{
			int min_desk = 0;
			for (int j = 0; j < n; j++)
			{
				if (cur_time[j] <= time[i])
				{
					min_desk = j;
					break;
				}
				if (cur_time[min_desk] > cur_time[j])
					min_desk = j;
			}
			if (time[i] <= cur_time[min_desk])
			{
				cur_time[min_desk] = cur_time[min_desk] + reception_time[min_desk];
				where_desk[i][0] = min_desk + 1;
				q->push(person(i, cur_time[min_desk]));
			}
			else
			{
				cur_time[min_desk] = time[i] + reception_time[min_desk];
				where_desk[i][0] = min_desk + 1;
				q->push(person(i, cur_time[min_desk]));
			}
		}
		delete[] cur_time;
		cur_time = new int[m];
		for (int i = 0; i < m; i++)
			cur_time[i] = 0;
		for (int i = 0; i < k; i++)
		{
			int min_desk = 0;
			person p = q->top();
			q->pop();
			for (int j = 0; j < m; j++)
			{
				if (cur_time[j] <= p.time)
				{
					min_desk = j;
					break;
				}
				if (cur_time[min_desk] > cur_time[j])
					min_desk = j;
			}
			if (p.time <= cur_time[min_desk])
			{
				cur_time[min_desk] = cur_time[min_desk] + repair_time[min_desk];
				where_desk[p.num][1] = min_desk + 1;
			}
			else
			{
				cur_time[min_desk] = p.time + repair_time[min_desk];
				where_desk[p.num][1] = min_desk + 1;
			}
		}
		delete q;
		delete[] cur_time;

		for (int i = 0; i < k; i++)
		{
			if (where_desk[i][0] == a && where_desk[i][1] == b)
				sum[test - 1] += i + 1;
		}
		if (sum[test - 1] == 0)
			sum[test - 1] = -1;

		for (int i = 0; i < k; i++)
			delete[] where_desk[i];
		delete[] where_desk;
		delete[] reception_time;
		delete[] repair_time;
		delete[] time;
	}

	for (int i = 0; i < t; i++)
		cout << "#" << i + 1 << " " << sum[i] << endl;
	return 0;
}