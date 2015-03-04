#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <sstream>

using namespace std;

struct Customer
{
	int id;
	int servertime;
	int leavetime;
};

Customer customer[1005];

string FormatTime(int time)
{
	string ans;
	int hour = time / 60;
	int minute = time % 60;

	stringstream s;
	s << (hour + 8);
	ans = hour < 2 ? "0" + s.str() : s.str();
	s.str("");
	ans += ":";
	s << minute;
	ans += minute < 10 ? "0" + s.str() : s.str();

	return ans;
}

void ComputeLeaveTime(int winnum, int quelen, int customernum)
{
	vector<deque<int> > que(winnum);
	deque<int> people;
	int id = 0;
	for (int k = 0; k < quelen; k++)
	{
		for (int i = 0; i < winnum && id < customernum; i++)
		{
			que[i].push_back(id++);
		}
		if (id == customernum)
		{
			break;
		}
	}
	
	for (int i = quelen * winnum; i < customernum; i++)
	{
		people.push_back(i);
	}

	vector<int> quetime(winnum, 0);
	int timer = 0;
	int servernum = 0;
	while (true)
	{
		timer++;
		//if (timer > 540 || servernum == customernum)
		if (servernum == customernum)
		{
			break;
		}

		for (int i = 0; i < winnum; i++)
		{
			if (!que[i].empty())
			{
				int idx = que[i].front();
				if(customer[idx].servertime == (timer - quetime[i]))
				{
					customer[idx].leavetime = timer;
					que[i].pop_front();
					servernum++;
					quetime[i] = timer;
				
					if (!people.empty())
					{
						int next = people.front();
						people.pop_front();
						que[i].push_back(next);
					}
				}
			}
		}
	}
	
}

int main()
{
	ifstream in("in.in");

	//int totoalmin = 540;
	int winnum, quelen, customernum, querynum;
	in >> winnum >> quelen >> customernum >> querynum;

	for (int i = 0; i < customernum; i++)
	{
		in >> customer[i].servertime;
		customer[i].leavetime = -1;
	}

	ComputeLeaveTime(winnum, quelen, customernum);

	for (int i = 0; i < querynum; i++)
	{
		int id;
		in >> id;
		if (customer[id - 1].leavetime - customer[id - 1].servertime >= 540)
		{
			cout << "Sorry" << endl;
		}
		else
		{
			cout << FormatTime(customer[id - 1].leavetime) << endl;
		}
		
	}

	return 0;
}
