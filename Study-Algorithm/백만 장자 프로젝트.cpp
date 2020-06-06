//https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(vector<int>::iterator begin, vector<int>::iterator end) {
	if (begin == end) {
		return 0;
	}
	vector<int>::iterator maxIt = max_element(begin, end);
	long long gain = 0;
	while (begin != maxIt) {
		gain += *maxIt - *begin++;
	}
	return gain + solution(maxIt + 1, end);
}

int main(void) {
	int t;
	cin >> t;
	for (int test = 0; test < t; test++) {
		long long answer = 0;
		int days;
		vector<int> prices;
		cin >> days;
		for (int i = 0; i < days; i++) {
			int price;
			cin >> price;
			prices.push_back(price);
		}
		answer = solution(prices.begin(), prices.end());
		cout << "#" << test + 1 << " " << answer << endl;
	}
}