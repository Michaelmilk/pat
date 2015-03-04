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

using namespace std;

int highways[1000][1000];
int cost[1000][1000];
int total_cost[1000];
int path[1000];
int dis[1000];
bool visit[1000];

void dijkstra(int city_num)
{
	while(true)
	{
		int min_val = INT_MAX;
		int idx = -1;
		for(int i = 0; i < city_num; i++)
		{
			if(!visit[i] && dis[i] < min_val)
			{
				min_val = dis[i];
				idx = i;
			}
		}

		if(min_val == INT_MAX)
		{
			break;
		}

		visit[idx] = true;

		for(int i = 0; i < city_num; i++)
		{
			if(!visit[i] && highways[idx][i] > 0)
			{
				int d = dis[idx] + highways[idx][i];
				int tcost = total_cost[idx] + cost[idx][i];
				if(d < dis[i])
				{
					dis[i] = d;
					path[i] = idx;
					total_cost[i] = tcost;
				}
				else if(d == dis[i] && tcost < total_cost[i])
				{
					path[i] = idx;
					total_cost[i] = tcost;
				}
			}
		}
	}
}

void PrintPath(int dest)
{
	if(path[dest] != -1)
	{
		PrintPath(path[dest]);
		cout << " ";
	}
	cout << dest;
}

int main()
{
	ifstream in("in.in");

	int city_num, highway_num, start, dest;
	in >> city_num >> highway_num >> start >> dest;

	for(int i = 0; i < highway_num; i++)
	{
		int s, e, dis, cst;
		in >> s >> e >> dis >> cst;
		highways[s][e] = dis;
		highways[e][s] = dis;
		cost[s][e] = cst;
		cost[e][s] = cst;
	}

	for(int i = 0; i < city_num; i++)
	{
		path[i] = -1;
		dis[i] = INT_MAX;
		total_cost[i] = INT_MAX;
		visit[i] = false;
	}

	dis[start] = 0;
	total_cost[start] = 0;
	dijkstra(city_num);

	PrintPath(dest);
	cout << " " << dis[dest] << " " << total_cost[dest];

	system("pause");
	return 0;
}