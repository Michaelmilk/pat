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


////dfs + dij   AC
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
//
////案例5，7没过
//
///*point：题设的要求是修正最短路径上的所有点，
//实际上必须严格遵循访问顺序修改每个点的权值
//（eg:要依次修改权值分别为3，10的两个点，必须send2back5而非简单地back3)，
//也就是说如果bike数目小于容量的一半的节点，出现在bike数量大于容量一半的节点之前，
//那么必须先send来满足之前的容量，而不能在遍历到后一个节点的时候在回程。
//亦即到达目标点sp后的回程是不能修改的。*/
//
//bool visit[505];
//int edge[505][505] = { 0 };
//int dis[505];
//int station_bikes[505];
//vector<int> path[505];
//vector<int> record_path;
//vector<int> min_path;
//int min_need_bike = INT_MAX;
//int min_back_bike = INT_MAX;
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
//				if (d < dis[i])
//				{
//					path[i].clear();
//					dis[i] = d;
//					path[i].push_back(idx);
//				}
//				else if (d == dis[i])
//				{
//					path[i].push_back(idx);
//				}
//			}
//		}
//	}
//}
//
//void FindShortPath(int station, int capacity)
//{
//	if (0 == station)
//	{
//		int need_bike = 0;
//		int back_bike = 0;
//		for (int i = record_path.size() - 2; i >= 0; i--)//i==size - 1,is the index of the pbms
//		{
//			int station_idx = record_path[i];
//			int bikes = station_bikes[station_idx] + back_bike - (capacity / 2);//因为后一个station的多余bike不能反向弥补给前一个station，而前一个station剩余的bike可以弥补给后一个station
//			if (bikes > 0)
//			{
//				back_bike = bikes;
//			}
//			else
//			{
//				need_bike += -bikes;
//				back_bike = 0;
//			}
//		}
//
//		if (need_bike < min_need_bike)
//		{
//			min_need_bike = need_bike;
//			min_back_bike = back_bike;
//			min_path = record_path;
//		}
//		else if (need_bike == min_need_bike && back_bike < min_back_bike)
//		{
//			min_back_bike = back_bike;
//			min_path = record_path;
//		}
//		
//		return;
//	}
//
//	int size = path[station].size();
//	for (int i = 0; i < size; i++)
//	{
//		record_path.push_back(path[station][i]);
//		FindShortPath(path[station][i], capacity);
//		record_path.pop_back();
//	}
//}
//
//int main()
//{
//	ifstream in("in.in");
//
//	for (int i = 0; i < 505; i++)
//	{
//		dis[i] = INT_MAX;
//		visit[i] = false;
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
//	ChoosePath(stations, capacity);
//	record_path.push_back(pro_station);
//	FindShortPath(pro_station, capacity);
//
//	cout << min_need_bike << " " << 0;
//	for (int i = min_path.size() - 2; i >= 0; i--)
//	{
//		cout << "->" << min_path[i];
//	}
//	//各站调解后自行车有多余的情况
//	cout << " " << min_back_bike << endl;
//
//	system("pause");
//	return 0;
//}

//为了消除贪心算法的后效性，将dij改成逆向，使用DP的思想找出路径
#include <iostream>
#include <vector>
#include <climits>
#include <Windows.h>

using namespace std;

const int N = 500 + 5;
int cap, n, sp, m;
int bikes[N];
vector<pair<int, int> > e[N];
int need[N], back[N];
int vis[N], dis[N], path[N];
bool first;

void dij()
{
	dis[sp] = sp;//将终点的dis值设置为大于零，其他的值全部小于零
	//根据终点的自行车数来设置need和back的值
	need[sp] = max(0, cap / 2 - bikes[sp]);
	back[sp] = max(0, bikes[sp] - cap / 2);

	//for (int ca = 0; ca<n; ca++)
	while (true)
	{
		int min_val = INT_MAX, idx = -1;//mi
		for (int i = 0; i < n; i++)
		{
			//(min_val < 0 || dis[i] < min_val)
			//第一次进入if的时候，min_val = -1，是的条件成立
			//后来进入if后，由于min_val中保存的值是之前值中的最小值
			//if (!vis[i] && dis[i] >= 0 && (min_val < 0 || dis[i] < min_val))
			if (!vis[i] && dis[i] < min_val)
			{
				min_val = dis[i];
				idx = i;
			}
		}

		if (idx == -1)//如果所有点都访问了，则跳出遍历
		{
			break;
		}

		vis[idx] = 1;

		//如果只有0节点没有访问，其实0节点的最短路径，
		//need和back其实已经由和它相连的后面的点计算了
		if (idx == 0)//如果已经到达起点，就可以返回了
		{
			return;
		}

		for (int i = 0; i < e[idx].size(); i++)
		{
			int v = e[idx][i].first;
			int w = e[idx][i].second;
			if (!vis[v]){
				int nd = need[idx], bk = back[idx];
				//由于是从后往前查找，所以bk中的值不能用来弥补当前节点对车辆的需求，
				//因为后面多余的车辆是不能拿来弥补前面的不足的车辆的。
				//然而，当前站点如果有车辆多余，则可以用来弥补后面站点缺少的车辆，
				//所以x>0的时候，nd -=x；
				int x = bikes[v] - cap / 2;
				if (x >= 0)//more to back
				{
					if (x > nd)
					{
						bk += x - nd;
						nd = 0;
					}
					else
					{
						nd -= x;
					}
				}
				else //need
				{
					nd += -x;
				}

				//通过dis[v]<0来判断该站点是否被遍历过
				//判断的先后顺序，先路径长度，再nd的值，最后才是
				if (dis[idx] + w < dis[v]
					|| dis[idx] + w == dis[v] && nd < need[v]
					|| dis[idx] + w == dis[v] && nd == need[v] && bk < back[v])
				{
					dis[v] = dis[idx] + w;
					need[v] = nd;
					back[v] = bk;
					path[v] = idx;//记录当前站点的后一个站点
				}
			}
		}
	}
}

int main()
{
	cin >> cap >> n >> sp >> m;
	n++;
	for (int i = 1; i < n; i++)
	{
		cin >> bikes[i];
	}
		
	for (int i = 0; i<m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		if (w <= 0)
			return -1;
		e[a].push_back(make_pair(b, w));
		e[b].push_back(make_pair(a, w));
	}

	for (int i = 0; i<n; i++)
	{
		dis[i] = INT_MAX;
		need[i] = back[i] = 0;
	}
	bikes[0] = cap / 2;
	dij();
	cout << need[0] << " ";
	int i = 0;
	while (i != sp){
		cout << i << "->";
		i = path[i];
	}
	cout << sp << " " << back[0] << endl;
	return 0;
}
