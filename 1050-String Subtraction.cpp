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
#include <map>

using namespace std;


int main()
{
	ifstream in("in.in");

	string original;
	string pattern;

	getline(in, original);
	getline(in, pattern);

	map<char, int> mp;
	int len = pattern.length();
	for(int i = 0; i < len; i++)
	{
		mp[pattern[i]]++;
	}

	len = original.length();
	for(int i = 0; i < len; i++)
	{
		if(mp.find(original[i]) == mp.end())
		{
			cout << original[i];
		}
	}
	system("pause");
	return 0;
}