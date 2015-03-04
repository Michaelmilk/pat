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

	int n, m;
	in >> n >> m;

	map<int, int> color_times;
	int dominant_color;
	int max_times = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int color_val;
			in >> color_val;
			color_times[color_val]++;
			// if(color_times[color_val] > max_times)
			// {
			// 	max_times = color_times[color_val];
			// 	dominant_color = color_val;
			// }
		}
	}

	map<int, int>::iterator it = color_times.begin();
	for(; it != color_times.end(); it++)
	{
		if(it->second > max_times)
		{
			max_times = it->second;
			dominant_color = it->first;
		}
	}
	cout << dominant_color << endl;

	system("pause");
	return 0;
}