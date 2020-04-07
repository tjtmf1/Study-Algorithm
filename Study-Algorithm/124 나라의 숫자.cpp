//https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	while (n) {
		int num = n % 3;
		if (num == 0) {
			num = 4;
			n -= 3;
		}
		answer += num + '0';
		n /= 3;
	}
	reverse(answer.begin(), answer.end());
	return answer;
}