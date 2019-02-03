//https://algospot.com/judge/problem/read/BRACKETS2
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
	int c;
	cin >> c;
	while (c--)
	{
		string str;
		cin >> str;
		stack<char> s;
		bool flag = true;
		s.push(1);
		for (int i = 0; i < str.size(); i++)
		{
			char ch = str.at(i);
			if (ch == '(' || ch == '[' || ch == '{')
			{
				s.push(ch);
			}
			else
			{
				if (s.top() == 1)
				{
					flag = false;
					break;
				}
				if (ch == ')')
				{
					if (s.top() != '(')
					{
						flag = false;
						break;
					}
					s.pop();
				}
				else if (ch == ']')
				{
					if (s.top() != '[')
					{
						flag = false;
						break;
					}
					s.pop();
				}
				else
				{
					if (s.top() != '{')
					{
						flag = false;
						break;
					}
					s.pop();
				}
			}
		}
		if (flag && s.top() == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}