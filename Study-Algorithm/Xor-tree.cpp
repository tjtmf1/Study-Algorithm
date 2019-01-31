//http://codeforces.com/problemset/problem/429/A

#include <iostream>
#include <vector>
using namespace std;

int n;
int *answer;
int cnt = 0;
vector<int> save;
class node
{
public:
	int value;
	int num;
	bool traversal = false;
	vector<node*> edge;
	node() {}

	void dfs(int odd_flip, int even_flip, bool is_odd)
	{
		if (traversal)
			return;
		traversal = true;
		switch (is_odd)
		{
		case true:
			if (odd_flip & 1)
				value = !value;
			break;
		case false:
			if (even_flip & 1)
				value = !value;
			break;
		}
		if (value == answer[num - 1])
		{
			for (int i = 0; i < edge.size(); i++)
				edge[i]->dfs(odd_flip, even_flip, !is_odd);
		}
		else
		{
			cnt++;
			save.push_back(num);
			value = !value;
			if (is_odd)
				for (int i = 0; i < edge.size(); i++)
					edge[i]->dfs(odd_flip + 1, even_flip, !is_odd);
			else
				for (int i = 0; i < edge.size(); i++)
					edge[i]->dfs(odd_flip, even_flip + 1, !is_odd);
		}
	}
};

int main(void)
{
	cin >> n;
	node *nd = new node[n];
	answer = new int[n];
	for (int i = 0; i < n; i++)
		nd[i].num = i + 1;
	for (int i = 0; i < n - 1; i++)
	{
		int _child, _parent;
		cin >> _child >> _parent;
		nd[_parent - 1].edge.push_back(&nd[_child - 1]);
		nd[_child - 1].edge.push_back(&nd[_parent - 1]);
	}
	for (int i = 0; i < n; i++)
		cin >> nd[i].value;
	for (int i = 0; i < n; i++)
		cin >> answer[i];
	nd[0].dfs(0, 0, true);
	cout << cnt << endl;
	for (int i = 0; i < save.size(); i++)
		cout << save[i] << endl;
	delete[] nd;
	delete[] answer;
	return 0;
}