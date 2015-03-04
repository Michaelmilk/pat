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


int main()
{
	ifstream in("in.in");

	string num;
	in >> num;

	int epos = num.find('E');
	string portion_num = num.substr(0, epos);
	string exp_num = num.substr(epos + 1);
	bool exp_sign = (exp_num[0] == '+' ? true : false);//represent exponent sign
	stringstream ss;
	ss << exp_num.substr(1);
	int exp;
	ss >> exp;
	ss.clear();
	int portion;
	ss << portion_num;
	ss >> portion;
	if(exp != 0 && portion != 0)
	{
		int len = portion_num.length();
		int point_pos = portion_num.find('.');
		int after_len = 0;
		if(point_pos != string::npos)
		{
			after_len = len - point_pos - 1;
			portion_num.erase(point_pos, 1);
		}
		
		if(exp_sign)
		{
			if(exp < after_len)
			{
				portion_num.insert(point_pos + exp, 1, '.');
			}
			else
			{
				portion_num.insert(portion_num.end(), exp - after_len, '0');
			}
		}
		else
		{
			portion_num.insert(1, "0.");
			exp--;
			if(exp > 0)
			{
				portion_num.insert(3, exp, '0');
			}
		}
	}
	portion_num = portion_num[0] == '+' ? portion_num.substr(1) : portion_num;
	cout << portion_num << endl;

	system("pause");
	return 0;
}