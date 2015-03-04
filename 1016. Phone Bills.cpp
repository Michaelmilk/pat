#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

using namespace std;

struct TimeAndPrice
{
	int time;
	double price;

};

struct DateTag
{
	string date;
	string tag;
	bool operator<(const DateTag &d) const
	{
		return date < d.date;
	}
};

struct Person
{
	string name;
	vector<DateTag> start_time;
	vector<DateTag> end_time;
};

int price_per_minute[24];
int price_per_hours[24];
int price_per_day;


vector<TimeAndPrice> ComputeTimePrice(Person &p)
{
	vector<TimeAndPrice> ans;
	int size = p.start_time.size();
	TimeAndPrice tp;
	for (int i = 0; i < size; i++)
	{
		string ss = p.start_time[i].date;
		int start, end;
		int days1 = atoi((ss.substr(0, 2)).c_str());
		int hours1 = atoi((ss.substr(3, 2)).c_str());
		int minutes1 = atoi((ss.substr(6, 2)).c_str());
		start = (days1 - 1) * 24 * 60 + hours1 * 60 + minutes1;
		ss = p.end_time[i].date;
		int days2 = atoi((ss.substr(0, 2)).c_str());
		int hours2 = atoi((ss.substr(3, 2)).c_str());
		int minutes2 = atoi((ss.substr(6, 2)).c_str());
		end = (days2 - 1) * 24 * 60 + hours2 * 60 + minutes2;

		double total_price = 0;
		if (days1 < days2)
		{
			if (hours1 < hours2)
			{
				total_price += price_per_day * (days2 - days1);
			}
			else
			{
				total_price += price_per_day * (days2 - days1 - 1);//ÉÙËãÒ»Ìì
				hours2 += 24;
			}
		}
		total_price += hours1 == hours2 ? price_per_minute[hours1] * (minutes2 - minutes1) : price_per_minute[hours1] * (60 - minutes1) + price_per_minute[hours2 % 24] * minutes2;
		for (int i = hours1 + 1; i < hours2; i++)
		{
			total_price += price_per_hours[i % 24];
		}

		tp.price = total_price;
		tp.time = end - start;
		ans.push_back(tp);
	}

	return ans;
}

void PairDate(Person &p)
{
	vector<DateTag> v;
	v.insert(v.end(), p.start_time.begin(), p.start_time.end());
	v.insert(v.end(), p.end_time.begin(), p.end_time.end());
	sort(v.begin(), v.end());
	int size = v.size();
	p.start_time.clear();
	p.end_time.clear();

	for (int i = 1; i < size; i++)
	{
		if (v[i].tag == "off-line" && v[i - 1].tag == "on-line")
		{
			p.start_time.push_back(v[i - 1]);
			p.end_time.push_back(v[i]);
		}
	}
}

void GenerateBills(map<string, Person> &mp, int price_per_minute[], string mon)
{
	//sort(mp.begin(), mp.end());

	map<string, Person>::iterator it = mp.begin();
	for (; it != mp.end(); it++)
	{
		PairDate(it->second);
		int size = (it->second).start_time.size();
		if (0 == size)
		{
			continue;
		}
		vector<TimeAndPrice> price = ComputeTimePrice(it->second);
		cout << it->first << " " << mon << endl;
		double total_price = 0;
		for (int j = 0; j < size; j++)
		{
			cout << (it->second).start_time[j].date << " " << (it->second).end_time[j].date
				<< " " << price[j].time << " " << "$";
			cout << setiosflags(ios::fixed);
			cout << setprecision(2) << (price[j].price / 100) << endl;
			total_price += price[j].price;
		}
		cout << setprecision(6);
		cout << "Total amount: $";
		cout << setiosflags(ios::fixed);
		cout << setprecision(2) << (total_price / 100) << endl;
		cout << setprecision(6);
	}
}


int main()
{
	ifstream in("in.in");

	map<string, Person> mp;

	for (int i = 0; i < 24; i++)
	{
		in >> price_per_minute[i];
	}

	price_per_day = 0;
	for (int i = 0; i < 24; i++)
	{
		price_per_hours[i] = 60 * price_per_minute[i];
		price_per_day += price_per_hours[i];
	}

	int record_num;
	in >> record_num;
	string month;
	for (int i = 0; i < record_num; i++)
	{
		string name;
		in >> name;
		if (mp.find(name) == mp.end())
		{
			Person p;
			p.name = name;
			mp[name] = p;
		}

		string date;
		in >> date;
		string state;
		in >> state;
		DateTag dt;
		dt.date = date.substr(3);
		dt.tag = state;
		if (state == "on-line")
		{
			mp[name].start_time.push_back(dt);
		}
		else
		{
			mp[name].end_time.push_back(dt);
		}
		if (month.empty())
		{
			month = date.substr(0, 2);
		}
	}

	GenerateBills(mp, price_per_minute, month);

	system("pause");
	return 0;

}

