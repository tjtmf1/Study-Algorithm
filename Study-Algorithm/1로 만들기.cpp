//https://www.acmicpc.net/problem/1463
#include<iostream>
using namespace std;

int main(void) {

	int n;
	cin >> n;

	int *dp = new int[n + 1];
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	int min = n;

	for (int i = 4; i <= n; i++) {
		min = n;
		if (i % 3 == 0) {
			dp[i] = dp[i / 3] + 1;
			if (dp[i] < min)
				min = dp[i];
		}
		if (i % 2 == 0) {
			dp[i] = dp[i / 2] + 1;
			if (dp[i] < min)
				min = dp[i];
		}
		dp[i] = dp[i - 1] + 1;
		if (dp[i] < min)
			min = dp[i];
		dp[i] = min;
	}

	cout << dp[n] << endl;
	delete[] dp;

	return 0;
}