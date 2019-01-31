//https://algospot.com/judge/problem/read/FENCE
#include <iostream>
using namespace std;
int n;
int h[200000];
int solution(int left, int right)
{
	if (left == right)
		return h[left];
	if (right - 1 == left)
	{
		int max = h[right];
		if (h[left] > max)
			max = h[left];
		int min = (h[left] < h[right]) ? h[left] : h[right];
		if (min * 2 > max)
			max = min * 2;
		return max;

	}

	int lMax = solution(left, (left + right) / 2);
	int rMax = solution((left + right) / 2 + 1, right);

	int ml = (left + right) / 2;
	int mr = ml + 1;
	int width = 2;
	int height = (h[ml] < h[mr]) ? h[ml] : h[mr];
	int max = height * width;
	for (; height > 0; height--)
	{
		while (ml > left && h[ml - 1] >= height)
		{
			ml--;
			width++;
		}
		while (mr < right && h[mr + 1] >= height)
		{
			mr++;
			width++;
		}
		if (width * height > max)
			max = width * height;
	}
	if (max < lMax)
		max = lMax;
	if (max < rMax)
		max = rMax;
	return max;
}
int main(void)
{
	int c;
	cin >> c;
	for (int test = 0; test < c; test++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> h[i];
		cout << solution(0, n - 1) << endl;
	}

	return 0;
}