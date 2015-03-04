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

	int sets_num;
	in >> sets_num;

	vector<set<int> > s(sets_num);
	for(int i = 0; i < sets_num; i++)
	{
		int val_num;
		in >> val_num;
		for(int j = 0; j < val_num; j++)
		{
			int val;
			in >> val;
			s[i].insert(val);
		}
	}

	map<int, int> set_size;
	for(int i = 0; i < sets_num; i++)
	{
		set_size[i] = s[i].size();
	}

	int query_num;
	in >> query_num;
	for(int i = 0; i < query_num; i++)
	{
		int idx1, idx2;
		in >> idx1 >> idx2;
		if(idx1 == idx2)
		{
			cout << 100 << "%" << endl;
			continue;
		}
		int size1 = set_size[idx1 - 1];
		int size2 = set_size[idx2 - 1];
		//cout << size1 << " " << size2 << endl;
		int total = size1 + size2;
		/*
		//set<int> tmp_set(s[idx1 - 1].begin(), s[idx1 - 1].end());
		//tmp_set.insert(s[idx2 - 1].begin(), s[idx2 - 1].end());
		set<int> tmp_set;
		set_intersection(s[idx1 - 1].begin(), s[idx1 - 1].end(), s[idx2 - 1].begin(), s[idx2 - 1].end(),
		 inserter(tmp_set, tmp_set.begin()));
		int same_num = tmp_set.size();
		// cout << tmp_set.size() << endl;
		// int same_num = total - tmp_size;
		//cout << same_num << endl;

		cout << fixed << setprecision(1) << ((double)same_num / (total - same_num)) * 100 << "%" << endl;
		*/

		int same_num = 0;
		set<int>::iterator it1 = s[idx1 - 1].begin();
		set<int>::iterator it2 = s[idx2 - 1].begin();
		for(; it1 != s[idx1 -1].end() && it2 != s[idx2 - 1].end();)
		{
			if(*it1 == *it2)
			{
				same_num++;
				it1++;
				it2++;
			}
			else if(*it1 > *it2)
			{
				it2++;
			}
			else
			{
				it1++;
			}
		}
		cout << fixed << setprecision(1) << ((double)same_num / (total - same_num)) * 100 << "%" << endl;
	}

	system("pause");
	return 0;
}