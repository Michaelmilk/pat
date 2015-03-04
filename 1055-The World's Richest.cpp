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

struct Person
{
	char name[9];
	int age;
	int worth;
	// bool operator <(const Person &p) const
	// {
	// 	return age < p.age;
	// }
};

bool cmp(const Person &p1, const Person &p2)
{
	if(p1.worth != p2.worth)
	{
		return p1.worth > p2.worth;
	}
	else if(p1.age != p2.age)
	{
		return p1.age < p2.age;
	}
	else
	{
		int i = -1;
		int j = -1;
		while(p1.name[++i] != '\0' && p2.name[++j] != '\0' && p1.name[i] == p2.name[j]);
		return p1.name[i] < p2.name[j];
	}
}

int main()
{
	int people_num, query_num;
	scanf("%d %d", &people_num, &query_num);

	vector<Person> person(people_num);
	for(int i = 0; i < people_num; i++)
	{
		//char name[9];
		//int age, worth;
		scanf("%s", person[i].name);
		scanf("%d %d", &person[i].age, &person[i].worth);
	}
	
	sort(person.begin(), person.end(), cmp);
	int account[201] = {0};
	int idx = 0;
	vector<int> effect_idx;
	for(int i = 0; i < people_num; i++)
	{
		if(++account[person[i].age] < 101)//某个年龄的人不超过100.不进行筛选，第2个case会超时
		{
			effect_idx.push_back(i);
		}
	}

	int case_id = 1;
	for(int i = 0; i < query_num; i++)
	{
		int outputs;
		scanf("%d", &outputs);
		int a_min, a_max;
		scanf("%d %d", &a_min, &a_max);
		vector<Person> ans;
		int count = 0;
		int s = effect_idx.size();
		for(int j = 0; j < s; j++)
		{
			if(person[effect_idx[j]].age >= a_min && person[effect_idx[j]].age <= a_max)
			{
				ans.push_back(person[effect_idx[j]]);
				count++;
			}

			//!!!!count >= outputs因为前outputs名不一定是财产最多的，而是年龄最小的，所以必须将年龄段的所有人全部找出来排序
			//outputs最大值是100， 所以超过100可以break
			if(count >= outputs)
			{
				break;
			}
		}

		int size = ans.size();
		printf("Case #%d:\n", case_id);
		case_id++;
		if(0 == size)
		{
			printf("None\n");
		}
		else
		{
			//sort(ans.begin(), ans.end(), cmp);
			if(size > outputs)
			{
				size = outputs;
			}

			for(int i = 0; i < size; i++)
			{
				printf("%s %d %d\n", ans[i].name, ans[i].age, ans[i].worth);
			}
		}
	}

	system("pause");
	return 0;
}