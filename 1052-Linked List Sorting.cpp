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
	int num, first_addr;
	scanf("%d %d", &num, &first_addr);

	map<int, pair<int, int> > node;
	map<int, pair<int, int> > val_mp;
	vector<int> v;
	for(int i = 0; i < num; i++)
	{
		int addr, val, next;
		scanf("%d %d %d", &addr, &val, &next);
		node[addr] = make_pair(val, next);
		val_mp[val] = make_pair(addr, next);
	}


	while(first_addr != -1)
	{
		if(node.find(first_addr) == node.end())
		{
			break;
		}
		v.push_back(node[first_addr].first);
		first_addr = node[first_addr].second;
	}

	int size = v.size();

	if(size == 0)
	{
		if(first_addr == -1)
		{
			printf("0 -1\n");
		}
		else
		{
			printf("0 %05d\n", first_addr);//找不到第一个地址的情况或者找不到链表中某个后接的地址
		}
		
	}
	else
	{
		sort(v.begin(), v.end());
		printf("%d %05d\n", size, val_mp[v[0]].first);
		for(int i = 0; i < size; i++)
		{
			if(i != 0)
			{
				//cout << val_mp[v[i]].first << endl;
				printf(" %05d\n", val_mp[v[i]].first);
			}
			//cout << val_mp[v[i]].first << v[i];
			printf("%05d %d", val_mp[v[i]].first, v[i]);
		}
		printf(" -1\n");
	}
	
	system("pause");
	return 0;
}