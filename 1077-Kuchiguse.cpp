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

string GetSuffix(string &kuch, string &s)
{
	int klen = kuch.length();
	int slen = s.length();
	string tmp = "";
	for(int i = klen - 1, j = slen - 1; i >= 0 && j >= 0; i--, j--)
	{
		if(kuch[i] == s[j])
		{
			tmp =kuch[i] + tmp;
		}
		else
		{
			break;
		}
	}
	return tmp;
}

int main()
{
	int n;
	cin >> n;

	string kuch = "";
	string s;
	getline(cin, s);
	for(int i = 0; i < n; i++)
	{
		getline(cin, s, '\n');
		kuch = (i == 0 ? s : GetSuffix(kuch, s));
	}

	if(kuch.empty())
	{
		cout << "nai" << endl;
	}
	else
	{
		cout << kuch << endl;
	}

	system("pause");
	return 0;
}