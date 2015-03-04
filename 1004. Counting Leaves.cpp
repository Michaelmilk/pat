#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <Windows.h>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>

using namespace std;

struct Child
{
	int label;
	Child *next;
	Child() : next(NULL){}
};

struct Node
{
	int childnum;
	Child *childhead;
	Node() : childnum(0), childhead(NULL){}
};

int countleaf[105];

void CountLeaves(int dep, int s, int &level, Node *pNode)
{
	Child* n = pNode[s].childhead;
	dep++;//record cur level info, always change by recursive
	while (n)
	{
		level = level < dep ? dep : level;//recore level of tree, record the max dep
		if (pNode[n->label].childhead == 0)
		{
			countleaf[dep]++;
		}
		else
		{
			CountLeaves(dep, n->label, level, pNode);
		}
		n = n->next;
	}
}

int main()
{
	ifstream in("in.in");

	
	int level = 0;
	memset(countleaf, 0, 105);

	int nodenum, nonleafnum;
	in >> nodenum >> nonleafnum;

	Node *pNode = new Node[nodenum + 1];

	for (int i = 0; i < nonleafnum; i++)
	{
		int id, k;
		in >> id >> k;
		pNode[id].childnum = k;
		for (int j = 0; j < k; j++)
		{
			Child *c = new Child;
			in >> c->label;
			if (pNode[id].childhead)
			{
				c->next = pNode[id].childhead;
				pNode[id].childhead = c;
			}
			else
			{
				pNode[id].childhead = c;
			}
		}
	}

	if (pNode[1].childnum == 0)
	{
		countleaf[0] = 1;
	}
	else
	{
		CountLeaves(0, 1, level, pNode);
	}

	for (int i = 0; i < level; i++)
	{
		cout << countleaf[i] << " ";
	}
	cout << countleaf[level] << endl;

	return 0;
}
