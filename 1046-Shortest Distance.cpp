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

//TLE
/*struct Route
{
	int s;
	int e;
};

void ShortestDis(int road_num, int city_pair_num, vector<int> &road, vector<Route> &route)
{
	for(int i = 0; i < city_pair_num; i++)
	{
		int min_val = route[i].s < route[i].e ? route[i].s : route[i].e;
		int max_val = route[i].s < route[i].e ? route[i].e : route[i].s;
		
		int discw = 0;
		for(int i = min_val - 1; i < max_val - 1; i++)
		{
			discw += road[i];
		}

		int disanticw = 0;
		for(int i = 0; i < min_val - 1; i++)
		{
			disanticw += road[i];
		}
		for(int i = max_val - 1; i < road_num; i++)
		{
			disanticw += road[i];
		}

		cout << min(discw, disanticw) << endl;
	}
}

int main()
{
	ifstream in("in.in");

	int road_num;
	in >> road_num;

	vector<int> road(road_num, 0);
	for(int i = 0; i < road_num; i++)
	{
		in >> road[i];
	}

	int city_pair_num;
	in >> city_pair_num;
	vector<Route> route(city_pair_num);
	for(int i = 0; i < city_pair_num; i++)
	{
		in >> route[i].s >> route[i].e;
	}

	ShortestDis(road_num, city_pair_num, road, route);

	system("pause");
	return 0;
}*/

int main()
{
	ifstream in("in.in");

	int road_num;
	in >> road_num;

	vector<int> road(road_num, 0);
	vector<int> dis(road_num + 1, 0);
	int sum = 0;
	for(int i = 0; i < road_num; i++)
	{
		in >> road[i];
		sum += road[i];
		dis[i + 1] = dis[i] + road[i];
	}

	int city_pair_num;
	in >> city_pair_num;
	for(int i = 0; i < city_pair_num; i++)
	{
		int s, e, shorest_dis;
		in >> s >> e;
		shorest_dis = dis[max(s, e) - 1] - dis[min(s, e) - 1];
		cout << min(shorest_dis, sum - shorest_dis) << endl;
	}

	system("pause");
	return 0;
}