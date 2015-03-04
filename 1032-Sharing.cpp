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

const int k_num = 100005;
int nxt[k_num];
bool vst[k_num];

int main()
{
	int first_addr1, first_addr2, num;
	memset(vst, false, k_num);
	scanf("%d %d %d", &first_addr1, &first_addr2, &num);

	for(int i = 0; i < num; i++)
	{
		int addr, n;
		char val;
		scanf("%d %c %d", &addr, &val, &n);
		nxt[addr] = n;
	}

	int addr = first_addr1;
	while(addr != -1)
	{
		vst[addr] = 1;
		addr = nxt[addr];
	}

	addr = first_addr2;
	while(addr != -1)
	{
		if(vst[addr] == 1)
		{
			printf("%05d\n", addr);
			system("pause");
			return 0;
		}
		addr = nxt[addr];
	}
	printf("-1\n");
	system("pause");
	return 0;
}

//TLE
// ifstream in("in.in");
// #define cin in

// int main()
// {
// 	map<string, pair<char, string> > list;
// 	string l1_first_addr, l2_first_addr;
// 	int node_num;
// 	char l1_f_addr[6], l2_f_addr[6];
// 	//cin >> l1_first_addr >> l2_first_addr >> node_num;
// 	scanf("%s %s %d", l1_f_addr, l2_f_addr, &node_num);
// 	l1_first_addr = l1_f_addr;
// 	l2_first_addr = l2_f_addr;

// 	for(int i = 0; i < node_num; i++)
// 	{
// 		string addr, next;
// 		char a[6], n[6];
// 		char val;
// 		scanf("%s %c %s", a, &val, n);
// 		addr = a;
// 		next = n;
// 		//cin >> addr >> val >> next;
// 		//cout << "---" << addr << val << next << endl;
// 		list[addr] = make_pair(val, next);
// 	}
// 	//cout << "---" << endl;

// 	vector<string> l1;
// 	vector<string> l2;

// 	while(list[l1_first_addr].second != "-1")
// 	{
// 		//cout << l1_first_addr << endl;
// 		l1.push_back(l1_first_addr);
// 		l1_first_addr = list[l1_first_addr].second;
// 	}

// 	while(list[l2_first_addr].second != "-1")
// 	{
// 		l2.push_back(l2_first_addr);
// 		l2_first_addr = list[l2_first_addr].second;
// 	}

// 	//bool flag = false;
// 	int idx = -1;
// 	for(int i = l1.size() - 1, j = l2.size() - 1; i >= 0 && j >= 0; i--, j--)
// 	{
// 		if(l1[i] != l2[j])
// 		{
// 			break;
// 		}
// 		idx = i;
// 	}

// 	if(idx == -1)
// 	{
// 		cout << -1 << endl;
// 	}
// 	else
// 	{
// 		cout << l1[idx] << endl;
// 	}

// 	system("pause");
// 	return 0;
// }