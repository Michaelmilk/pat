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
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>

using namespace std;

int postorder[35];
int inorder[35];

void traversal(int level, int &depth, vector<vector<int> > &ans, int ps, int pe, int is, int ie)
{
	if (is <= ie)
	{
		depth = level > depth ? level : depth;
		int id = postorder[pe];
		ans[level].push_back(id);
		int mid = ie;
		for (int i = is; i < ie; i++)
		{
			if (inorder[i] == id)
			{
				mid = i;
				break;
			}
		}

		int d = level + 1;
		int diff = mid - is;
		traversal(d, depth, ans, ps, ps + diff - 1, is, mid - 1);
		traversal(d, depth, ans, ps + diff, pe - 1, mid + 1, ie);
	}
}

int main()
{
	ifstream in("in.in");

	int nodenum;
	in >> nodenum;

	for (int i = 0; i < nodenum; i++)
	{
		in >> postorder[i];
	}

	for (int i = 0; i < nodenum; i++)
	{
		in >> inorder[i];
	}

	vector<vector<int> > ans(nodenum, vector<int>());
	int depth = 0;
	traversal(0, depth, ans, 0, nodenum - 1, 0, nodenum - 1);

	for (int i = 0; i <= depth; i++)
	{
		int size = ans[i].size();
		for (int j = 0; j < size; j++)
		{
			cout << ans[i][j];
			if (i == depth && j == size - 1)
			{
				break;
			}
			cout << " ";
		}
	}

	return 0;
}
