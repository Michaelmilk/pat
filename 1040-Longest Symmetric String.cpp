#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>
#include <fstream>
#include <iomanip>

using namespace std;

int TwoSideExtend(string s, int left, int right)
{
	int max_len = 0;
	int len = s.length();
	if(left == right)
	{
		max_len = 1;
		left--;
		right++;
	}

	while(left >= 0 && right < len && s[left] == s[right])
	{
		max_len += 2;
		left--;
		right++;
	}

	return max_len;
}

void LongestSysmetricString(string s)
{
	int len = s.length();
	int max_len = 0;

	for(int i = 0; i < len; i++)
	{
		int tlen = TwoSideExtend(s, i, i);
		max_len = max_len > tlen ? max_len : tlen;
	}

	for(int i = 1; i < len; i++)
	{
		int tlen = TwoSideExtend(s, i - 1, i);
		max_len = max_len > tlen ? max_len : tlen;
	}

	cout << max_len << endl;
}

int main()
{
	ifstream in("in.in");

	string str;
	getline(in, str);

	LongestSysmetricString(str);

	system("pause");
	return 0;
}