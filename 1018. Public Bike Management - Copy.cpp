//#include <iostream>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <cmath>
//#include <map>
//#include <algorithm>
//#include <cstdlib>
//#include <fstream>
//#include <iomanip>
//#include <climits>
//
//using namespace std;
///*point：题设的要求是修正最短路径上的所有点，
//实际上必须严格遵循访问顺序修改每个点的权值
//（eg:要依次修改权值分别为3，10的两个点，必须send2back5而非简单地back3)，
//也就是说如果bike数目小于容量的一半的节点，出现在bike数量大于容量一半的节点之前，
//那么必须先send来满足之前的容量，而不能在遍历到后一个节点的时候在回程。
//亦即到达目标点sp后的回程是不能修改的。*/
//
//bool visit[510];
//int edge[510][510] = { 0 };
//int path[510];
//int dis[510];
//int bike_from_pbmc[510];
//int bike_back_pbmc[510];
//int station_bikes[510];
////int min_bikes_need[505];
//
//void ChoosePath(int stations, int capacity)
//{
//	while (true)
//	{
//		int min_val = INT_MAX;
//		int idx = -1;
//		for (int i = 0; i <= stations; i++)
//		{
//			if (!visit[i] && dis[i] < min_val)
//			{
//				min_val = dis[i];
//				idx = i;
//			}
//		}
//
//		if (min_val == INT_MAX)
//		{
//			break;
//		}
//
//		visit[idx] = true;
//
//		for (int i = 0; i <= stations; i++)
//		{
//			if (!visit[i] && edge[idx][i] > 0)
//			{
//				int d = dis[idx] + edge[idx][i];
//				int need = station_bikes[i] + bike_back_pbmc[idx] - (capacity / 2);//因为后一个station的多余bike不能反向弥补给前一个station，而前一个station剩余的bike可以弥补给后一个station
//				int from, back;
//				if (need > 0)
//				{
//					from = bike_from_pbmc[idx];//加上前一次需求的bike
//					back = need;
//				}
//				else
//				{
//					from = bike_from_pbmc[idx] - need;
//					back = 0;
//				}
//				if (d < dis[i])
//				{
//					dis[i] = d;
//					path[i] = idx;
//					bike_from_pbmc[i] = from;
//					bike_back_pbmc[i] = back;
//				}
//				else if (d == dis[i])
//				{
//					if (from < bike_from_pbmc[i])
//					{
//						bike_from_pbmc[i] = from;
//						bike_back_pbmc[i] = back;
//						path[i] = idx;
//					}
//					else if (from == bike_from_pbmc[i])
//					{
//						if (back < bike_back_pbmc[i])
//						{
//							bike_back_pbmc[i] = back;
//							path[i] = idx;
//						}
//					}
//				}
//			}
//		}
//	}
//}
//
//void PrintPath(int cur)
//{
//	if (path[cur] != -1)
//	{
//		PrintPath(path[cur]);
//		cout << "->";
//	}
//	cout << cur;
//}
//
//int main()
//{
//	ifstream in("in.in");
//
//	for (int i = 0; i < 510; i++)
//	{
//		dis[i] = INT_MAX;
//		visit[i] = false;
//		bike_from_pbmc[i] = 0;
//		bike_back_pbmc[i] = 0;
//	}
//
//	int capacity, stations, pro_station, roads;
//	in >> capacity >> stations >> pro_station >> roads;
//
//	for (int i = 1; i <= stations; i++)
//	{
//		in >> station_bikes[i];
//	}
//
//	for (int i = 0; i < roads; i++)
//	{
//		int s, e, cost;
//		in >> s >> e >> cost;
//		edge[s][e] = cost;
//		edge[e][s] = cost;
//	}
//
//	dis[0] = 0;
//	path[0] = -1;
//	ChoosePath(stations, capacity);
//	cout << bike_from_pbmc[pro_station] << " ";
//	PrintPath(pro_station);
//	//各站调解后自行车有多余的情况
//	cout << " " << bike_back_pbmc[pro_station] << endl;
//
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <climits>

using namespace std;

//案例5，7没过

/*point：题设的要求是修正最短路径上的所有点，
实际上必须严格遵循访问顺序修改每个点的权值
（eg:要依次修改权值分别为3，10的两个点，必须send2back5而非简单地back3)，
也就是说如果bike数目小于容量的一半的节点，出现在bike数量大于容量一半的节点之前，
那么必须先send来满足之前的容量，而不能在遍历到后一个节点的时候在回程。
亦即到达目标点sp后的回程是不能修改的。*/

bool visit[505];
int edge[505][505] = { 0 };
int dis[505];
int station_bikes[505];
vector<int> path[505];
vector<int> record_path;
vector<int> min_path;
int min_need_bike = INT_MAX;
int min_back_bike = INT_MAX;

void ChoosePath(int stations, int capacity)
{
	while (true)
	{
		int min_val = INT_MAX;
		int idx = -1;
		for (int i = 0; i <= stations; i++)
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

		for (int i = 0; i <= stations; i++)
		{
			if (!visit[i] && edge[idx][i] > 0)
			{
				int d = dis[idx] + edge[idx][i];
				if (d < dis[i])
				{
					path[i].clear();
					dis[i] = d;
					path[i].push_back(idx);
				}
				else if (d == dis[i])
				{
					path[i].push_back(idx);
				}
			}
		}
	}
}

void FindShortPath(int station, int capacity)
{
	if (0 == station)
	{
		int need_bike = 0;
		int back_bike = 0;
		for (int i = record_path.size() - 2; i >= 0; i--)//i==size - 1,is the index of the pbms
		{
			int station_idx = record_path[i];
			int bikes = station_bikes[station_idx] + back_bike - (capacity / 2);//因为后一个station的多余bike不能反向弥补给前一个station，而前一个station剩余的bike可以弥补给后一个station
			if (bikes > 0)
			{
				back_bike = bikes;
			}
			else
			{
				need_bike += -bikes;
				back_bike = 0;
			}
		}

		if (need_bike < min_need_bike)
		{
			min_need_bike = need_bike;
			min_back_bike = back_bike;
			min_path = record_path;
		}
		else if (need_bike == min_need_bike && back_bike < min_back_bike)
		{
			min_back_bike = back_bike;
			min_path = record_path;
		}
		
		return;
	}

	int size = path[station].size();
	for (int i = 0; i < size; i++)
	{
		record_path.push_back(path[station][i]);
		FindShortPath(path[station][i], capacity);
		record_path.pop_back();
	}
}

int main()
{
	ifstream in("in.in");

	for (int i = 0; i < 505; i++)
	{
		dis[i] = INT_MAX;
		visit[i] = false;
	}

	int capacity, stations, pro_station, roads;
	in >> capacity >> stations >> pro_station >> roads;

	for (int i = 1; i <= stations; i++)
	{
		in >> station_bikes[i];
	}

	for (int i = 0; i < roads; i++)
	{
		int s, e, cost;
		in >> s >> e >> cost;
		edge[s][e] = cost;
		edge[e][s] = cost;
	}

	dis[0] = 0;
	ChoosePath(stations, capacity);
	record_path.push_back(pro_station);
	FindShortPath(pro_station, capacity);

	cout << min_need_bike << " " << 0;
	for (int i = min_path.size() - 2; i >= 0; i--)
	{
		cout << "->" << min_path[i];
	}
	//各站调解后自行车有多余的情况
	cout << " " << min_back_bike << endl;

	system("pause");
	return 0;
}