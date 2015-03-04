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
	wait_time = c.serve_time - c.arr_time;//count值已经变化
	if(wait_time % 60 >= 30)
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
		custmers[i].wait_time = 0;
	}

	sort(custmers.begin(), custmers.end());

	// for(int i = 0; i < custmer_num; i++)
	// {
	// 	cout << custmers[i].arrive_time << endl;
	// }

	queue<int> vip_que;
	queue<int> ord_que;
	for(int i = 0; i < custmer_num; i++)
	{
		if (custmers[i].vip)
		{
			vip_que.push(i);
			continue;
		}
		ord_que.push(i);
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
	//vector<int> leave_time(table_num + 1, 0);
	//vector<queue<int> > ord_table_que(ord_table_num);
	//vector<int> ord_leave_time(ord_table_num, 0);
	//vector<queue<int> > vip_table_que(vip_table_num);
	//vector<int> vip_leave_time(vip_table_num, 0);
	int count = 0;
	//cout << "-----" << endl;
	while(!ord_que.empty() || !vip_que.empty())
	{
		if(count >= k_opentime)
		{
			break;
		}
		//cout << "--21---" << endl;
		for(int i = 1; i <= table_num; i++)
		{
			if (!table_que[i].empty()
				&& ((count - custmers[table_que[i].front()].serve_time) >= custmers[table_que[i].front()].play_time * 60
				|| (count - custmers[table_que[i].front()].serve_time) >= 7200))
			{
				table_que[i].pop();
				//leave_time[i] = count;
			}
			//if (!table_que[i].empty() && (count - leave_time[i] - custmers[table_que[i].front()].arr_time) == custmers[table_que[i].front()].play_time * 60)
			//{
			//	table_que[i].pop();
			//	leave_time[i] = count;
			//}
			//cout << "-11----" << endl;
		}

		//cout << "--22---" << endl;
		
		//cout << que.front() << " " << custmers[que.front()].arrive_time << " " << custmers[que.front()].arr_time << " " << count << endl;
		while ((!ord_que.empty() && custmers[ord_que.front()].arr_time <= count) || (!vip_que.empty() && custmers[vip_que.front()].arr_time <= count))
		{
			bool is_assign = false;
			//bool is_vip_assign = false;
			//bool is_ord_assign = false;
			//int idx;
			int o_idx = -1;
			int v_idx = -1;
			if (!ord_que.empty() && !vip_que.empty() && custmers[ord_que.front()].arr_time <= count && custmers[vip_que.front()].arr_time <= count)
			{
				o_idx = ord_que.front();
				v_idx = vip_que.front();
			}
			else if (!ord_que.empty() && custmers[ord_que.front()].arr_time <= count)
			{
				o_idx = ord_que.front();
			}
			else if (!vip_que.empty() && custmers[vip_que.front()].arr_time <= count)
			{
				v_idx = vip_que.front();
			}
			//bool vip_assigned = false;
			
			//if (v_idx != -1 && custmers[v_idx].arr_time < custmers[o_idx].arr_time)
			if (v_idx != -1)
			{
				for(int i = 0; i < vip_table_num; i++)
				{
					int vip_idx = vip_tables[i];
					if(table_que[vip_idx].empty())
					{
						table_que[vip_idx].push(v_idx);
						table_srv_players[vip_idx]++;
						vip_que.pop();
						custmers[v_idx].serve_time = count;
						//vip_assigned = true;
						is_assign = true;
						break;
					}
				}
				if (!is_assign && (o_idx == -1 || (o_idx != -1 && custmers[v_idx].arr_time < custmers[o_idx].arr_time)))
				{
					for (int i = 0; i < ord_table_num; i++)
					{
						int ord_idx = ord_tables[i];
						if (table_que[ord_idx].empty())
						{
							table_que[ord_idx].push(v_idx);
							table_srv_players[ord_idx]++;
							vip_que.pop();
							custmers[v_idx].serve_time = count;
							is_assign = true;
							break;
						}
					}
				}

				if (is_assign)//vip安排完成后直接进入下一轮安排， 避免vip_que中下一个成员来的比ord_que当前成员来得早，却被ord_que中的成员抢了vip的位置
				{
					continue;
				}
			}

			if (o_idx != -1)
			{
				for (int i = 0; i < ord_table_num; i++)
				{
					int ord_idx = ord_tables[i];
					if (table_que[ord_idx].empty())
					{
						table_que[ord_idx].push(o_idx);
						table_srv_players[ord_idx]++;
						ord_que.pop();
						custmers[o_idx].serve_time = count;
						is_assign = true;
						break;
					}
				}

				if (!is_assign)//当前vip成员找到桌子，vip队列中的下一个成员比当前非vip成员来得早，这时候不能让普通成员抢到vip桌子---未解决
				{
					for (int i = 0; i < vip_table_num; i++)
					{
						int vip_idx = vip_tables[i];
						if (table_que[vip_idx].empty())
						{
							table_que[vip_idx].push(o_idx);
							table_srv_players[vip_idx]++;
							ord_que.pop();
							custmers[o_idx].serve_time = count;
							//vip_assigned = true;
							is_assign = true;
							break;
						}
					}
				}
			}
			if (!is_assign)
			{
				break;
			}
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
