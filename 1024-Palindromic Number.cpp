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

bool IsPalindrome(string s)
{
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		if(s[i] != s[len - 1 -i])
		{
			return false;
		}
	}

	return true;
}

void AddInit(string &initial, string &s)
{
	int c = 0;
	int len = initial.length();
	for(int i = len - 1; i >= 0; i--)
	{
		int val = (initial[i] - '0') + (s[i] - '0') + c;
		c = val / 10;
		val %= 10;
		initial[i] = val +'0';
	}
	if(c != 0)
	{
		initial = (char)(c + '0') + initial;
	}
}

void CountSteps(int steps, string initial)
{
	int count = 0;
	stringstream ss;
	ss << initial;
	long long tmp;
	ss >> tmp;
	if(tmp >= 10)
	{
		while(!IsPalindrome(initial) && count < steps)
		{
			string tmp_str(initial);
			reverse(tmp_str.begin(), tmp_str.end());
			AddInit(initial, tmp_str);
			count++;
		}
	}
	cout << initial << endl << count << endl;
}

int main()
{
	//initial最大数值10^10,再迭代相加100次，因为第一次迭代10^10+10^10=（10^10）*（2^1）
	//第二次迭代（10^10+10^10）+（10^10+10^10）也就是（10^10）*（2^2）…………
	//迭代100次就是（10^10）*（2^100）约等于（10^10）*（10^30），超出了longlong的范围
	//大概达到10^40级；long long型也不足以表示，需要使用字符型处理
	string initial;
	int steps;
	cin >> initial >> steps;

	CountSteps(steps, initial);

	system("pause");
	return 0;
}