#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void Judge(bool &is_permutation, string &doubled, map<char, int> &char_count)
{
	int len = doubled.length();
	int c = 0;
	for(int i = len - 1; i >= 0; i--)
	{
		int mul = (doubled[i] - 48) * 2;
		int t = mul;
		mul %= 10;
		doubled[i] =  (c + mul) + 48;
		c = t / 10;
	}

	if(c != 0)
	{
		doubled.insert(0, 1, (char)(c + 48));
		return;
	}

	for(int i = 0; i < len; i++)
	{
		if(char_count[doubled[i]] == 0)
		{
			return;
		}
		char_count[doubled[i]]--;
	}

	is_permutation = true;
	return;
}

int main()
{
	ifstream in("in.in");
	string original;
	in >> original;

	map<char, int> char_count;
	int len = original.length();
	for(int i = 0; i < len; i++)
	{
		char_count[original[i]]++;
	}

	bool is_permutation = false;
	string doubled = original;
	Judge(is_permutation, doubled, char_count);
	string ans = is_permutation ? "Yes" : "No";
	cout << ans << endl;
	cout << doubled << endl;
	system("pause");
	return 0;
}