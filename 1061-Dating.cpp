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
#include <cctype>


using namespace std;

map<char, string> day_map;
map<char, string> hour_map;

void GetDay(string &one, string &two)
{
	int olen = one.length();
	int tlen = two.length();
	bool day_flag = false;
	bool hour_flag = false;
	for(int i = 0, j = 0; i < olen, j < tlen; i++, j++)
	{
		//if(day_flag && one[i] == two[j] && (('0' <= one[i] && one[i] <= '9') || ('A' <= one[i] && one[i] <= 'N')))
		if(day_flag && one[i] == two[j] && (hour_map.find(one[i]) != hour_map.end()))
		{
			cout << hour_map[one[i]] << ":";
                  break;
		}

		if(!day_flag && one[i] == two[j] && day_map.find(one[i]) != day_map.end())
		{
			cout << day_map[one[i]] << " ";
			day_flag = true;
		}
	}
}
void GetTime(string &one, string &two)
{
	int olen = one.length();
	int tlen = two.length();
	int i = 0;
	int j = 0;
	while(i < olen && j < tlen)
	{
		if(one[i] == two[j] && isalpha(one[i]))
		{
			if(i < 10)
			{
				cout << 0 << i << endl;
			}
			else
			{
				cout << i << endl;
			}
			break;
		}
		i++;
		j++;
	}
}

void init()
{
	day_map['A'] = "MON";
	day_map['B'] = "TUE";
	day_map['C'] = "WED";
	day_map['D'] = "THU";
	day_map['E'] = "FRI";
	day_map['F'] = "SAT";
	day_map['G'] = "SUN";
	hour_map['0'] = "00";
	hour_map['1'] = "01";
	hour_map['2'] = "02";
	hour_map['3'] = "03";
	hour_map['4'] = "04";
	hour_map['5'] = "05";
	hour_map['6'] = "06";
	hour_map['7'] = "07";
	hour_map['8'] = "08";
	hour_map['9'] = "09";
	hour_map['A'] = "10";
	hour_map['B'] = "11";
	hour_map['C'] = "12";
	hour_map['D'] = "13";
	hour_map['E'] = "14";
	hour_map['F'] = "15";
	hour_map['G'] = "16";
	hour_map['H'] = "17";
	hour_map['I'] = "18";
	hour_map['J'] = "19";
	hour_map['K'] = "20";
	hour_map['L'] = "21";
	hour_map['M'] = "22";
	hour_map['N'] = "23";

}
int main()
{
//	ifstream in("in.in");

	init();
	string str[4];
	for(int i = 0; i < 4; i++)
	{
		cin >> str[i];
	}

	GetDay(str[0], str[1]);
	GetTime(str[2], str[3]);

	system("pause");
	return 0;
}