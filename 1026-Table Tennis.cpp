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


using namespace std;

ifstream in("in.in");
#define cin in

const int k_opentime = 13 * 3600;

struct Custmer
{
	int arr_time;
	string arrive_time;
	int serve_time;
	string s_time;
	int play_time;
	int wait_time;
	int vip;

	bool operator<(const Custmer &c) const
	{
		return arr_time < c.arr_time;
	}
};

struct Table
{
	int id;
	int vip;
	//Table() : vip(0){};
};

bool cmp(const Custmer &c1, const Custmer &c2)
{
	return c1.serve_time < c2.serve_time;
}

int ConvertTimeToSec(string t)
{
	stringstream ss;
	int hour, minute, second;
	string tmp = t.substr(0, 2);
	ss << tmp;
	ss >> hour;
	ss.clear();
	tmp = t.substr(3, 2);
	ss << tmp;
	ss >> minute;
	ss.clear();
	tmp = t.substr(6, 2);
	ss << tmp;
	ss >> second;
	int count = (hour - 8) * 3600 + minute * 60 +second;
	return count;
}

void ConvertTime(Custmer &c)
{
	int wait_time = 0;
	int count = c.serve_time;
	int hour, minute, second;
	hour = count / 3600;
	count %= 3600;
	minute = count / 60;
	second = count % 60;
	stringstream ss;
	wait_time = count - c.arr_time;;
	if(wait_time % 60)
	{
		c.wait_time = 1;
	}
	c.wait_time += wait_time / 60;
	string h, m, s;
	ss.clear();
	ss << (hour + 8);
	ss >> h;
	if(8 + hour < 10)
	{
		h = "0" + h;
	}
	
	ss.clear();
	ss << minute;
	ss >> m;
	if(minute < 10)
	{
		m = "0" + m;
	}

	ss.clear();
	ss << second;
	ss >> s;
	if(second < 10)
	{
		s = "0" + s;
	}

	c.s_time = h + ":" + m + ":" + s;
}

int main()
{
	int custmer_num;
	cin >> custmer_num;

	vector<Custmer> custmers(custmer_num);
	for(int i = 0; i < custmer_num; i++)
	{
		cin >> custmers[i].arrive_time >> custmers[i].play_time >> custmers[i].vip;
		custmers[i].serve_time = -1;
		custmers[i].arr_time = ConvertTimeToSec(custmers[i].arrive_time);
	}

	sort(custmers.begin(), custmers.end());

	// for(int i = 0; i < custmer_num; i++)
	// {
	// 	cout << custmers[i].arrive_time << endl;
	// }

	queue<int> que;
	for(int i = 0; i < custmer_num; i++)
	{
		que.push(i);
	}

	//cout << que.front() << endl;

	int table_num, vip_table_num;
	cin >> table_num >> vip_table_num;

	vector<Table> table(table_num + 1);
	for(int i  = 1; i <= table_num; i++)
	{
		table[i].id = i;
		table[i].vip = 0;
	}

	
	vector<int> vip_tables(vip_table_num);
	for(int i = 0; i < vip_table_num; i++)
	{
		cin >> vip_tables[i];
		table[vip_tables[i]].vip = 1;
	}

	vector<int> ord_tables;
	for(int i = 1; i <= table_num; i++)
	{
		if(table[i].vip == 0)
		{
			ord_tables.push_back(i);
		}
	}
	
	int ord_table_num = table_num - vip_table_num;
	vector<int> table_srv_players(table_num + 1, 0);
	vector<queue<int> > table_que(table_num + 1);
	//for(int i = 0; i < table_num)
	vector<int> leave_time(table_num + 1, 0);
	//vector<queue<int> > ord_table_que(ord_table_num);
	//vector<int> ord_leave_time(ord_table_num, 0);
	//vector<queue<int> > vip_table_que(vip_table_num);
	//vector<int> vip_leave_time(vip_table_num, 0);
	int count = 0;
	//cout << "-----" << endl;
	while(true)
	{
		if(count >= k_opentime)
		{
			break;
		}
		//cout << "--21---" << endl;
		for(int i = 1; i <= table_num; i++)
		{
			if(!table_que[i].empty() && (count - leave_time[i]) == custmers[table_que[i].front()].play_time * 60)
			{
				table_que[i].pop();
				leave_time[i] = count;
			}
			//cout << "-11----" << endl;
		}

		//cout << "--22---" << endl;
		int idx;
		//cout << que.front() << " " << custmers[que.front()].arrive_time << " " << custmers[que.front()].arr_time << " " << count << endl;
		while(!que.empty() && custmers[que.front()].arr_time <= count)
		{
			bool vip_assigned = false;

			if(custmers[idx].vip == 1)
			{
				for(int i = 0; i < vip_table_num; i++)
				{
					int vip_idx = vip_tables[i];
					if(table_que[vip_idx].empty())
					{
						table_que[vip_idx].push(idx);
						table_srv_players[vip_idx]++;
						que.pop();
						custmers[idx].serve_time = count - custmers[idx].arr_time;
						vip_assigned = true;
						break;
					}
				}
				continue;
			}

			for(int i = 0; i < ord_table_num; i++)
			{
				if(table_que[ord_tables[i]].empty())
				{
					table_que[i].push(idx);
					table_srv_players[i]++;
					que.pop();
					custmers[idx].serve_time = count;
				}
			}
			idx = que.front();
		}
		count++;
	}


	sort(custmers.begin(), custmers.end(), cmp);

	for(int i = 0; i < custmer_num; i++)
	{
		if(custmers[i].serve_time != -1)
		{
			ConvertTime(custmers[i]);
			cout << custmers[i].arrive_time << " " << custmers[i].s_time << " " << custmers[i].wait_time << endl;
		}
	}

	for(int i = 1; i <= table_num; i++)
	{
		cout << table_srv_players[i] << (i == table_num ? "\n" : " ");
	}

	system("pause");
	return 0;
}