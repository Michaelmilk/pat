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
	double dis;
	bool operator<(const GaxStation &gs) const
	{
		return dis < gs.dis;
	}
};


int main()
{
	ifstream in("in.in");

	double max_capacity, distance, dis_per_gas;
  	int station_num;
	in >> max_capacity >> distance >> dis_per_gas >> station_num;

	vector<GaxStation> stations(station_num);
	for(int i = 0; i < station_num; i++)
	{
		in >> stations[i].price >> stations[i].dis;
	}

	if(distance == 0)
	{
		cout << fixed << setprecision(2) << (double)0 << endl;
		system("pause");
		return 0;
	}

	sort(stations.begin(), stations.end());

	if(stations[0].dis != 0)//!!!!!!!!!!!!!
	{
		cout << "The maximum travel distance = " << fixed << setprecision(2) << (double)0 << endl;
				system("pause");
				return 0;
	}

	double cost = 0;
	int idx = 0;
	double cur_gas = 0;
	double max_distance = dis_per_gas * max_capacity;
	while(true)
	{
		bool have_station = false;//whether the max distance have stations
		bool have_cheaper_station = false;//whether the max distance have cheapter stations
		double cheaper_price = DBL_MAX;
		int cheaper_station;
		for(int i = idx + 1; i < station_num; i++)
		{
			double d = stations[i].dis - stations[idx].dis;
			if(d <= max_distance)
			{
				have_station = true;
				if(stations[i].price < stations[idx].price)
				{
					have_cheaper_station = true;
					double need_gas = d / dis_per_gas - cur_gas;
					cost += need_gas * stations[idx].price;
					idx = i;
					cur_gas = 0;//the remain gas when arrival the i station
					break;
				}
				else if(stations[i].price < cheaper_price)
				{
					cheaper_price = stations[i].price;
					cheaper_station = i;
				}
			}
			else
			{
				break;
			}
		}

		if(!have_cheaper_station && max_distance >= distance - stations[idx].dis)
		{
			double d = distance - stations[idx].dis;
			double need_gas = d / dis_per_gas - cur_gas;
			cost += need_gas * stations[idx].price;
			cout << fixed << setprecision(2) << cost << endl;
			system("pause");
			return 0;
		}

		if(!have_cheaper_station && have_station)
		{
			double d = stations[cheaper_station].dis - stations[idx].dis;
			double need_gas = max_capacity - cur_gas;
			cost += need_gas * stations[idx].price;
			cur_gas = max_capacity - d / dis_per_gas;
			idx = cheaper_station;
		}
		else if(!have_station)
		{
			cout << "The maximum travel distance = " << fixed << setprecision(2) 
				<< stations[idx].dis + max_distance << endl;
				system("pause");
				return 0;
		}
	}

	system("pause");
	return 0;
}