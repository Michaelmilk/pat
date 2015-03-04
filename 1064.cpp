#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int g_idx = 0;
int g_tree[1003];

void build(int root, int nodenum, vector<int> &node)
{
	if(root > nodenum)
	{
		return;
	}

	int left = root << 1;
	int right = (root << 1) + 1;

	build(left, nodenum, node);
	g_tree[root] = node[g_idx++];
	build(right, nodenum, node);
}

int main()
{
	int node_num;
	cin >> node_num;
	vector<int> node(node_num);
	for(int i = 0; i < node_num; i++)
	{
		cin >> node[i];
	}

	sort(node.begin(), node.end());

	build(1, node_num, node);

	for(int i = 1; i <= node_num - 1; i++)
	{
		cout << g_tree[i] << " ";
	}
	cout << g_tree[node_num];

	system("pause");
	return 0;
}