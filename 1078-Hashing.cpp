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

bool visit[20005];

bool IsPrime(int n)
{
	if (n <= 1) return false;  
    if (n == 2 || n == 3) return true; 

	int m = sqrt(n);
	for(int i = 2; i <= m; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int ProbePos(int table_size, int pos)
{
	for(int j = 1; j < table_size; j++)
	{
		int idx = (pos + j * j) % table_size;
		if(!visit[idx])
		{
			visit[idx] = true;
			return idx;
		}
	}
	return -1;
}

int main()
{
	ifstream in("in.in");

	memset(visit, 0, 20005);
	int table_size, num;
	in >> table_size >> num;

	while(!IsPrime(table_size))
	{
		table_size++;
	}

	for(int i = 0; i < num; i++)
	{
		int val;
		in >> val;
		int pos = val % table_size;
		if(!visit[pos])
		{
			visit[pos] = true;
			cout << pos;
		}
		else
		{
			pos = ProbePos(table_size, pos);
			if(-1 == pos)
			{
				cout << "-";
			}
			else
			{
				cout << pos;
			}
		}
		cout << (i == num - 1 ? "\n" : " ");
	}
	system("pause");
	return 0;
}