//https://algospot.com/judge/problem/read/FORTRESS
#include <iostream>
#include <vector>
using namespace std;
class Node;
bool visited[100];
int maxDepth = 0;
Node *maxDepthNode;
int answer = 0;
class Node
{
public:
	int x;
	int y;
	int r;
	int num;
	Node *parent;
	vector<Node*> child;
	Node(int x, int y, int r, Node *parent, int num)
	{
		this->x = x;
		this->y = y;
		this->r = r;
		this->parent = parent;
		this->num = num;
	}
};
Node* findWhere(Node *curNode, int x, int y)
{
	for (int i = 0; i < curNode->child.size(); i++)
	{
		Node *child = curNode->child.at(i);
		if ((child->x - x) * (child->x - x) + (child->y - y) * (child->y - y) - child->r * child->r < 0)
			return findWhere(child, x, y);
	}
	return curNode;
}
void dfs1(Node *curNode, int height)
{
	for (int i = 0; i < curNode->child.size(); i++)
		dfs1(curNode->child.at(i), height + 1);
	if (curNode->child.empty() && height > maxDepth)
	{
		maxDepth = height;
		maxDepthNode = curNode;
	}
}
void dfs2(Node *curNode, int height)
{
	bool go = false;
	visited[curNode->num] = true;
	if (curNode->parent != NULL && !visited[curNode->parent->num])
	{
		dfs2(curNode->parent, height + 1);
		go = true;
	}
	for (int i = 0; i < curNode->child.size(); i++)
	{
		if (!visited[curNode->child.at(i)->num])
		{
			dfs2(curNode->child.at(i), height + 1);
			go = true;
		}
	}
	if (!go && height > answer)
	{
		answer = height;
	}
}
int main(void)
{
	int t;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		int n;
		cin >> n;
		int x, y, r;
		cin >> x >> y >> r;
		int cnt = 0;
		Node *root = new Node(x, y, r, NULL, cnt++);
		for (int i = 1; i < n; i++)
		{
			cin >> x >> y >> r;
			Node *find = findWhere(root, x, y);
			find->child.push_back(new Node(x, y, r, find, cnt++));
		}

		for (int i = 0; i < n; i++)
			visited[i] = false;
		maxDepth = 0;
		maxDepthNode = root;
		answer = 0;
		dfs1(root, 0);
		dfs2(maxDepthNode, 0);
		cout << answer << endl;
	}
	return 0;
}