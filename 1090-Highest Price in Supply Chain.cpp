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

struct Member
{
	int id;
	double price;
	Member(int i, double p) : id(i), price(p){}
};

int main()
{
	ifstream in("in.in");

	int num;
	double price, rate;
	in >> num >> price >> rate;

	map<int, vector<int> > member;
	int root;
	for(int i = 0; i < num; i++)
	{
		int id;
		in >> id;
		if(id == -1)
		{
			root = i;
			continue;
		}
		member[id].push_back(i);
	}

	queue<Member> que;
	Member root_supplier(root, price);
	que.push(root_supplier);
	int count = 0;
	double max_price = price;
	while(!que.empty())
	{
		Member mem = que.front();
		que.pop();

		if(mem.price > max_price)
		{
			max_price = mem.price;
			count = 1;
		}
		else if(mem.price == max_price)
		{
			count++;
		}

		double cur_price = mem.price * ((100 + rate) / 100);
		int size = member[mem.id].size();
		for(int i = 0; i < size; i++)
		{
			Member tmp(member[mem.id][i], cur_price);
			que.push(tmp);
		}
	}
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << max_price;
	cout << setprecision(6);
	cout << " " << count << endl;

	system("pause");
	return 0;
}

//DFS  TLE!!!!
// void GetLevel(int idx, int &level, vector<int> &member)
// {
// 	if(member[idx] == -1)
// 	{
// 		return;
// 	}
// 	level += 1;
// 	GetLevel(member[idx], level, member);
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int num;
// 	double price, rate;
// 	in >> num >> price >> rate;

// 	vector<int> member;
// 	vector<int> member_level(num, 0);
// 	for(int i = 0; i < num; i++)
// 	{
// 		int id;
// 		in >> id;
// 		member.push_back(id);
// 	}

// 	for(int i = 0; i < num; i++)
// 	{
// 		GetLevel(i, member_level[i], member);
// 	}

// 	int count = 0;
// 	int max = 0;
// 	for(int i = 0; i < num; i++)
// 	{
// 		if(member_level[i] > max)
// 		{
// 			max = member_level[i];
// 			count = 1;
// 		}
// 		else if(member_level[i] == max)
// 		{
// 			count++;
// 		}
// 	}
// 	cout << setiosflags(ios::fixed);
// 	cout << setprecision(2) << pow((1 + rate / 100), max) * price;
// 	cout << setprecision(6);
// 	cout << " " << count << endl;

// 	system("pause");
// 	return 0;
// }
