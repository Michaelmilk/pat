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

ifstream fin("in.in");
#define cin fin

const int k_NUM = 3000;

int set_size[k_NUM];
//int gang_set[k_NUM];
int member_time[k_NUM];
//int pair_member_time[k_NUM];//团伙内两个成员的通话时间
int gang_time[k_NUM];
int gang_num[k_NUM];
//int gang_time_of_member[k_NUM];//成员所在团伙的时间
map<string, int> name_to_id;
map<int, string> id_to_name;
int root[k_NUM];

struct HeadOfGang
{
	string name;
	int num;
	bool operator<(const HeadOfGang &hg) const
	{
		return name < hg.name;
	}
};

int GetRoot(int id)
{
	if(root[id] == id)
	{
		return id;
	}
	return root[id] = GetRoot(root[id]);
}

//根据id1和id2所属集合的成员数量，使小的集合合并到大的集合
void UnionSet(int id1, int id2)
{
	int root1 = GetRoot(id1);
	int root2 = GetRoot(id2);
	if(root1 == root2)
	{
		return;
	}

	if(set_size[root1] < set_size[root2])
	{
		root[root1] = root[root2];
		set_size[root2] += set_size[root1];
	}
	else
	{
		root[root2] = root[root1];
		set_size[root1] += set_size[root2];
	}
}

int main()
{
	int calls_num, threshold;
	cin >> calls_num >> threshold;

	int idx = 0;
	for(int i = 0; i < calls_num; i++)
	{
		string s, e;
		int time;
		cin >> s >> e >> time;
		if(name_to_id.find(s) == name_to_id.end())
		{
			name_to_id[s] = idx;
			id_to_name[idx] = s;
			root[idx]=idx;
			set_size[idx] = 1;
			idx++;
		}
		if(name_to_id.find(e) == name_to_id.end())
		{
			name_to_id[e] = idx;
			id_to_name[idx] = e;
			root[idx]=idx;
			set_size[idx] = 1;
			idx++;
		}

		int id1 = name_to_id[s];
		int id2 = name_to_id[e];
		member_time[id1] += time;
		member_time[id2] += time;
		//pair_member_time[id1] += time;//如果该id1和id2属于某一个团伙，那么time为团伙内两人的通话时间
		UnionSet(id1, id2);//并查集
	}
	//cout << idx << endl;
	//确定集合
	vector<int> gang_set;
	vector<int> set_of_member(idx);
	for(int i = 0; i < idx; i++)
	{
		set_of_member[i] = GetRoot(i);
		if(set_of_member[i] == i)
		{
			gang_set.push_back(i);
			//cout << i << endl;
		}
		//cout << gang_set[i] << endl;
	}

	//计算集合的人数以及总的通话时间
	int gang_set_size = gang_set.size();
	for(int i = 0; i < gang_set_size; i++)
	{
		for(int j = 0; j < idx; j++)
		{
			if(set_of_member[j] == gang_set[i])
			{
				gang_time[set_of_member[j]] += member_time[j];
				gang_num[gang_set[i]]++;
			}
		}
		gang_time[gang_set[i]] /= 2;
	}


	vector<HeadOfGang> gang_head;
	for(int i = 0; i < gang_set_size; i++)
	{
		if(gang_num[gang_set[i]] > 2 && gang_time[gang_set[i]] > threshold)
		{
			int head_id, max_time = INT_MIN;
			for(int j = 0; j < idx; j++)//查找集合中通话时长最长的
			{
				if(gang_set[i] == set_of_member[j])
				{
					if(member_time[j] > max_time)
					{
						head_id = j;
						max_time = member_time[j];
					}
				}
			}
			//保存集合的head以及集合的人数
			HeadOfGang head;
			head.name = id_to_name[head_id];
			head.num = gang_num[gang_set[i]];
			gang_head.push_back(head);
		}
	}

	sort(gang_head.begin(), gang_head.end());
	int size = gang_head.size();
	cout << size << endl;
	for(int i = 0; i < size; i++)
	{
		cout << gang_head[i].name << " " << gang_head[i].num << endl;
	}

	system("pause");
	return 0;
}

// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <climits>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <fstream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>

// using namespace std;

// ifstream fin("in.in");
// #define cin fin

// const int k_NUM = 3000;

