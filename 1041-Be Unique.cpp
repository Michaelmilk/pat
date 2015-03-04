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
#include <fstream>


using namespace std;

struct Id
{
	int num;
	int id;
	bool operator <(const Id &p) const
	{
		return id < p.id;
	}
};

int main()
{
	ifstream in("in.in");
	
	int n;
	in >> n;

	map<int, Id> mp;
	for(int i = 0; i < n; i++)
	{
		int num;
		in >> num;
		if(mp[num].num == 0)
		{
			mp[num].id = i;
		}
		mp[num].num++;
	}

	int order = INT_MAX;
	int one;
	
	
	map<int, Id>::iterator it = mp.begin();
	for(; it != mp.end(); it++)
	{
		if((it->second).num == 1 && (it->second).id < order)
		{
			order = (it->second).id;
			one = it->first;
		}

	}
	if(order != INT_MAX)
	{
		cout << one << endl;
	}
	else
	{
		cout << "None" << endl;
	}
		
	system("pause");
	return 0;
}