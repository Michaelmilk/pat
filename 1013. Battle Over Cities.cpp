//#include <iostream>
//#include <vector>
//#include <string>
//#include <stack>
//#include <iterator>
//#include <cmath>
//#include <map>
//#include <algorithm>
//#include <cstdlib>
//#include <fstream>
//#include <climits>
//#include <Windows.h>
//#include <queue>
//#include <deque>
//#include <set>
//#include <unordered_set>
//
//using namespace std;
//
////通过减少不必要的循环来解决TLE的问题
//bool graphic[1005][1005];
//
//
//int RepairHighways(int citynum, int cityid)
//{
//	/*
//	vector<vector<bool> > graphic(citynum + 1, vector<bool>(citynum + 1, false));
//
//	for (int i = 1; i <= citynum; i++)
//	{
//		for (int j = 1; j <= citynum; j++)
//		{
//			if (graphic[i][j])
//			{
//				graphic[i][j] = true;
//			}
//		}
//	}
//
//
//	for (int i = 1; i <= citynum; i++)
//	{
//		if (graphic[i][cityid])
//		{
//			graphic[i][cityid] = 3;
//		}
//		if (graphic[cityid][i])
//		{
//			graphic[cityid][i] = 3;
//		}
//	}*/
//
//	set<int> cityset;
//	int num = 0;
//	bool flag = false;
//	for (int i = 1; i <= citynum; i++)
//	{
//		if (i != cityid && cityset.find(i) == cityset.end())
//		{
//			if (cityset.size() != 0)
//			{
//				num++;
//			}
//			cityset.insert(i);
//			queue<int> que;
//			que.push(i);
//			while (!que.empty())
//			{
//				int t = que.front();
//				que.pop();
//				for (int i = 1; i <= citynum; i++)
//				{
//					if (i != cityid && cityset.find(i) == cityset.end() && (graphic[i][t] == true || graphic[t][i] == true))
//					{
//						cityset.insert(i);
//						que.push(i);
//						/*graphic[i][t] = 3;
//						graphic[t][i] = 3;*/
//					}
//				}
//			}
//		}
//	}
//
//	/*for (int i = 1; i <= citynum; i++)
//	{
//		for (int j = 1; j <= citynum; j++)
//		{
//			if (graphic[i][j] == 3)
//			{
//				graphic[i][j] = 1;
//			}
//		}
//	}*/
//
//	return num;
//}
//
//int main()
//{
//	ifstream in("in.in");
//
//	int citynum, highways, checknum;
//	in >> citynum >> highways >> checknum;
//
//	for (int i = 1; i <= highways; i++)
//	{
//		int s, e;
//		in >> s >> e;
//		graphic[s][e] = true;
//		graphic[e][s] = true;
//	}
//
//	for (int i = 0; i < checknum; i++)
//	{
//		int id;
//		in >> id;
//		int edgenum = RepairHighways(citynum, id);
//		cout << edgenum << endl;
//	}
//
//	return 0;
//}


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>

using namespace std;

struct Edge
{
	int s;
	int e;
};

int GetSet(int i, vector<int> &cityset)
{
	if (cityset[i] == i)
	{
		return i;
	}
	else
	{
		return cityset[i] = GetSet(cityset[i], cityset);//decrease the hight of tree
	}
}

void UnionSet(int start, int end, vector<int> &cityset, vector<int> &setsize)
{
	int s = GetSet(start, cityset);
	int e = GetSet(end, cityset);

	if (setsize[s] > setsize[e])
	{
		setsize[s] += setsize[e];
		cityset[e] = cityset[s];
	}
	else
	{
		setsize[e] += setsize[s];
		cityset[s] = cityset[e];
	}
}

int main()
{
	ifstream in("in.in");

	int citys, highways, checks;
	in >> citys >> highways >> checks;

	vector<Edge> edge(highways);
	for (int i = 0; i < highways; i++)
	{
		in >> edge[i].s;
		in >> edge[i].e;
	}

	for (int i = 0; i < checks; i++)
	{
		vector<int> cityset(citys + 1);
		vector<int> citysize(citys + 1, 1);
		for (int i = 1; i <= citys; i++)//reassign the initial city sets
		{
			cityset[i] = i;
		}

		int id;
		in >> id;

		//merge the node in the same connected area, this means set the same nodes root
		for (int j = 0; j < highways; j++)
		{
			if (edge[j].s == id || edge[j].e == id)//delete edges related to id
			{
				continue;
			}

			if (edge[j].s == edge[j].e)
			{
				continue;
			}
			UnionSet(edge[j].s, edge[j].e, cityset, citysize);//merge the nodes
		}

		int num = 0;
		for (int k = 1; k <= citys; k++)
		{
			if (k != id && cityset[k] == k)
			{
				num++;//connective blocks' num
			}
		}

		cout << num - 1 << endl;
	}

	return 0;
}
