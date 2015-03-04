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

// struct  Retailer
// {
// 	int products_num;
// 	double price;
// };

struct Distributor
{
	int id;
	double price;
};

int main()
{
	ifstream in("in.in");

	map<int, int> retailers;
	int n;
	double root_price, rate;
	in >> n >> root_price >> rate;

	vector<vector<Distributor> > members(n, vector<Distributor>());

	for(int i = 0; i < n; i++)
	{
		int num;
		in >> num;
		if(0 == num)
		{
			int products_num;
			in >> products_num;
			retailers[i] = products_num;
		}
		else
		{
			for(int j = 0; j < num; j++)
			{
				int retailer_id;
				in >> retailer_id;
				Distributor d;
				d.id = retailer_id;
				d.price = 0;
				members[i].push_back(d);
			}
		}
	}

	double profile = 0;
	queue<Distributor> que;
	Distributor root;
	root.id = 0;
	root.price = root_price;
	que.push(root);

	while(!que.empty())
	{
		Distributor mem = que.front();
		que.pop();
		
		int size = members[mem.id].size();
		if(0 == size)
		{
			profile += mem.price * retailers[mem.id];
			//continue;
		}
		else
		{
			double cur_price = mem.price * (100 + rate) / 100;
			for(int i = 0; i < size; i++)
			{
				members[mem.id][i].price = cur_price;
				que.push(members[mem.id][i]);
			}
		}
	}

	cout << fixed << setprecision(1) << profile << endl;

	system("pause");
	return 0;
}