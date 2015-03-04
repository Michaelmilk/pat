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
int shortest_paths[kNum];//path num

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
					shortest_paths[i] = shortest_paths[idx];
					dis[i] = d;
					happiness[i] = hap;
					path[i] = idx;
					city_on_path[i] = citys;
					avg_happiness[i] = avg_hap;
				}
				else if (d == dis[i])
				{
					shortest_paths[i] += shortest_paths[idx];
					if (hap > happiness[i])
					{
						happiness[i] = hap;
						path[i] = idx;
						city_on_path[i] = citys;
						avg_happiness[i] = avg_hap;
					}
					else if (hap == happiness[i] && citys < city_on_path[i])
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
		shortest_paths[i] = 0;
	}

	dis[0] = 0;
	happiness[0] = 0;
	shortest_paths[0] = 1;
	dijkstra(city_num);

	cout << shortest_paths[city_id["ROM"]] << " " << dis[city_id["ROM"]] << " "
		<< happiness[city_id["ROM"]] << " " << avg_happiness[city_id["ROM"]] << endl;

	PrintPath(city_id["ROM"]);

	system("pause");
	return 0;
}