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

using namespace std;

ifstream in("in.in");
#define cin in

const int k_num = 10005;
int root[k_num];
//bool graphic[k_num][k_num];
vector<int> graphic[k_num];
int set_size[k_num];
int node_root[k_num];//the root of every node
bool vst[k_num];
vector<int> dep_root;
int max_val;

int GetRoot(int n)
{
	if(root[n] == n)
	{
		return n;
	}

	return root[n] = GetRoot(root[n]);
}

//！！！！！！！！！！！！！最后一个case过不了的原因！！！！！！！！！！
void UnionSet(int s, int e)
{
	int s_root = GetRoot(s);
	int e_root = GetRoot(e);
	// cout << s << " " << s_root << endl;
	// cout << e << " " << e_root << endl;
	// if(s_root != e_root)
	// {
	// 	root[s_root] = e_root;
	// }

	if(set_size[s_root] < set_size[e_root])
	{
		set_size[e_root] += set_size[e_root];
		root[s_root] = e_root;
	}
	else
	{
		set_size[s_root] += set_size[e_root];
		root[e_root] = s_root;
	}
}

// void GetDepth(int s, int sum, int node_num, int &depth)
// {
// 	sum++;
// 	depth = depth < sum ? sum : depth;
// 	vst[s] = true;
// 	for(int i = 1; i <= node_num; i++)
// 	{
// 		if(i != s && !vst[i] && graphic[s][i])
// 		{
// 			vst[i] = true;
// 			GetDepth(i, sum, node_num, depth);
// 		}
// 	}
// }

void GetDepth(int s, int depth)
{

	if(depth > max_val)
	{
		max_val = depth;
		dep_root.clear();
		dep_root.push_back(s);
		//cout << s << endl;
	}
	else if(depth == max_val)
	{
		dep_root.push_back(s);
	}
	
	int size = graphic[s].size();
	//cout << size << "---" << endl;
	for(int i = 0; i < size; i++)
	{
		if(!vst[graphic[s][i]])
		{
			vst[graphic[s][i]] = true;
			GetDepth(graphic[s][i], depth + 1);
			vst[graphic[s][i]] = false;
		}
	}
}

int main()
{
	int node_num;
	cin >> node_num;

	for(int i = 1; i <= node_num; i++)
	{
		set_size[i] = 1;
		root[i] = i;
	}

	for(int i = 0; i < node_num - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		//graphic[s][e] = true;
		//graphic[e][s] = true;
		graphic[s].push_back(e);
		graphic[e].push_back(s);
		UnionSet(s, e);
	}

	int count = 0;
	for(int i = 1; i <= node_num; i++)
	{
		if(root[i] == i)
		{
			//cout << node_num << " " << i << endl;
			count++;
		}
	}

	if(count > 1)
	{
		cout << "Error: " << count << " components" << endl;
	}
	else
	{
		memset(vst, 0, k_num);
		//int depth = 1;
		max_val = -1;
		vst[1] = true;
		GetDepth(1, 1);
		vst[1] = false;

		//depth = 1;
		vector<int> ans(dep_root);
		//copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
		max_val = -1;
		int s = dep_root[0];
		dep_root.clear();
		memset(vst, 0, k_num);
		vst[s] = true;
		GetDepth(s, 1);
		vst[s] = false;
		for(int i = 0; i < dep_root.size(); i++)
		{
			ans.push_back(dep_root[i]);
		}

		sort(ans.begin(), ans.end());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		int size = ans.size();
		for(int i = 0; i < size; i++)
		{
			cout << ans[i] << endl;
		}
		// for(int i = 1; i <= node_num; i++)
		// {
		// 	memset(vst, 0, k_num);
		// 	depth = 0;//!!!
		// 	GetDepth(i, 0, node_num, depth);
		// 	if(depth > max_val)
		// 	{
		// 		max_val = depth;
		// 		dep_root.clear();
		// 		dep_root.push_back(i);
		// 	}
		// 	else if(depth == max_val)
		// 	{
		// 		dep_root.push_back(i);
		// 	}
		// }

		// int size = dep_root.size();
		// for(int i = 0; i < size; i++)
		// {
		// 	cout << dep_root[i] << endl;
		// }
	}

	system("pause");
	return 0;
}