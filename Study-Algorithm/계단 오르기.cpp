//https://www.acmicpc.net/problem/2579
#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int stair[301];
	for (int i = 1; i <= n; i++)
		cin >> stair[i];
	int dp1[301];
	int dp2[301];
	dp1[0] = 0;
	dp2[0] = 0;
	dp1[1] = stair[1];
	dp2[1] = 0;
	dp1[2] = stair[1] + stair[2];
	dp2[2] = stair[2];
	for (int i = 3; i <= n; i++)
	{
		dp1[i] = dp2[i - 1] + stair[i];
		dp2[i] = (dp1[i - 2] > dp2[i - 2]) ? dp1[i - 2] + stair[i] : dp2[i - 2] + stair[i];
	}
	cout << ((dp1[n] > dp2[n]) ? dp1[n] : dp2[n]) << endl;

	return 0;
}