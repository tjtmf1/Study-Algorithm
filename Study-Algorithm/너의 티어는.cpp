//https://www.acmicpc.net/problem/14613
#include <iostream>
using namespace std;
double factorial(int x)
{
	double fac = 1.0;
	while (x >= 1)
	{
		fac *= x--;
	}
	return fac;
}
double power(double x, double y)
{
	if (y == 0.0)
		return 1;
	if (x == 0.0)
		return 0;
	double power = 1;
	for (int k = y; k > 0; k--)
	{
		power *= x;
	}
	return power;
}
int main(void)
{
	double po_win, po_draw, po_lose;
	double bronze_rate = 0, silver_rate = 0, gold_rate = 0, platinum_rate = 0, dia_rate = 0;

	cin >> po_win >> po_lose >> po_draw;

	for (int win = 0; win <= 20; win++)
	{
		for (int lose = 0; lose <= 20; lose++)
		{
			for (int draw = 0; draw <= 20; draw++)
			{
				if (win + lose + draw == 20)
				{
					int score = 2000 + win * 50 - lose * 50;
					double probablity = power(po_win, win * 1.0) * power(po_lose, lose * 1.0)
						* power(po_draw, draw * 1.0) * factorial(20)
						/ factorial(win) / factorial(draw) / factorial(lose);
					if (score >= 1000 && score <= 1499)
					{
						bronze_rate += probablity;

					}
					else if (score >= 1500 && score <= 1999)
					{
						silver_rate += probablity;
					}
					else if (score >= 2000 && score <= 2499)
					{
						gold_rate += probablity;
					}
					else if (score >= 2500 && score <= 2999)
					{
						platinum_rate += probablity;
					}
					else if (score >= 3000 && score <= 3499)
					{
						dia_rate += probablity;
					}
				}
			}
		}
	}
	cout << fixed;
	cout.precision(8);

	cout << bronze_rate << endl << silver_rate << endl << gold_rate << endl
		<< platinum_rate << endl << dia_rate << endl;
	return 0;
}
