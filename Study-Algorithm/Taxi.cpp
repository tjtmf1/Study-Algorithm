//http://codeforces.com/problemset/problem/158/B

#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int *s = new int[n];
	int car_count = 0;
	int group_count[4] = { 0,0,0,0 };
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		group_count[s[i] - 1]++;
	}
	car_count += group_count[3];			//4명인 그룹은 그냥 태워보냄
	car_count += group_count[2]; group_count[0] -= group_count[2];		//3명인 그룹은 1명인 그룹과 함께 보냄
	car_count += group_count[1] / 2;			//2명인 그룹은 2명씩 짝지어 보내고
	if (group_count[1] % 2 == 1)				//2명인 그룹이 홀수개면 1인이랑 같이 보냄
	{
		car_count++; group_count[0] -= 2;
	}
	if (group_count[0] > 0)						//1명인 그룹은 4개그룹을 같이보냄
		car_count += (int)ceil(group_count[0] / 4.0);
	cout << car_count;
	delete s;
	return 0;
}