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
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <cstdio>

using namespace std;

int main()
{
	ifstream in("in.in");

	vector<char> ans;
	char res[] = { 'W', 'T', 'L' };
	double odd[3] = { 0 };
	double profile = 1.0;
	for (int i = 0; i < 3; i++)
	{
		char tmp;
		int idx = 0;
		int maxval = 0;
		for (int j = 0; j < 3; j++)
		{
			in >> odd[j];
			if (odd[j] > maxval)
			{
				idx = j;
				tmp = res[j];
				maxval = odd[j];
			}
		}
		profile *= odd[idx];
		ans.push_back(tmp);
	}

	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << " ";
	}
	
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << (profile * 0.65 - 1.0) * 2 << endl;
	cout << setprecision(6);
	//printf("%.2lf", (profile * 0.65 - 1.0) * 2);

	return 0;
}
