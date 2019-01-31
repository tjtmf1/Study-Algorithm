//https://algospot.com/judge/problem/read/LUNCHBOX

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class LunchBox
{
public:
	int heat, eat;
	void operator=(LunchBox l)
	{
		heat = l.heat;
		eat = l.eat;
	}
	bool operator<(LunchBox l)
	{
		return eat > l.eat;
	}
};

int main(void)
{
	int c;
	cin >> c;
	for (int test = 0; test < c; test++)
	{
		int n;
		cin >> n;
		vector<LunchBox> v;
		for (int i = 0; i < n; i++)
		{
			v.push_back(LunchBox());
			int heat;
			cin >> heat;
			v[i].heat = heat;
		}
		for (int i = 0; i < n; i++)
		{
			int eat;
			cin >> eat;
			v[i].eat = eat;
		}
		sort(v.begin(), v.end());
		int max = 0, accSum = 0;
		for (int i = 0; i < n; i++)
		{
			if (accSum + v[i].heat + v[i].eat > max)
				max = accSum + v[i].heat + v[i].eat;
			accSum += v[i].heat;
		}
		cout << max << endl;

	}

	return 0;
}