// int set_size[k_NUM];
// int gang_set[k_NUM];
// int member_time[k_NUM];
// int pair_member_time[k_NUM];//团伙内两个成员的通话时间
// int gang_time[k_NUM];
// int gang_num[k_NUM];
// //int gang_time_of_member[k_NUM];//成员所在团伙的时间
// map<string, int> name_to_id;
// map<int, string> id_to_name;
// int root[k_NUM];

// struct HeadOfGang
// {
// 	string name;
// 	int num;
// 	bool operator<(const HeadOfGang &hg) const
// 	{
// 		return name < hg.name;
// 	}
// };

// int GetRoot(int id)
// {
// 	if(root[id] == id)
// 	{
// 		return id;
// 	}
// 	return root[id] = GetRoot(root[id]);
// }

// //根据id1和id2所属集合的成员数量，使小的集合合并到大的集合
// void UnionSet(int id1, int id2)
// {
// 	int root1 = GetRoot(id1);
// 	int root2 = GetRoot(id2);
// 	if(root1 == root2)
// 	{
// 		return;
// 	}

// 	if(set_size[root1] < set_size[root2])
// 	{
// 		root[root1] = root[root2];
// 		set_size[root2] += set_size[root1];
// 	}
// 	else
// 	{
// 		root[root2] = root[root1];
// 		set_size[root1] += set_size[root2];
// 	}
// }

// int main()
// {
// 	int calls_num, threshold;
// 	cin >> calls_num >> threshold;

// 	int idx = 0;
// 	for(int i = 0; i < calls_num; i++)
// 	{
// 		string s, e;
// 		int time;
// 		cin >> s >> e >> time;
// 		if(name_to_id.find(s) == name_to_id.end())
// 		{
// 			name_to_id[s] = idx;
// 			id_to_name[idx] = s;
// 			root[idx]=idx;
// 			set_size[idx] = 1;
// 			idx++;
// 		}
// 		if(name_to_id.find(e) == name_to_id.end())
// 		{
// 			name_to_id[e] = idx;
// 			id_to_name[idx] = e;
// 			root[idx]=idx;
// 			set_size[idx] = 1;
// 			idx++;
// 		}

// 		int id1 = name_to_id[s];
// 		int id2 = name_to_id[e];
// 		member_time[id1] += time;
// 		member_time[id2] += time;
// 		pair_member_time[id1] += time;//如果该id1和id2属于某一个团伙，那么time为团伙内两人的通话时间
// 		UnionSet(id1, id2);//并查集
// 	}
// 	//cout << idx << endl;
// 	//确定每个成员所属的集合
// 	for(int i = 0; i < idx; i++)
// 	{
// 		gang_set[i] = GetRoot(i);
// 		//cout << gang_set[i] << endl;
// 	}

// 	//计算集合的人数以及总的通话时间
// 	for(int i = 0; i < idx; i++)
// 	{
// 		gang_num[gang_set[i]]++;
// 		gang_time[gang_set[i]] += pair_member_time[i];
// 	}

// 	vector<bool> vst(idx, false);
// 	vector<HeadOfGang> gang_head;
// 	for(int i = 0; i < idx; i++)
// 	{
// 		//如果当前集合没被访问过&&人数大于2&&集合的通话总时长大于阈值
// 		if(!vst[gang_set[i]] && gang_num[gang_set[i]] > 2 && gang_time[gang_set[i]] > threshold)
// 		{
// 			vst[gang_set[i]] = true;
// 			int head_id, max_time = INT_MIN;
// 			for(int j = 0; j < idx; j++)//查找集合中通话时长最长的
// 			{
// 				if(gang_set[i] == gang_set[j])
// 				{
// 					if(member_time[j] > max_time)
// 					{
// 						head_id = j;
// 						max_time = member_time[j];
// 					}
// 				}
// 			}
// 			//保存集合的head以及集合的人数
// 			HeadOfGang head;
// 			head.name = id_to_name[head_id];
// 			head.num = gang_num[gang_set[i]];
// 			gang_head.push_back(head);
// 		}
// 	}

// 	sort(gang_head.begin(), gang_head.end());
// 	int size = gang_head.size();
// 	cout << size << endl;
// 	for(int i = 0; i < size; i++)
// 	{
// 		cout << gang_head[i].name << " " << gang_head[i].num << endl;
// 	}

// 	system("pause");
// 	return 0;
// }