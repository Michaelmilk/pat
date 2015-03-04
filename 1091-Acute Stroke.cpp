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

struct Point
{
	int x;
	int y;
	int z;
	Point(int a, int b, int c) : x(a), y(b), z(c){}
};

bool graphic[65][1300][130];
int row, col, slice_num, threshold;
int sum;

//segment fault (段错误) for the last two test cases
void DFS(int i, int j, int k)
{
	if(graphic[i][j][k])
	{
		sum++;
		graphic[i][j][k] = false;
		if(i > 0)
		{
			DFS(i - 1, j, k);
		}
		if(i + 1 < slice_num)
		{
			DFS(i + 1, j, k);
		}
		if (j > 0)
		{
			DFS(i, j - 1, k);
		}
		if(j + 1 < row)
		{
			DFS(i, j + 1, k);
		}
		if(k > 0)
		{
			DFS(i, j, k - 1);
		}
		if(k + 1 < col)
		{
			DFS(i, j, k + 1);
		}
	}
}


//利用队列和循环下取代递归
void DFSQue(int i, int j, int k)
{
	if(!graphic[i][j][k])
	{
		return;
	}
	queue<Point> que;
	Point p(i, j, k);
	que.push(p);

	while(!que.empty())
	{
		Point tp = que.front();
		que.pop();
		int i = tp.x;
		int j = tp.y;
		int k = tp.z;
		if(graphic[i][j][k]) 
		{
			sum++;
			graphic[i][j][k] = false;
			if(i > 0)
			{
				que.push(Point(i - 1, j, k));
			}
			if(i + 1 < slice_num)
			{
				que.push(Point(i + 1, j, k));
			}
			if (j > 0)
			{
				que.push(Point(i, j - 1, k));
			}
			if(j + 1 < row)
			{
				que.push(Point(i, j + 1, k));
			}
			if(k > 0)
			{
				que.push(Point(i, j, k - 1));
			}
			if(k + 1 < col)
			{
				que.push(Point(i, j, k + 1));
			}
		}
	}
}

int main()
{
	ifstream in("in.in");

	in >> row >> col >> slice_num >> threshold;

	for(int i = 0; i < slice_num; i++)
	{
		for(int j = 0; j < row; j++)
		{
			for(int k = 0; k < col; k++)
			{
				int val;
				in >> val;
				graphic[i][j][k] = val == 1 ? true : false;
			}
		}
	}

	int total = 0;
	for(int i = 0; i < slice_num; i++)
	{
		for(int j = 0; j < row; j++)
		{
			for(int k = 0; k < col; k++)
			{
				sum = 0;
				//DFS(i, j, k);
				DFSQue(i, j, k);
				total += sum >= threshold ? sum : 0;
			}
		}
	}

	cout << total << endl;
	system("pause");
	return 0;
}