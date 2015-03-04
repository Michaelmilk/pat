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
	int level;
	Node(int i, int l) : id(i), level(l){}
};

bool vst[1010];
//TLE  如果把set换成vector，那么可以避免TLE
int CountFollowers(int id, int level, map<int, set<int> > &follower)
{
	int count = 0;
	queue<Node> que;
	Node root(id, 0);
	que.push(root);
	vst[id] = true;
	while(!que.empty())
	{
		Node buf = que.front();
		int idx = buf.id;
		que.pop();
		set<int> set_buf = follower[idx];
		set<int>::iterator it = set_buf.begin();
		for(; it!= set_buf.end(); it++)
		{
			if(!vst[*it] && buf.level + 1 <= level)
			{
				Node tmp(*it, buf.level + 1);
				que.push(tmp);
				vst[*it] = true;
				count++;
			}
		}
	}

	return count;
}

int main()
{
	ifstream in("in.in");

	int num, level, query_num;
	in >> num >> level;

	map<int, set<int> > follower;
	for(int i = 1; i <= num; i++)
	{
		int size;
		in >> size;
		for(int j = 0; j < size; j++)
		{
			int idx;
			in >> idx;
			follower[idx].insert(i);
		}
	}

	in >> query_num;
	for(int i = 0; i < query_num; i++)
	{
		memset(vst, 0, 1010);
		int id;
		in >> id;
		cout << CountFollowers(id, level, follower) << endl;
	}

	system("pause");
	return 0;
}

// //TLE
// void CountFollowers(int cur_level, int id, int level, set<int> &ans, map<int, set<int> > &follower)
// {
// 	if(cur_level == level || vst[id])
// 	{
// 		return;
// 	}
// 	set<int> set_buf = follower[id];
// 	set<int>::iterator it = set_buf.begin();
// 	for(; it!= set_buf.end(); it++)
// 	{
// 		vst[id] = true;
// 		set_union(ans.begin(), ans.end(), set_buf.begin(), set_buf.end(), inserter(ans, ans.begin()));
// 		CountFollowers(cur_level + 1, *it, level, ans, follower);
// 	}


// void CountFollowers(int cur_level, int id, int level, int &follower_num, map<int, set<int> > &follower)
// {
// 	if(cur_level == level)
// 	{
// 		return;
// 	}
// 	set<int> set_buf = follower[id];
// 	vector<int> buf;
// 	set<int>::iterator it = set_buf.begin();
// 	for(; it!= set_buf.end(); it++)
// 	{
// 		vst[id] = true;
// 		//set_union(ans.begin(), ans.end(), set_buf.begin(), set_buf.end(), inserter(ans, ans.begin()));
// 		if(!vst[*it])
// 		{
// 			//cout << *it << endl;
// 			follower_num++;
// 			vst[*it] = true;
// 			//可能已经访问过的点下面还有新节点，所以必须保证广度先遍历，在进行深度遍历
// 			//CountFollowers(cur_level + 1, *it, level, follower_num, follower);
// 			buf.push_back(*it);//先广度
// 		}
// 	}
// 	for(int i = 0; i < buf.size(); i++)
// 	{
// 		CountFollowers(cur_level + 1, buf[i], level, follower_num, follower);
// 	}
// }



// int main()
// {
// 	ifstream in("in.in");

// 	int num, level, query_num;
// 	in >> num >> level;

// 	map<int, set<int> > follower;
// 	for(int i = 1; i <= num; i++)
// 	{
// 		int size;
// 		in >> size;
// 		for(int j = 0; j < size; j++)
// 		{
// 			int idx;
// 			in >> idx;
// 			follower[idx].insert(i);
// 		}
// 	}

// 	in >> query_num;
// 	for(int i = 0; i < query_num; i++)
// 	{
// 		memset(vst, 0, 1010);
// 		int id;
// 		in >> id;
// 		// set<int> ans;
// 		// CountFollowers(0, id, level, ans, follower);
// 		// cout << ((ans.find(id) != ans.end()) ? ans.size() - 1 : ans.size()) << endl;
// 		int follower_num = 0;
// 		CountFollowers(0, id, level, follower_num, follower);
// 		cout << follower_num << endl;
// 	}

// 	system("pause");
// 	return 0;
// }