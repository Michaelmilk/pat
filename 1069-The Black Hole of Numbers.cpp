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
#include <functional>

using namespace std;

void PrintProcess(string num, int previous)
{
	while(true)
	{
		stringstream ss;
		ss << setw(4) << setfill('0') << num;
		string nonincre_num;
		ss >> nonincre_num;
		sort(nonincre_num.begin(), nonincre_num.end(), greater<int>());
		ss.clear();
		ss << setw(4) << setfill('0') << num;
		string nondecre_num;
		ss >> nondecre_num;
		sort(nondecre_num.begin(), nondecre_num.end());
		ss.clear();
		ss << nonincre_num;
		int big;
		ss >> big;
		ss.clear();
		ss << nondecre_num;
		int small;
		ss >> small;
		int diff = big - small;
		if(diff == previous)
		{
			break;
		}
		else
		{
			cout << nonincre_num << " - " << nondecre_num << " = " << setw(4) << setfill('0') << diff << endl;
			previous = diff;
			ss.clear();
			ss << setw(4) << setfill('0') << diff;
			ss >> num;
		}
	}
}

int main()
{
	string num;
	cin >> num;

	int previos_num = -1;
	PrintProcess(num, previos_num);

	system("pause");
	return 0;
}