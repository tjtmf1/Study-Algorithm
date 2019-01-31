//http://codeforces.com/problemset/problem/103/B

#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

int n, m;
vector<int> *v;
list<int> li;
stack<int> st;
bool *visited;
int main(void)
{
	int cnt = 0;
	cin >> n >> m;
	v = new vector<int>[n + 1];
	visited = new bool[n + 1];
	for (int i = 0; i < n + 1; i++)
		visited[i] = false;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	st.push(1);
	while (!st.empty())
	{
		int node = st.top();
		st.pop();
		visited[node] = true;
		li.push_back(node);
		for (int i = 0; i < v[node].size(); i++)
		{
			if (visited[v[node].at(i)])
				continue;
			else
				st.push(v[node].at(i));
		}
	}
	li.sort();
	li.unique();
	if (li.size() == n && m == n)
		cout << "FHTAGN!";
	else
		cout << "NO";
	return 0;
}