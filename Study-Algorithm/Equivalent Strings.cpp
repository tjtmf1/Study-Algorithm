//https://codeforces.com/problemset/problem/559/B
#include <iostream>
#include <string>
#include <map>
using namespace std;
map<pair<string, string>, bool>m;
bool isEqual(string a, string b)
{
	pair<string, string> p1(a, b);
	pair<string, string> p2(b, a);
	if (m.find(p1) != m.end())
	{
		return m.find(p1)->second;
	}
	if (m.find(p2) != m.end())
	{
		return m.find(p2)->second;
	}
	bool value;
	if (a.size() % 2 == 1)
	{
		value = (a == b);
	}
	else
	{
		int size = a.size() / 2;
		string a1(a, 0, size);
		string a2(a, size, size);
		string b1(b, 0, size);
		string b2(b, size, size);
		value = (isEqual(a1, b1) && isEqual(a2, b2)) || (isEqual(a1, b2) && isEqual(a2, b1));
	}
	m.insert(make_pair(p1, value));
	m.insert(make_pair(p2, value));
	return value;
}
int main(void)
{
	string str[2];
	cin >> str[0] >> str[1];
	cout << ((isEqual(str[0], str[1])) ? "YES" : "NO") << endl;

	return 0;
}