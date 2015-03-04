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
//#include <Windows.h>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>

using namespace std;

struct Item
{
	int exponent;
	double coefficient;
};

vector<Item> AddItems(vector<Item> &item1, vector<Item> &item2)
{
	if (0 == item1.size())
	{
		return item2;
	}
	else
	{
		vector<Item> ans;
		int size1 = item1.size();
		int size2 = item2.size();
		int idx1 = 0;
		int idx2 = 0;
		for (; idx1 < size1 && idx2 < size2;)
		{
			if (item1[idx1].exponent > item2[idx2].exponent)
			{
				ans.push_back(item1[idx1]);
				idx1++;
			}
			else if (item1[idx1].exponent < item2[idx2].exponent)
			{
				ans.push_back(item2[idx2]);
				idx2++;
			}
			else
			{
				Item tmp;
				double c = item1[idx1].coefficient + item2[idx2].coefficient;
				if (c != 0)
				{
					tmp.coefficient = c;
					tmp.exponent = item1[idx1].exponent;
					ans.push_back(tmp);
				}
				idx1++;
				idx2++;
			}
		}

		if (idx1 < size1)
		{
			while (idx2 < size1)
			{
				ans.push_back(item1[idx1]);
				idx1++;
			}
		}
		else if (idx2 < size2)
		{
			while (idx2 < size2)
			{
				ans.push_back(item2[idx2]);
				idx2++;
			}
		}

		return ans;
	}
}

vector<Item> ProductItems(Item item1[], Item item2[], int n1, int n2)
{
	vector<Item> ans;
	vector<Item> tmp;

	for (int i = 0; i < n1; i++)
	{
		tmp.clear();
		for (int j = 0; j < n2; j++)
		{
			Item t;
			t.coefficient = item1[i].coefficient * item2[j].coefficient;
			t.exponent = item1[i].exponent + item2[j].exponent;
			tmp.push_back(t);
		}
		ans = AddItems(ans, tmp);
	}

	return ans;
}

int main()
{
	ifstream in("in.in");

	Item item1[15];
	Item item2[15];
	int n1, n2;
	in >> n1;
	for (int i = 0; i < n1; i++)
	{
		in >> item1[i].exponent >> item1[i].coefficient;
	}

	in >> n2;
	for (int i = 0; i < n2; i++)
	{
		in >> item2[i].exponent >> item2[i].coefficient;
	}

	vector<Item> ans;
	ans = ProductItems(item1, item2, n1, n2);
	
	int size = ans.size();
	cout << size;
	for (int i = 0; i < size; i++)
	{
		cout << " " << ans[i].exponent << " ";
		cout << setiosflags(ios::fixed);
		cout << setprecision(1) << ans[i].coefficient;
		cout << setprecision(6);
	}
	return 0;
}
