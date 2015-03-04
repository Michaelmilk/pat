//#include <iostream>
//#include <string>
//#include <map>
//#include <cstring>
//#include <stdlib.h>
//#include<cstdio>
//#include <stack>
//
//using namespace std;
//
//const int INF = 2100000000;
//const int MAX = 205;
//int n, K;
//bool vi[MAX];
//int dis[MAX];
//int cost[MAX][MAX];
//int happiness[MAX], final_happiness[MAX];
//int pre[MAX];
//int pre_city_cnt[MAX];//the num of nodes in the path
//int road_cnt[MAX];//the num of path from st to i
//map<string, int> name_to_num;
//map<int, string> num_to_name;
//stack<int> S;
//void init()
//{
//	for (int i = 0; i < n; ++i)
//	{
//		pre[i] = 0;
//		road_cnt[i] = 0;
//		pre_city_cnt[i] = 0;
//		vi[i] = 0;
//		dis[i] = INF;
//		happiness[i] = 0;
//		final_happiness[i] = 0;
//		name_to_num.clear();
//		num_to_name.clear();
//		while (!S.empty())
//		{
//			S.pop();
//		}
//		for (int j = 0; j < n; ++j)
//		{
//			cost[i][j] = INF;
//		}
//	}
//}
////void init()
////{
////	//freopen("in.txt", "r", stdin);
////	while (!S.empty())
////	{
////		S.pop();
////	}
////	string name1, name2;
////	int dist;
////	cin >> n >> K >> name1;
////	name_to_num[name1] = 0;
////	num_to_name[0] = name1;
////	happiness[0] = final_happiness[0] = 0;
////	for (int i = 1; i < n; ++i)
////	{
////		cin >> name1;
////		name_to_num[name1] = i;
////		num_to_name[i] = name1;
////		cin >> happiness[i];
////	}
////	memset(vi, false, sizeof(vi));
////	memset(road_cnt, 0, sizeof(road_cnt));
////	memset(pre_city_cnt, 0, sizeof(pre_city_cnt));
////	for (int i = 0; i < n; ++i)
////	{
////		dis[i] = INF;
////		for (int j = 0; j < n; ++j)
////		{
////			cost[i][j] = INF;
////		}
////	}
////	for (int i = 0; i < K; ++i)
////	{
////		cin >> name1 >> name2 >> dist;
////		cost[name_to_num[name1]][name_to_num[name2]] = dist;
////		cost[name_to_num[name2]][name_to_num[name1]] = dist;
////	}
////}
//
//
//
//void dijkstra()
//{//迪杰斯特拉
//	dis[0] = 0;
//	road_cnt[0] = 1;
//	for (int i = 0; i < n; ++i)
//	{
//		int index = -1;
//		int minn = INF;
//		for (int j = 0; j < n; ++j)
//		{
//			if (!vi[j] && dis[j] < minn)
//			{
//				minn = dis[j];
//				index = j;
//			}
//		}
//		if (index == -1)
//		{
//			break;
//		}
//		vi[index] = 1;
//		for (int j = 0; j <n; ++j)
//		{
//			//if (!visit[j])
//			//{
//			if (dis[index] + cost[index][j] < dis[j])
//			{
//				dis[j] = dis[index] + cost[index][j];
//				final_happiness[j] = final_happiness[index] + happiness[j];
//				road_cnt[j] = road_cnt[index];
//				pre_city_cnt[j] = pre_city_cnt[index] + 1;
//				pre[j] = index;
//			}
//			else if (dis[index] + cost[index][j] == dis[j])
//			{
//				road_cnt[j] += road_cnt[index];
//				if (final_happiness[j] < final_happiness[index] + happiness[j])
//				{
//					final_happiness[j] = final_happiness[index] + happiness[j];
//					pre_city_cnt[j] = pre_city_cnt[index] + 1;
//					pre[j] = index;
//				}
//				else if (final_happiness[j] == final_happiness[index] + happiness[j])
//				{
//					if (pre_city_cnt[j] > pre_city_cnt[index] + 1)
//					{
//						pre_city_cnt[j] = pre_city_cnt[index] + 1;
//						pre[j] = index;
//					}
//				}
//
//			}
//			//}
//		}
//	}
//}
////void dijkstra()
////{
////	dis[0] = 0;
////	road_cnt[0] = 1;
////
////	for (int k = 0; k < n; ++k)
////	{
////		int index = -1;
////		int minn = INF;
////		for (int i = 0; i < n; ++i)
////		{
////			if (vi[i] == false && dis[i]<minn)
////			{
////				index = i;
////				minn = dis[i];
////			}
////		}
////		if (index == -1)
////		{
////			break;
////		}
////		vi[index] = true;
////		for (int j = 0; j < n; ++j)
////		{
////			//dis[j] is the shortest route from index to j
////			if (dis[j] > dis[index] + cost[index][j])//the cost of index to j 
////			{
////				road_cnt[j] = road_cnt[index];//the shortest route equal to the node's
////				dis[j] = dis[index] + cost[index][j];//assignment
////				final_happiness[j] = final_happiness[index] + happiness[j];//node j's happiness
////				pre_city_cnt[j] = pre_city_cnt[index] + 1;//the num of nodes in the path
////				pre[j] = index;//node j's previous node 
////			}
////			else if (dis[j] == dis[index] + cost[index][j])//the cost of index to j 
////			{
////				road_cnt[j] += road_cnt[index];//plus another shortest path
////				//compare the new path happiness with the previous path's
////				if (final_happiness[j] < final_happiness[index] + happiness[j])
////				{
////					final_happiness[j] = final_happiness[index] + happiness[j];//assignment
////					pre_city_cnt[j] = pre_city_cnt[index] + 1;//the num of nodes in the path
////					pre[j] = index;//j node's previous node
////				}
////				else if (final_happiness[j] == final_happiness[index] + happiness[j]
////					&& pre_city_cnt[j] > pre_city_cnt[index] + 1)//if tje happiness is the same and the num of city is fewer
////				{
////					pre_city_cnt[j] = pre_city_cnt[index] + 1;//the num of nodes in the path
////					pre[j] = index;//j node's previous node
////				}
////			}
////		}
////	}
////}
//
//void print(int city)
//{
//	cout << road_cnt[name_to_num["ROM"]] << " " << dis[name_to_num["ROM"]] << " " << final_happiness[name_to_num["ROM"]];
//	printf(" %d\n", (final_happiness[name_to_num["ROM"]] / pre_city_cnt[name_to_num["ROM"]]));
//	//输出路径
//	int iter = name_to_num["ROM"];
//	while (1)//把之前的路径上的节点全部压栈
//	{
//		S.push(iter);
//		if (iter == pre[iter])
//		{
//			break;
//		}
//		iter = pre[iter];
//	};
//	int tmpCnt = pre_city_cnt[name_to_num["ROM"]];
//	while (!S.empty())
//	{
//		cout << num_to_name[S.top()];
//		S.pop();
//		if (tmpCnt != 0)
//		{
//			cout << "->";
//		}
//		/*else
//		{
//		printf("\n");
//		}*/
//		tmpCnt--;
//	}
//}
//
//
////void print(int city)
////{
////	if (city == 0)
////	{
////		int dest = name_to_num[string("ROM")];
////		cout << road_cnt[dest] << " " << dis[dest] << " "
////			<< final_happiness[dest] << " " << final_happiness[dest] / pre_city_cnt[dest] << endl;
////		cout << num_to_name[0];
////	}
////	else
////	{
////		print(pre[city]);
////		cout << "->" << num_to_name[city];
////	}
////}
//
//int main()
//{
//	init();
//
//	dijkstra();
//
//	print(name_to_num[string("ROM")]);
//
//	//system("pause");
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>
#include <fstream>
#include <iomanip>

