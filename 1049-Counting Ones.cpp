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
#include <sstream>

using namespace std;

int CountOnes(int num, int idx)
{
	int base = (int)pow(10, idx);
	int next_base = base * 10;
	int right = num % base;//when the cur digit is 1,there are ones at the idx digit 
	int round_down = num - num % next_base;//the digit bdfore the idx digit
	int round_up = round_down + next_base;//when the idx digit > 1

	int cur_digit = (num / base) % 10;//the cur digit
	if(cur_digit > 1)
	{
		return round_up / 10;
	}
	else if(cur_digit == 1)
	{
		return round_down / 10 + right + 1;//why plus 1  because the range is 0 - right
	}
	else
	{
		return round_down / 10;
	}
}


int main()
{
	int num;
	cin >> num;
	stringstream s;
	s << num;
	string str;
	s >> str;
	int len = str.length();
	int count = 0;
	for(int i = 0; i < len; i++)
	{
		count += CountOnes(num, i);
	}

	cout << count << endl;
	system("pause");
	return 0;
}