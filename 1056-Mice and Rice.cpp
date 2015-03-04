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

using namespace std;

struct Programer
{
	int mouse_weight;
	int order;
	int rank;
};


int main()
{
	ifstream in("in.in");

	int programers_num, group_num;
	in >> programers_num >> group_num;

	vector<Programer> programer(programers_num);
	queue<int> que;
	for(int i = 0; i < programers_num; i++)
	{
		in >> programer[i].mouse_weight;
	}
	for(int i = 0; i < programers_num; i++)
	{
		in >> programer[i].order;
		que.push(programer[i].order);
	}

	while(que.size() != 1)
	{
		int groups = que.size() % group_num ? (que.size() / group_num) + 1 : (que.size() / group_num);
		queue<int> tmp;
		for(int i = 0; i < groups; i++)
		{
			int idx = -1;
			int max_val = -1;
			for(int j = i * groups; j < i * groups + group_num && que.size() != 0; j++)
			{
				int t= que.front();
				programer[t].rank = groups + 1;//need deduce
				que.pop();
				if(programer[t].mouse_weight > max_val)
				{
					max_val = programer[t].mouse_weight;
					idx = t;
				}
			}
			tmp.push(idx);
		}
		que = tmp;
	}
	
	programer[que.front()].rank = 1;

	for(int i = 0; i < programers_num; i++)
	{
		cout << programer[i].rank << (i != programers_num - 1 ? " " : "\n");
	}
	system("pause");
	return 0;
}