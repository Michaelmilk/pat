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

using namespace std;

//不超时的关键在于第一个参数，如果一个大数列前面基本有序的情况下，
//每次如果都从开始进行查找会很耗时
int IsComplete(int s, int size, int *mp)
{
	for(int i = s; i < size; i++)
	{
		if(mp[i] != i)
		{
			return i;
		}
	}
	return -1;
}


void CountSwapTimes(int size, int *mp)
{
	int count = 0;
	int pos = IsComplete(0, size, mp);
	while(-1 != pos)
	{
		if(mp[0] == 0)
		{
			//pos = IsComplete(size, mp);
			mp[0] = mp[pos];
			mp[pos] = 0;
			count++;
		}
		while(mp[0] != 0)//减少调用IsComplete()的次数
		{
			int t = mp[0];
			mp[0] = mp[t];
			mp[t] = t;
			count++;
		}
		pos = IsComplete(pos, size, mp);
	}
	cout << count << endl;
}

int main()
{
	ifstream in("in.in");

	int num;
	in >> num;

	int *mp = new int[num];
	for(int i = 0; i < num; i++)
	{
		int val;
		in >> val;
		mp[val] = i;
	}

	CountSwapTimes(num, mp);

	system("pause");
	return 0;
}

//TLE
// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <climits>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <fstream>
// #include <cstring>

// using namespace std;

// bool IsComplete(map<int, int> &mp)
// {
// 	map<int, int>::iterator it = mp.begin();
// 	for(; it != mp.end(); it++)
// 	{
// 		if(it->first != it->second)
// 		{
// 			return false;
// 		}
// 	}
// 	return true;
// }

// int FindNextPos(map<int, int> &mp)
// {
// 	map<int, int>::iterator it = mp.begin();
// 	for(; it != mp.end(); it++)
// 	{
// 		if(it->first != it->second)
// 		{
// 			return it->first;
// 		}
// 	}
// }

// void output(map<int, int> &mp)
// {
// 	map<int, int>::iterator it = mp.begin();
// 	for(; it != mp.end(); it++)
// 	{
// 		cout << it->first << "--" << it->second << " ";
// 	}
// }

// void CountSwapTimes(map<int, int> &mp)
// {
// 	int count = 0;
// 	while(!IsComplete(mp))
// 	{
// 		int pos;
// 		if(mp[0] == 0)
// 		{
// 			pos = FindNextPos(mp);
// 			mp[0] = mp[pos];
// 			mp[pos] = 0;
// 		}
// 		else
// 		{
// 			pos = mp[0];
// 			mp[0] = mp[pos];
// 			mp[pos] = pos;
// 		}
		
// 		// if(count <= 9)
// 		// {
// 		// 	output(mp);
// 		// 	cout << endl;
// 		// }
// 		count++;
// 	}
// 	cout << count << endl;
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int num;
// 	//in >> num;

// 	map<int, int> mp;
// 	for(int i = 0; i < num; i++)
// 	{
// 		int val;
// 		//in >> val;
// 		mp[val] = i;
// 	}

// 	CountSwapTimes(mp);

// 	system("pause");
// 	return 0;
// }