using namespace std;

const int kNum = 210;
map<string, int> city_happiness;
map<string, int> city_id;
map<int, string> id_city;
int route[kNum][kNum];
bool visit[kNum];
int happiness[kNum];
int avg_happiness[kNum];
int dis[kNum];
int path[kNum];
int city_on_path[kNum];
int shortest_paths = 0;

void dijkstra(int city_num)
{
	while (true)
	{
		int min_val = INT_MAX;
		int idx = -1;
		for (int i = 0; i < city_num; i++)
		{
			if (!visit[i] && dis[i] < min_val)
			{
				min_val = dis[i];
				idx = i;
			}
		}

		if (min_val == INT_MAX)
		{
			break;
		}

		visit[idx] = true;

		for (int i = 0; i < city_num; i++)
		{
			if (!visit[i] && route[idx][i] > 0)
			{
				int d = dis[idx] + route[idx][i];
				int hap = happiness[idx] + city_happiness[id_city[i]];
				int citys = city_on_path[idx] + 1;
				int avg_hap = hap / citys;
				if (d < dis[i])
				{
					if (i == city_id["ROM"])
					{
						shortest_paths = 1;
					}
					dis[i] = d;
					happiness[i] = hap;
					path[i] = idx;
					city_on_path[i] = citys;
					avg_happiness[i] = avg_hap;
				}
				else if (d == dis[i])
				{
					if (i == city_id["ROM"])
					{
						shortest_paths++;
					}
					if (hap > happiness[i])
					{
						happiness[i] = hap;
						path[i] = idx;
						city_on_path[i] = citys;
						avg_happiness[i] = avg_hap;
					}
					else if (hap == happiness[i] && avg_hap > avg_happiness[i])
					{
						path[i] = idx;
						city_on_path[i] = citys;
						avg_happiness[i] = avg_hap;
					}
				}
			}
		}
	}
}

void PrintPath(int dest)
{
	if (path[dest] != -1)
	{
		PrintPath(path[dest]);
		cout << "->";
	}
	cout << id_city[dest];
}

int main()
{
	ifstream in("in.in");

	string start;
	int city_num, route_num;
	in >> city_num >> route_num >> start;
	city_id[start] = 0;
	id_city[0] = start;
	for (int i = 1; i < city_num; i++)
	{
		string name;
		int hap;
		in >> name >> hap;
		city_happiness[name] = hap;
		city_id[name] = i;
		id_city[i] = name;
	}

	for (int i = 0; i < route_num; i++)
	{
		string st, dest;
		int d;
		in >> st >> dest >> d;
		route[city_id[st]][city_id[dest]] = d;
		route[city_id[dest]][city_id[st]] = d;
	}

	for (int i = 0; i < kNum; i++)
	{
		dis[i] = INT_MAX;
		visit[i] = false;
		path[i] = -1;
		happiness[i] = INT_MIN;
	}

	dis[0] = 0;
	happiness[0] = 0;
	dijkstra(city_num);

	cout << shortest_paths << " " << dis[city_id["ROM"]] << " "
		<< happiness[city_id["ROM"]] << " " << avg_happiness[city_id["ROM"]] << endl;

	PrintPath(city_id["ROM"]);

	system("pause");
	return 0;
}