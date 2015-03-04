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
#include <queue>

using namespace std;

struct Customer
{
	string come_time;
	int server_time;
	int state;
	bool operator<(const Customer &cst) const
	{
		return come_time > cst.come_time;
	}
};

priority_queue<Customer> wait_queue;

int InitialSrvTime(string time)
{
	int initial = 0;
	if (time <= "08:00:00")
	{
		return 0;
	}
	else
	{
		int hour, minute, second;
		hour = atoi((time.substr(0, 2)).c_str());
		minute = atoi((time.substr(3, 2)).c_str());
		second = atoi((time.substr(6, 2)).c_str());
		initial = hour * 3600 + minute * 60 + second - 8 * 3600;
	}
	return initial;
}

int CountSec(string time, int pass_time)
{
	int sec_count = 0;
	int hour, minute, second;
	int base = 8 * 3600;
	int now;

	if (pass_time == 0 && time >= "08:00:00")
	{
		sec_count += 0;
	}
	else
	{
		base += pass_time;
		hour = atoi((time.substr(0, 2)).c_str());
		minute = atoi((time.substr(3, 2)).c_str());
		second = atoi((time.substr(6, 2)).c_str());
		now = hour * 3600 + minute * 60 + second;
		sec_count += abs(base - now);
	}

	return sec_count;
}

int IsCustomerCome(string time, int count)
{
	int hour, minute, second;
	hour = atoi((time.substr(0, 2)).c_str());
	minute = atoi((time.substr(3, 2)).c_str());
	second = atoi((time.substr(6, 2)).c_str());
	int base = hour * 3600 + minute * 60 + second;//客户来的时间
	if (base < (8 * 3600 + count))
	{
		return 1;
	}
	else if (base == (8 * 3600 + count))
	{
		return 2;
	}
	return 0;
}

double ComputerAverWaitTime(int win_num, int person_num, vector<Customer>  &sev_customer)
{
	vector<int> leave_time(win_num, 0);
	double total_wait_time = 0;
	for (int i = 0; i < win_num; i++)
	{
		if (!wait_queue.empty())
		{
			sev_customer[i] = wait_queue.top();
			wait_queue.pop();
			total_wait_time += CountSec(sev_customer[i].come_time, 0);
			leave_time[i] = InitialSrvTime(sev_customer[i].come_time);
		}
	}

	int time_count = 0;
	int srvd_num = 0;
	while (true)
	{
		time_count++;
		if (srvd_num == person_num)
		{
			break;
		}
		//窗口服务完了，客户却还没有到,此时客户来了不需要等
		//2 1
		//08:03 : 24 1
		//08 : 05 : 00 9
		for (int i = 0; i < win_num; i++)
		{
			if (sev_customer[i].state == 3)
			{
				if (IsCustomerCome(sev_customer[i].come_time, time_count) == 2)
				{
					sev_customer[i].state = 1;//客户已经到达
					leave_time[i] = time_count;//上一个客户离开的时间就是当前时间，因为是窗口等客户，客户不需要等待
				}
				else
				{
					continue;
				}
			}
			

			if (sev_customer[i].state == 1 && sev_customer[i].server_time * 60 == time_count - leave_time[i])
			{
				srvd_num++;
				leave_time[i] = time_count;
				sev_customer[i].state = 0;//表明已经服务过，不然wait_queue中没有元素的时候，sev_customer[i]会被再次服务
				if (!wait_queue.empty())
				{
					Customer cst;
					cst = wait_queue.top();
					sev_customer[i] = cst;
					wait_queue.pop();
					if (IsCustomerCome(cst.come_time, time_count) == 0)
					{
						sev_customer[i].state = 3;//user dont come
						continue;
					}
				
					total_wait_time += CountSec(sev_customer[i].come_time, time_count);
					
				}
			}
		}
	}

	return total_wait_time / (person_num * 60);
}

int main()
{
	ifstream in("in.in");

	int person_num;
	int win_num;
	in >> person_num >> win_num;

	vector<Customer> sev_customer(win_num);
	int count = 0;
	for (int i = 0; i < person_num; i++)
	{
		Customer cst;
		in >> cst.come_time;
		in >> cst.server_time;
		cst.state = 1;
		if (cst.come_time >= "17:00:01")
		{
			continue;
		}
		wait_queue.push(cst);
		count++;
	}

	if (0 == count)
	{
		
		cout << setiosflags(ios::fixed);
		cout << setprecision(1) << (double)0 << endl;
		cout << setprecision(6);
		return 0;
	}

	double ave_time = ComputerAverWaitTime(win_num, count, sev_customer);

	cout << setiosflags(ios::fixed);
	cout << setprecision(1) << ave_time << endl;
	cout << setprecision(6);
	system("pause");
	return 0;
}