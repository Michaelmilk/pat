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

ifstream in("in.in");
#define cin in

int main()
{
	int num;
	string f1, f2;
	cin >> num >> f1 >> f2;

	int nz = 0;
	while(f1[nz] == '0' && f1[nz + 1] != '.')
	{
		nz++;
	}
	f1 = f1.substr(nz);
	nz = 0;
	while(f2[nz] == '0' && f2[nz + 1] != '.')
	{
		nz++;
	}
	f2 = f2.substr(nz);
	
	int len1 = f1.length();
	int len2 = f2.length();
	int f1_int = 0;
	int f2_int = 0;
	int exp1 = len1, exp2 = len2;

	int idx = 0;
	while(idx < len1 && (f1[idx] == '0' || f1[idx] == '.'))
	{
		idx++;
	}
	f1_int = idx;
	if(f1_int == len1)//为零的情况
	{
		f1 = "0";
		exp1 = 0;
		len1 = 1;
	}
	

	idx = 0;
	while(idx < len2 && (f2[idx] == '0' || f2[idx] == '.'))
	{
		idx++;
	}
	f2_int = idx;
	if(f2_int == len2)//为零的情况
	{
		f2 = "0";
		exp2 = 0;
		len2 = 1;
	}

	int pos = f1.find(".");
	if(pos != string::npos)
	{
		exp1 = pos - f1_int;
		if(exp1 > 0)
		{
			f1.erase(pos, 1);
			len1--;
		}
		else
		{
			f1 = f1.substr(f1_int);
			len1 -= f1_int;
			exp1++;
		}
	}

	pos = f2.find(".");
	if(pos != string::npos)
	{
		exp2 = pos - f2_int;
		if(exp2 > 0)
		{
			f2.erase(pos, 1);
			len2--;
		}
		else
		{
			f2 = f2.substr(f2_int);
			len2 -= f2_int;
			exp2++;
		}
	}

	if(len1 < num)
	{
		f1.insert(len1, num - len1, '0');
	}

	if(len2 < num)
	{
		f2.insert(len2, num - len2, '0');
	}

	

	cout << f1 << endl;
	cout << f2 << endl;
	bool is_same = true;

	for(int i = 0; i < num; i++)
	{
		if(f1[i] != f2[i])
		{
			is_same = false;
			break;
		}
	}

	if(is_same)
	{
		is_same = exp1 == exp2 ? true : false;
	}

	cout << (is_same ? "YES" : "NO") << " ";

	string ans1 = f1.substr(0, num);
	
	if(is_same)
	{
		cout << "0." << ans1 << "*10^" << exp1 << endl;
	}
	else
	{	
		string ans2 = f2.substr(0, num);
		cout << "0." << ans1 << "*10^" << exp1 << " ";
		cout << "0." << ans2 << "*10^" << exp2 << endl;
	}

	system("pause");
	return 0;
}