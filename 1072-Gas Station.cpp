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

using namespace std;

ifstream in("in.in");
#define cin in

const int k_num = 2000;

struct Gas_Station
{
	int id;
	double short_dis;
	double aver_dis;
	bool operator <(const Gas_Station &gs) const
	{
		if(short_dis != gs.short_dis)
		{
			return short_dis > gs.short_dis;
		}
		else if(aver_dis != gs.aver_dis)
		{
			return aver_dis < gs.aver_dis;
		}
		else
		{
			return id < gs.id;
		}
	}
};

int dis[k_num];
bool vst[k_num];
int graphic[k_num][k_num];
map<string, int> location_to_num;

//编号有可能是两位数，因为location<=10,而home_num<= 1000
//所以不能仅仅使用 s[i]-'0'来解决！！
int GetIdx(int home_num, string s)
{
	int idx;
	int len = s.length();
	stringstream ss;
	if(s[0] == 'G')
	{
		s = s.substr(1);
		ss << s;
		ss >> idx;
		idx += home_num;
	}
	else
	{
		ss << s;
		ss >> idx;
	}
	return idx;
}

void dijkstra(int home_num, int gas_location_num)
{
	while(true)
	{
		int min_val = INT_MAX;
		int idx = -1;
		for(int i = 1; i <= home_num + gas_location_num; i++)
		{
			if(!vst[i] && dis[i] < min_val)
			{
				idx = i;
				min_val = dis[i];
			}
		}

		if(idx == -1)
		{
			break;
		}

		vst[idx] = true;

		for(int i = 1; i <= home_num + gas_location_num; i++)
		{
			if(!vst[i] && graphic[idx][i] > 0)
			{
				int d = dis[idx] + graphic[idx][i];
				if(d < dis[i])
				{
					dis[i] = d;
				}
			}
		}
	}
	
}

int main()
{
	int home_num, gas_location_num, road_num, service_range;
	cin >> home_num >> gas_location_num >> road_num >> service_range;

	for(int i  = 0; i < road_num; i++)
	{
		string s, e;
		int w;
		cin >> s >> e >> w;
		int start, end;
		start = GetIdx(home_num, s);
		end = GetIdx(home_num, e);
		graphic[start][end] = w;
		graphic[end][start] = w;
	}

	vector<vector<int> > gas_stations(gas_location_num, vector<int>());
	for(int i = 0; i < gas_location_num; i++)
	{
		for(int j = 0; j <= home_num + gas_location_num; j++)
		{
			dis[j] = INT_MAX;
		}
		memset(vst, 0, k_num);
		dis[home_num + i + 1] = 0;
		//cout << "-------"<< endl;
		dijkstra(home_num, gas_location_num);
		for(int k = 1; k <= home_num; k++)
		{
			//cout << k << " " << dis[k] << "  " << home_num << endl;
			if(dis[k] > service_range)
			{
				gas_stations[i].clear();
				break;
			}
			gas_stations[i].push_back(dis[k]);
		}
	}

	vector<Gas_Station> station;
	for(int i = 0; i < gas_location_num; i++)
	{
		Gas_Station gs;
		int min_val = INT_MAX;
		int count = 0;
		//cout << i << " " << gas_stations[i].size() << endl;
		if(gas_stations[i].size() == 0)
		{
			continue;
		}
		for(int j = 0; j < home_num; j++)
		{ 
			if(gas_stations[i][j] < min_val)
			{
				min_val = gas_stations[i][j];
			}
			count += gas_stations[i][j];
		}
		gs.id = i + 1;
		gs.short_dis = min_val;
		gs.aver_dis = (double)count / home_num;
		station.push_back(gs);
	}

	int size = station.size();
	//cout << size << endl;
	if(size == 0)
	{
		cout <<  "No Solution" << endl;
	}
	else
	{
		if(size > 1)
		{
			sort(station.begin(), station.end());
		}
		
		cout << "G" << station[0].id << endl;
		cout << fixed << setprecision(1) << station[0].short_dis << " " << station[0].aver_dis << endl;
	}
	system("pause");
	return 0;
}