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

void PrintNextSortIteration(int size, vector<int> &ans)
{
	for(int i = 0; i < size; i++)
	{
		cout << ans[i] << (i == size - 1 ? "\n" : " ");
	}
}

bool IsEqual(int size, vector<int> &a, vector<int> &b)
{
	for(int i = 0; i < size; i++)
	{
		if(a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}

bool IsInsertSort(int size, vector<int> &original, vector<int> &serveral_sort)
{
	bool sign = false;
	bool is_next = false;
	vector<int> tmp(original);
	for(int i = 2; i <= size; i++)
	{
		//之所以可以先先排序后比较，是因为给定的第二个序列肯定是先排过一次序的，
		//否则无法区分为那种排序方法
		sort(tmp.begin(), tmp.begin() + i);
		is_next = sign ? true : false;
		sign = sign ? true : IsEqual(size, tmp, serveral_sort);
		if(sign && is_next)
		{
			cout << "Insertion Sort" << endl;
			PrintNextSortIteration(size, tmp);
			return true;
		}
	}
	return false;
}

void MergeSort(int size, vector<int> &original, vector<int> &serveral_sort)
{
	bool sign = false; 
	bool is_next = false;
	for(int i = 2; i <= size; i *= 2)
	{
		//之所以可以先先排序后比较，是因为给定的第二个序列肯定是先排过一次序的，
		//否则无法区分为那种排序方法
		int j;
		for(j = 0; j + i <= size; j += i)
		{
			sort(original.begin() + j, original.begin() + i + j);
		}
		sort(original.begin() + j, original.end());//不能二分剩下的数
		is_next = sign ? true : false;//是否上一个序列与serveral_sort相等时，此时oringinal是否为下一个所求的序列
		sign = sign ? true : IsEqual(size, original, serveral_sort);
		if(sign && is_next)
		{
			cout << "Merge Sort" << endl;
			PrintNextSortIteration(size, original);
			return;
		}
	}
}

int main()
{
	ifstream in("in.in");

	int num;
	in >> num;

	vector<int> original(num);
	for(int i = 0; i < num; i++)
	{
		in >> original[i];
	}

	vector<int> serveral_sort(num);
	for(int i = 0; i < num; i++)
	{
		in >> serveral_sort[i];
	}

	if(!IsInsertSort(num, original, serveral_sort))
	{
		MergeSort(num, original, serveral_sort);
	}
	system("pause");
	return 0;
}
