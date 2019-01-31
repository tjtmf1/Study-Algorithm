//http://codeforces.com/problemset/problem/107/A

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class des
{
public:
	int end;
	int diameter;
	des() {}
	des(int _end, int _diameter)
	{
		end = _end;
		diameter = _diameter;
	}
};

int n, p;
unordered_map<int, des> pipe;
unordered_map<int, int> reverse_pipe;
vector<int> tap;
int t;
int main(void)
{
	cin >> n >> p;
	for (int i = 0; i < p; i++)
	{
		int a, b, d;
		cin >> a >> b >> d;
		pipe[a] = des(b, d);
		reverse_pipe[b] = a;
	}
	for (int i = 1; i < n + 1; i++)
	{
		if (reverse_pipe.count(i) == 0)
		{
			if (pipe.count(i) == 0)
				continue;
			tap.push_back(i);
		}
	}
	t = tap.size();
	cout << t << endl;
	for (int i = 0; i < t; i++)
	{
		int house = tap[i];
		int water = 1000000;
		while (pipe.count(house) != 0)
		{
			if (pipe[house].diameter <= water)
				water = pipe[house].diameter;
			house = pipe[house].end;
		}
		cout << tap[i] << " " << house << " " << water << endl;
	}
	return 0;
}