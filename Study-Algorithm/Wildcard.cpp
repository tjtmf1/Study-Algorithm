//https://algospot.com/judge/problem/read/WILDCARD
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool dfs(string &w, string &s, int wIndex, int sIndex)
{
	if (w.size() == wIndex && s.size() == sIndex)
		return true;
	else if (w.size() == wIndex)
		return false;
	else if (s.size() == sIndex)
	{
		if (w[wIndex] == '*')
			return dfs(w, s, wIndex + 1, sIndex);
		return false;
	}
	switch (w[wIndex])
	{
	case '?':
		return dfs(w, s, wIndex + 1, sIndex + 1);
		break;
	case '*':
		return dfs(w, s, wIndex, sIndex + 1) | dfs(w, s, wIndex + 1, sIndex + 1) | dfs(w, s, wIndex + 1, sIndex);
		break;
	default:
		if (w[wIndex] == s[sIndex])
			return dfs(w, s, wIndex + 1, sIndex + 1);
		else
			return false;
		break;
	}
}

int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		string w;
		cin >> w;
		int n;
		cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		sort(s.begin(), s.end());
		for (int i = 0; i < n; i++)
		{
			if (dfs(w, s[i], 0, 0))
				cout << s[i] << endl;
		}
	}

	return 0;
}