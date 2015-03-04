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

ifstream in("in.in");
#define cin in

//字符串操作太耗时，通过哈希函数将字符串转换为int类型的值
int HashName(char *name)
{
	return (name[0] - 'A') * 26 * 26 * 10 
       + (name[1] - 'A') * 26 * 10
       + (name[2] - 'A') * 10 
       + (name[3] - '0'); 

}

int main()
{
	int query_num, course_num;
	//cin >> query_num >> course_num;
	scanf("%d %d", &query_num, &course_num);

	map<int, vector<int> > name_to_course;
	for(int i = 1; i <= course_num; i++)
	{
		int id, num;
		//cin >> id >> num;
		scanf("%d %d", &id, &num);

		for(int j = 0; j < num; j++)
		{
			//string name;
			//cin >> name;
			char ch[5];
			scanf("%s", ch);
			//string name = ch;
			int idx = HashName(ch);
			name_to_course[idx].push_back(id);
		}
	}

	for(int i = 0; i < query_num; i++)
	{
		// string name;
		// cin >> name;
		// cout << name << " ";
		char ch[5];
		scanf("%s", ch);
		printf("%s ", ch);
		int idx = HashName(ch);
		int size = name_to_course[idx].size();
		//cout << size;
		printf("%d", size);
		if(size > 1)
		{
			sort(name_to_course[idx].begin(), name_to_course[idx].end());
		}
		for(int i = 0; i < size; i++)
		{
			//cout << " " << name_to_course[name][i];
			printf(" %d", name_to_course[idx][i]);
		}
		//cout << endl;
		printf("\n");
	}
	system("pause");
	return 0;
}