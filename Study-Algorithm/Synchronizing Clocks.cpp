//https://algospot.com/judge/problem/read/CLOCKSYNC
#include <iostream>
using namespace std;
int iClock[16];
int minCount = 40;
const int CLOCK_COUNT = 16;
void nextTime(int num, int times)
{
	iClock[num] += 3 * times;
	if (iClock[num] > 12)
		iClock[num] -= 12;
}
void pushSwitch(int num, int times)
{
	switch (num)
	{
	case 0:
		nextTime(0, times); nextTime(1, times); nextTime(2, times);
		break;
	case 1:
		nextTime(3, times); nextTime(7, times); nextTime(9, times); nextTime(11, times);
		break;
	case 2:
		nextTime(4, times); nextTime(10, times); nextTime(14, times); nextTime(15, times);
		break;
	case 3:
		nextTime(0, times); nextTime(4, times); nextTime(5, times); nextTime(6, times); nextTime(7, times);
		break;
	case 4:
		nextTime(6, times); nextTime(7, times); nextTime(8, times); nextTime(10, times); nextTime(12, times);
		break;
	case 5:
		nextTime(0, times); nextTime(2, times); nextTime(14, times); nextTime(15, times);
		break;
	case 6:
		nextTime(3, times); nextTime(14, times); nextTime(15, times);
		break;
	case 7:
		nextTime(4, times); nextTime(5, times); nextTime(7, times); nextTime(14, times); nextTime(15, times);
		break;
	case 8:
		nextTime(1, times); nextTime(2, times); nextTime(3, times); nextTime(4, times); nextTime(5, times);
		break;
	case 9:
		nextTime(3, times); nextTime(4, times); nextTime(5, times); nextTime(9, times); nextTime(13, times);
		break;
	default:
		break;
	}
}
bool checkAnswer()
{
	for (int i = 0; i < CLOCK_COUNT; i++)
	{
		if (iClock[i] != 12)
			return false;
	}
	return true;
}
void dfs(int curSwitch, int push, int totalPush)
{
	if (checkAnswer())
	{
		if (totalPush < minCount)
			minCount = totalPush;
		return;
	}
	if (curSwitch == 10)
		return;

	dfs(curSwitch + 1, 0, totalPush);
	for (int i = 1; i < 4; i++)
	{
		pushSwitch(curSwitch, i);
		dfs(curSwitch + 1, i, totalPush + i);
		pushSwitch(curSwitch, 4 - i);
	}
}
int main(void)
{
	int c;
	cin >> c;
	for (int test = 0; test < c; test++)
	{
		minCount = 40;
		for (int i = 0; i < CLOCK_COUNT; i++)
			cin >> iClock[i];
		dfs(0, 0, 0);
		if (minCount == 40)
			minCount = -1;
		cout << minCount << endl;
	}

	return 0;
}