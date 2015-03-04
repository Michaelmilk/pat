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

struct Node
{
	string address;
	int val;
	string next;
};

int main()
{
	string first_addr;
	int node_num, sub_num;
	cin >> first_addr >> node_num >> sub_num;

	map<string, Node> list;
	for(int i = 0; i < node_num; i++)
	{
		string addr, next;
		int v;
		cin >> addr >> v >> next;
		Node node;
		node.address = addr;
		node.val = v;
		node.next = next;
		list[addr] = node;
	}

	vector<Node> l;
	string addr = first_addr;
	int size = 1;
	while(list[addr].next != "-1")
	{
		size++;
		l.push_back(list[addr]);
		addr = list[addr].next;
	}
	l.push_back(list[addr]);

	//int size = l.size();//！！！！！！！！因为输入的节点不一定都在满足条件的串中
	int round = size / sub_num;
	if(sub_num != 1)
	{
		for(int i = 0; i < round * sub_num; i += sub_num)
		{
			reverse(l.begin() + i, l.begin() + i + sub_num);
		}
	}
	
	for(int i = 0; i < size; i++)
	{
		if(i > 0)
		{
			cout << l[i].address << endl;
		}
		cout << l[i].address << " " << l[i].val << " ";
	}
	cout << -1 << endl;

	//system("pause");//不去掉会TLE
	return 0;
}