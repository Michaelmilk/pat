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
///*point�������Ҫ�����������·���ϵ����е㣬
//ʵ���ϱ����ϸ���ѭ����˳���޸�ÿ�����Ȩֵ
//��eg:Ҫ�����޸�Ȩֵ�ֱ�Ϊ3��10�������㣬����send2back5���Ǽ򵥵�back3)��
//Ҳ����˵���bike��ĿС��������һ��Ľڵ㣬������bike������������һ��Ľڵ�֮ǰ��
//��ô������send������֮ǰ���������������ڱ�������һ���ڵ��ʱ���ڻس̡�
//�༴����Ŀ���sp��Ļس��ǲ����޸ĵġ�*/
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
//				int need = station_bikes[i] + bike_back_pbmc[idx] - (capacity / 2);//��Ϊ��һ��station�Ķ���bike���ܷ����ֲ���ǰһ��station����ǰһ��stationʣ���bike�����ֲ�����һ��station
//				int from, back;
//				if (need > 0)
//				{
//					from = bike_from_pbmc[idx];//����ǰһ�������bike
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
//	//��վ��������г��ж�������
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

//����5��7û��

/*point�������Ҫ�����������·���ϵ����е㣬
ʵ���ϱ����ϸ���ѭ����˳���޸�ÿ�����Ȩֵ
��eg:Ҫ�����޸�Ȩֵ�ֱ�Ϊ3��10�������㣬����send2back5���Ǽ򵥵�back3)��
Ҳ����˵���bike��ĿС��������һ��Ľڵ㣬������bike������������һ��Ľڵ�֮ǰ��
��ô������send������֮ǰ���������������ڱ�������һ���ڵ��ʱ���ڻس̡�
�༴����Ŀ���sp��Ļس��ǲ����޸ĵġ�*/

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
			int bikes = station_bikes[station_idx] + back_bike - (capacity / 2);//��Ϊ��һ��station�Ķ���bike���ܷ����ֲ���ǰһ��station����ǰһ��stationʣ���bike�����ֲ�����һ��station
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
	//��վ��������г��ж�������
	cout << " " << min_back_bike << endl;

	system("pause");
	return 0;
}