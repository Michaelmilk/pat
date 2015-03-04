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
#include <ctype.h>
#include <cstdlib>
#include <set>

using namespace std;


int main()
{
	ifstream in("in.in");

	string ans = "";
	string original_str;
	in >> original_str;
	string type;
	in >> type;

	map<char, int> type_mp;
	set<char> s;
	int len = type.length();
	for(int i = 0; i < len; i++)
	{
		char ch = toupper(type[i]);
		type_mp[ch]++;
	}
	len = original_str.size();
	for(int i = 0; i < len; i++)
	{
		char ch = toupper(original_str[i]);
		if(type_mp[ch] == 0 && s.find(ch) == s.end())
		{
			ans += ch;
			s.insert(ch);
		}
	}

	cout << ans << endl;
	system("pause");
	return 0;
}