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

string n[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

string ReadLess(int num)
{
	bool zero = false;
	bool high = false;
	int r = num;
	string ans = "";
	int t = r / 1000;
	if(t)
	{
		ans = n[t] + " Qian";
		high = true;
	}

	r = r % 1000;
	t = r / 100;
	if(t)
	{
		ans += num > 1000 ? " " + n[t] + " Bai" : n[t] + " Bai";
		high = true;
	}
	else
	{
		ans += r > 0 && high ? " ling" : "";
		zero = true;
	}

	r = r % 100;
	t = r / 10;
	if(t)
	{
		ans += num > 100 ? " " + n[t] + " Shi" : n[t] + " Shi";
	}
	else
	{
		ans += (!zero && r > 0 && high) ? " ling" : "";
	}

	t = r % 10;
	if(t)
	{
		ans += num > 10 ? " " + n[t] : n[t];
	}
	//cout << ans << endl;
	return ans;
}

void ReadInChinese(int num)
{
	string ans = "";
	int t = num % 10000;
	//cout << t << endl;
	ans = ReadLess(t);
	//cout << ans << endl;
	if(num < 10000)
	{
		cout << ans << endl;
		return;
	}

	ans = t < 1000 ? "ling " + ans : ans;

	//cout << ans << endl;
	num /= 10000;
	t = num % 10000;
	ans = ReadLess(t) + " Wan " + ans;
	if(num < 10000)
	{
		cout << ans << endl;
		return;
	}
	ans = t < 1000 ? "ling " + ans : ans;

	num /= 10000;
	ans = ReadLess(num) + " Yi " + ans;

	cout << ans << endl;
}

int main()
{
	ifstream in("in.in");
	int num;
	in >> num;

	if(0 == num)
	{
		cout << "ling" << endl;
		return 0;
	}

	if((num >> 31))
	{
		cout << "Fu ";
	}

	ReadInChinese(abs(num));

	system("pause");
	return 0;
}