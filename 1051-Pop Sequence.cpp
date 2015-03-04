#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>
#include <fstream>
#include <iomanip>
#include <stack>

using namespace std;


int main()
{
	ifstream in("in.in");

	int capacity, len, pop_seq_num;
	in >> capacity >> len >> pop_seq_num;
	vector<int> pop_seq;
	for(int i = 0; i < pop_seq_num; i++)
	{
		stack<int> stk;
		pop_seq.clear();
		for(int j = 0; j < len; j++)
		{
			int n;
			in >> n;
			pop_seq.push_back(n);
		}
		int idx = 1;
		int k =0;
		stk.push(idx++);
		while(true)
		{
			if(stk.empty() || stk.top() != pop_seq[k])
			{
				//cout << stk.size() << " --" << idx << endl;
				stk.push(idx++);
				if(stk.size() > capacity)
				{
					cout << "NO" << endl;
					break;
				}
				else if(k == len)
				{
					cout << "YES" << endl;
					break;
				}
			}
			else if(stk.top() == pop_seq[k])
			{
				k++;
				stk.pop();
			}
		}
		
	}

	system("pause");
	return 0;
}