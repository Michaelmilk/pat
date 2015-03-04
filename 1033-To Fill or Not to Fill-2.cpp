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
#include <cfloat>


using namespace std;

struct GaxStation
{
	double price;
	int dis;
	bool operator<(const GaxStation &gs) const
	{
		return dis < gs.dis;
	}
};


int main()
{
	ifstream in("in.in");

	int max_capacity, distance, dis_per_gas, station_num;
	in >> max_capacity >> distance >> dis_per_gas >> station_num;

	vector<GaxStation> stations(station_num);
	for(int i = 0; i < station_num; i++)
	{
		in >> stations[i].price >> stations[i].dis;
	}

	sort(stations.begin(), stations.end());

	double cost = 0;
	double min_greater_price = DBL_MAX;
	//double min_less_price = DBL_MAX;
	double precious_capacity = 0;
	int greater_idx;
	int max_distance = dis_per_gas * max_capacity;
	GaxStation next_station;
	next_station.dis = distance;
	next_station.price = -1;
	for(int i = station_num - 1; i >= 0; i--)
	{
		int d = next_station.dis - stations[i].dis;
		if(d > max_distance)
		{
			cout << The maximum travel distance = << fixed << setprecision(2) 
			<< stations[i].dis + max_distance << endl;
			system("pause");
			return 0;
		}
		
		if(stations[i].price < next_station.price)
		{
			precious_capacity = 0;
			cost += (double)(stations[i].dis - next_station.dis) / dis_per_gas * next_station.price;
			next_station = stations[i];
		}
		else if(stations[i].price > next_station.price)
		{
			if(min_greater_price > stations[i].price)
			{
				min_greater_price = stations[i].price;
				greater_idx = i;
			}
		}
		
	}

	cout << fixed << setprecision(2) << cost << endl;

	system("pause");
	return 0;
}