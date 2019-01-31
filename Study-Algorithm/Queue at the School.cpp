//http://codeforces.com/problemset/problem/266/B

#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	int n, t;
	string input;

	cin >> n >> t;
	cin >> input;

	while (t > 0)
	{
		for (int i = 1; i < input.length(); i++)
		{
			if (input[i - 1] == 'B' && input[i] == 'G')
			{
				input[i - 1] = 'G';
				input[i] = 'B';
				i++;
			}
		}

		t--;
	}

	cout << input;
	return 0;
}