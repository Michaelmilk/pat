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

bool cmp(const string &s1, const string &s2)
{
	string a = s1 + s2;
	string b = s2 + s1;
	return a < b;
}

int main()
{
	int num;
	cin >> num;

	vector<string> segment(num);
	for(int i = 0; i < num; i++)
	{
		cin >> segment[i];
	}

	sort(segment.begin(), segment.end(), cmp);

	string ans = "";
	for(int i = 0; i < num; i++)
	{
		ans += segment[i];
	}

	int idx = 0;
	while(ans[idx++] == '0');

	ans = ans.substr(--idx);

	if(ans.length() == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	cout << ans << endl;

	system("pause");
	return 0;
}