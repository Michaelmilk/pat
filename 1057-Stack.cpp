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

ifstream in("in.in");
#define cin in


multiset<int, greater<int> > lower;
multiset<int> upper;
stack<int> stk;
int median_val;

//调整的目的是为了使中位数始终位于lower的begin（）的位置
void Adjust()
{
	if(upper.size() > lower.size())
	{
		lower.insert(*(upper.begin()));
		upper.erase(upper.begin());
	}
	else if(upper.size() + 1 < lower.size())
	{
		upper.insert(*(lower.begin()));
		lower.erase(lower.begin());
	}
	median_val = *(lower.begin());
}

int main()
{
	int num;
	//cin >> num;
	scanf("%d", &num);

	for(int i = 0; i < num; i++)
	{
		string cmd;
		//cin >> cmd;
		scanf("%s", cmd.c_str());
		cmd = (string)cmd.c_str();
		if(cmd == "Push")
		{
			int n;
			//cin >> n;
			scanf("%d", &n);
			stk.push(n);
			if(n > median_val)
			{
				upper.insert(n);
			}
			else
			{
				lower.insert(n);
			}
			Adjust();//需要重新调整
		}
		else if(cmd == "Pop")
		{
			if(stk.size() != 0)
			{
				int key = stk.top();
				//cout <<	key << endl;
				printf("%d\n", key);
				stk.pop();
				if(key > median_val)
				{
					upper.erase(upper.find(key));
				}
				else
				{
					lower.erase(lower.find(key));
				}
			}
			else
			{
				//cout << "Invalid" << endl;
				printf("Invalid\n");
			}
			Adjust();//需要重新调整
		}
		else if(cmd == "PeekMedian")
		{
			if(stk.size() != 0)
			{
				//cout << median_val << endl;
				printf("%d\n", median_val);
			}
			else
			{
				//cout << "Invalid" << endl;
				printf("Invalid\n");
			}
		}
	}
	system("pause");
	return 0;
}