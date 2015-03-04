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

int main()
{
	int stu_num, course_num;
	//cin >> stu_num >> course_num;
	scanf("%d%d", &stu_num, &course_num);

	//map<int, vector<string> > course_stu_mp;
	vector<string> course_stu_mp[course_num + 1];
	for(int i = 0; i < stu_num; i++)
	{
		char stu_name[6];
		//cin >> stu_name;
		scanf("%s", stu_name);
		string name = stu_name;
		int n;
		//cin >> n;
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
		{
			int course_id;
			//cin >> course_id;
			scanf("%d", &course_id);
			//cout << stu_name << endl;
			course_stu_mp[course_id].push_back(name);
		}
	}

	for(int i = 1; i <= course_num; i++)
	{
		int size = course_stu_mp[i].size();
		//cout << it->first << " " << size << endl;
		printf("%d %d\n", i, size);
		sort((course_stu_mp[i]).begin(), (course_stu_mp[i]).end());
		for(int j = 0; j < size; j++)
		{
			//cout << (it->second)[i] << endl;
			printf("%s\n", course_stu_mp[i][j].c_str());
		}
	}
	

	system("pause");
	return 0;
}

//map的迭代器太耗时，导致运行超时！
// ifstream in("in.in");
// #define cin in

// int main()
// {
// 	int stu_num, course_num;
// 	//cin >> stu_num >> course_num;
// 	scanf("%d%d", &stu_num, &course_num);

// 	map<int, vector<string> > course_stu_mp;
// 	for(int i = 0; i < stu_num; i++)
// 	{
// 		char stu_name[5];
// 		//cin >> stu_name;
// 		scanf("%s", stu_name);
// 		int n;
// 		//cin >> n;
// 		scanf("%d", &n);
// 		for(int j = 0; j < n; j++)
// 		{
// 			int course_id;
// 			//cin >> course_id;
// 			scanf("%d", &course_id);
// 			//cout << stu_name << endl;
// 			course_stu_mp[course_id].push_back(stu_name);
// 		}
// 	}

// 	if(course_stu_mp.size() == 0)
// 	{
// 		for(int i = 1; i <= course_num; i++)
// 		{
// 			//cout << i << " " << 0 << endl;
// 			printf("%d 0\n", i);
// 		}
// 	}
// 	int count = 1;
// 	map<int, vector<string> >::iterator it = course_stu_mp.begin();
// 	for(; it != course_stu_mp.end(); it++)
// 	{
// 		if(it->first > count)
// 		{
// 			//cout << count << " " << 0 << endl;
// 			printf("%d 0\n", count);
// 		}
// 		int size = (it->second).size();
// 		//cout << it->first << " " << size << endl;
// 		printf("%d %d\n", it->first, size);
// 		sort((it->second).begin(), (it->second).end());
// 		for(int i = 0; i < size; i++)
// 		{
// 			//cout << (it->second)[i] << endl;
// 			printf("%s\n", (it->second)[i].c_str());
// 		}
// 		count++;
// 	}
	

// 	system("pause");
// 	return 0;
// }