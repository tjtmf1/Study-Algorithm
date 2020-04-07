//https://programmers.co.kr/learn/courses/30/lessons/42746
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string a, string b) {
	return a + b > b + a;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> numberString;
	for (int i = 0; i < numbers.size(); i++) {
		numberString.push_back(to_string(numbers[i]));
	}
	sort(numberString.begin(), numberString.end(), cmp);
	stringstream ss;
	for (int i = 0; i < numberString.size(); i++) {
		ss << numberString[i];
	}
	answer = ss.str();
	if (answer[0] == '0') {
		answer = "0";
	}
	return answer;
}