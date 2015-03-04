#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>


using namespace std;

struct Node
{
	int id;
	int w;
	bool operator<(const Node& n) const
	{
		return w > n.w;
	}
};

void FindEqualWeightPath(int root_id, int weight, vector<int> &nodes, 
	vector<int> &tmp, vector<vector<Node> > &child,vector<vector<int> > &ans)
{
	if(child[root_id].size() == 0)
	{
		cout << "---" << root_id << "----" << endl;
		int s = tmp.size();
		int count = 0;
		for(int i = 0; i < s; i++)
		{
			count += tmp[i];
		}

		if(weight == count)
		{
			//copy(tmp.begin(), tmp.end(), ostream_iterator<int>(cout, " "));
			ans.push_back(tmp);
		}

		return;
	}

	int size = child[root_id].size();
	for(int i = 0; i < size; i++)
	{
		int child_id = child[root_id][i].id;
		tmp.push_back(nodes[child_id]);
		FindEqualWeightPath(child_id, weight, nodes, tmp, child, ans);
		tmp.pop_back();
	}
}

void PrintPath(vector<vector<int> > &ans)
{
	int size = ans.size();
	for(int i = 0; i < size; i++)
	{
		int s = ans[i].size();
		for(int j = 0; j < s; j++)
		{
			cout << ans[i][j] << (j == s - 1 ? "\n" : " ");
		}
	}
}

int main()
{
	ifstream in("in.in");

	//map<int, vector<int> > node_mp;
	int node_num, nonleaf_node_num, weight;
	in >> node_num >> nonleaf_node_num >> weight;
	vector<int> nodes(node_num);
	vector<vector<Node> > child(node_num, vector<Node>());

	for(int i = 0; i < node_num; i++)
	{
		in >> nodes[i];
	}

	for(int i = 0; i < node_num - nonleaf_node_num; i++)
	{
		int id;
		int child_num;
		in >> id >> child_num;
		for(int j = 0; j < child_num; j++)
		{
			Node n;
			int child_id;
			in >> child_id;
			n.id = child_id;
			n.w = nodes[child_id];
			child[id].push_back(n);
		}
		sort(child[id].begin(), child[id].end());
	}

	vector<vector<int> > ans;
	vector<int> tmp;
	tmp.push_back(nodes[0]);
	FindEqualWeightPath(0, weight, nodes, tmp, child, ans);

	PrintPath(ans);

	system("pause");
	return 0;
}