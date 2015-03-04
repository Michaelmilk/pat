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


int main()
{
	ifstream in("in.in");

	string speech;
	//in >> speech;
	getline(in, speech);

	map<string, int> string_times;
	int len = speech.length();
	int s = 0;
	//int e = 0;
	for(int i = 0; i < len; i++)
	{
		if(speech[i] >= 'A' && speech[i] <= 'Z')
		{
			speech[i] = tolower(speech[i]);
		}

		if(i == len - 1 && (s != i || s == 0))
		{
			string key = speech.substr(s, len - s);
			string_times[key]++;
		}

		if(!isalnum(speech[i]))
		{
			if(s != i)
			{
				string key = speech.substr(s, i - s);
				//out << key << endl;
				s = i + 1;
				string_times[key]++;
			}
			else
			{
				s = i + 1;
			}
		}
	}

	string ans;
	int times = INT_MIN;
	map<string, int>::iterator it = string_times.begin();
	for(; it != string_times.end(); it++)
	{
		if(it->second > times)
		{
			ans = it->first;
			times = it->second;
		}
	}

	cout << ans << " " << times << endl;
	system("pause");
	return 0;
}