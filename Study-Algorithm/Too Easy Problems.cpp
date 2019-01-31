//http://codeforces.com/contest/913/problem/D
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class problem
{
public:
	int n, a, time;
	problem() {}
};
bool compare_a(problem &p1, problem &p2)
{
	return p1.a < p2.a;
}
bool compare_time(problem &p1, problem &p2)
{
	return p1.time < p2.time;
}
bool isPossible(int cnt, int &retIndex);
int n, time;
vector<problem> v;
int main(void)
{
	cin >> n >> time;
	v.assign(n, problem());
	for (int i = 0; i < n; i++)
	{
		v[i].n = i + 1;
		cin >> v[i].a >> v[i].time;
	}
	int low = 0;
	int high = n;
	int mid = (low + high) / 2;
	int index;
	while (low <= high)
	{
		if (isPossible(mid, index))
		{
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else
		{
			high = mid - 1;
			mid = (low + high) / 2;
		}
	}
	isPossible(high, index);
	cout << high << endl << high << endl;
	for (int j = 0; j < mid; j++)
		cout << v[index + j].n << " ";
	return 0;
}

bool isPossible(int cnt, int &retIndex)
{
	sort(v.begin(), v.end(), compare_a);
	int index;
	for (index = 0; index < n; index++)
	{
		if (v[index].a >= cnt)
		{
			sort(v.begin() + index, v.end(), compare_time);
			break;
		}
	}
	if (n - index < cnt)
		return false;
	int sum = 0;
	for (int i = 0; i < cnt; i++)
	{
		sum += v[index + i].time;
	}
	if (sum <= time)
	{
		retIndex = index;
		return true;
	}
	else
		return false;

}