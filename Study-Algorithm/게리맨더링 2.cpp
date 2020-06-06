//https://www.acmicpc.net/problem/17779
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[20][20];

int computeMaxValue(int r, int c, int d1, int d2) {
	vector<int> v(5);
	int sector[20][20];

	for (int i = 0; i < r + d1; i++) {
		for (int j = 0; j <= c; j++) {
			sector[i][j] = 0;
		}
	}

	for (int i = 0; i <= r + d2; i++) {
		for (int j = c + 1; j < n; j++) {
			sector[i][j] = 1;
		}
	}

	for (int i = r + d2 + 1; i < n; i++) {
		for (int j = c - d1 + d2; j < n; j++) {
			sector[i][j] = 2;
		}
	}

	for (int i = r + d1; i < n; i++) {
		for (int j = 0; j < c + d2 - d1; j++) {
			sector[i][j] = 3;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j >= r + c && i + j <= r + d2 + c + d2 &&
				i - j >= r - c && i - j <= r + d1 - c + d1) {
				sector[i][j] = 4;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[sector[i][j]] += a[i][j];
		}
	}

	return *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int answer = 987654321;
	for (int r = 1; r < n; r++) {
		for (int c = 1; c < n; c++) {
			for (int d1 = 1; c - d1 >= 0; d1++) {
				for (int d2 = 1; c + d2 < n; d2++) {
					if (r + d1 + d2 >= n) {
						continue;
					}
					int value = computeMaxValue(r, c, d1, d2);
					if (answer > value) {
						answer = value;
					}
				}
			}
		}
	}
	cout << answer << endl;
	return 0;
}