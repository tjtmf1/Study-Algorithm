//http://codeforces.com/problemset/problem/490/B

#include<iostream>
#include<list>
#include <unordered_map>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int a, b;
	int queue[200001];
	list<int> l;
	unordered_map<int, int> map;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		map[a] = b;
		l.push_back(a);
		l.push_back(b);
	}
	l.sort();
	int uni[2];
	int i = 0;
	list<int>::iterator it = l.begin();
	while (l.size() >= 2)
	{
		if (*it == *(++it))
		{
			l.pop_front();
			l.pop_front();
			it = l.begin();
		}
		else
		{
			uni[i++] = *--it;
			l.pop_front();
			it = l.begin();
		}
	}
	if (i == 1)
		uni[i] = l.front();
	queue[1] = map[0];
	if (map.count(uni[0]) > 0)
		queue[0] = uni[0];
	else
		queue[0] = uni[1];
	int index = 0;
	int value = map[queue[index]];
	while (index < n)
	{
		queue[index + 2] = map[queue[index]];
		index++;
	}
	for (int i = 0; i < n; i++)
		cout << queue[i] << " ";

	delete[] queue;
	return 0;
}