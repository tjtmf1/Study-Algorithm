//http://codeforces.com/problemset/problem/777/B
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	char *s = new char[n + 1];
	char *m = new char[n + 1];
	cin >> s;
	cin >> m;
	sort(s, s + n);
	sort(m, m + n);
	int s_index = 0, m_index = 0;
	while (true)
	{
		if (m_index == n)
			break;
		if (s[s_index] <= m[m_index])
		{
			s_index++;
			m_index++;
		}
		else
		{
			while (true)
			{
				m_index++;
				if (m_index == n)
					break;
				if (s[s_index] <= m[m_index])
					break;
			}
		}
	}
	cout << n - s_index << endl;
	s_index = 0;
	m_index = 0;
	while (true)
	{
		if (m_index == n)
			break;
		if (s[s_index] < m[m_index])
		{
			s_index++;
			m_index++;
		}
		else
		{
			while (true)
			{
				m_index++;
				if (m_index == n)
					break;
				if (s[s_index] < m[m_index])
					break;
			}
		}
	}
	cout << s_index << endl;
	return 0;
}