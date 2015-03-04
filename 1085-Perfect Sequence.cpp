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

int BinSearch(int cmp, int size, vector<double> &v)
{
	int l = 0, r = size - 1;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(v[mid] > cmp)
		{
			r = mid - 1;
		}
		else if(v[mid] < cmp)
		{
			l = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return l;
}

int main()
{
	int num, parameter;
	cin >> num >> parameter;

	int min_val = INT_MAX;
	vector<double> v(num);
	for(int i = 0; i < num; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	if(parameter == 0 && min_val > 0)
	{
		cout << 0 << endl;
		return 0;
	}

	int count = 0;
	int max_val = 0;
	//long long t = min_val * parameter;
	//cout << min_val << " " << t << endl;
	for(int i = 0; i < num; i++)
	{
		long long t = v[i] * parameter;
		int idx = BinSearch(t, num, v);
		if(v[num - 1] <= t)
		{
			count = num - i;
		}
		else
		{
			count = idx - i;
		}
		
		max_val = max_val > count ? max_val : count;
	}

	cout << max_val << endl;
	system("pause");
	return 0;
}

//正整数可以，
// int main()
// {
// 	int num, parameter;
// 	cin >> num >> parameter;

// 	int min_val = INT_MAX;
// 	vector<double> v(num);
// 	for(int i = 0; i < num; i++)
// 	{
// 		cin >> v[i];
// 		min_val = min_val > v[i] ? v[i] : min_val;
// 	}

// 	if(parameter == 0 && min_val > 0)
// 	{
// 		cout << 0 << endl;
// 		return 0;
// 	}

// 	int count = 0;
// 	double t = min_val * parameter;
// 	//long long t = min_val * parameter;
// 	//cout << min_val << " " << t << endl;
// 	for(int i = 0; i < num; i++)
// 	{
// 		if(v[i] <= t)
// 		{
// 			count++;
// 		}
// 	}

// 	cout << count << endl;
// 	system("pause");
// 	return 0;
// }