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

const int kInitVal = INT_MAX - 10000;
int city[505];
//int val[505][505];
int graphic[505][505];
int teamnum[505];
int dis[505];
bool visit[505];
int path[505];

void ComputeSP(int s, int citynum)
{
	dis[s] = 0;
	teamnum[s] = city[s];
	path[s] = 1;

	while (true)
	{
		int min = INT_MAX;
		int label;
		for (int i = 0; i < citynum; i++)
		{
			if (!visit[i] && dis[i] < min)
			{
				min = dis[i];
				label = i;
			}
		}

		if (min == INT_MAX)
		{
			break;
		}

		visit[label] = true;

		for (int i = 0; i < citynum; i++)
		{
			if (!visit[i])
			{
				int d = dis[label] + graphic[label][i];//无需判断label与i节点是否有边相连，如果没有边相连，那么graphic[label][i]==INT_MAX此时肯定比dis[i]大
				if (d < dis[i])
				{
					path[i] = path[label];
					dis[i] = d;
					teamnum[i] = teamnum[label] + city[i];
				}
				else if (d == dis[i])
				{
					path[i] += path[label];
					if (teamnum[label] + city[i] > teamnum[i])
					{
						teamnum[i] = teamnum[label] + city[i];
					}
				}
			}
		}
	}
}

int main()
{
	ifstream in("in.in");

	int citynum;
	int roadnum;
	int curpos;
	int dest;

	in >> citynum >> roadnum >> curpos >> dest;

	for (int i = 0; i < citynum; i++)
	{
		for (int j = 0; j < citynum; j++)
		{
			graphic[i][j] = kInitVal;//只要将边的初始权值赋值为最大值，那么就可以少校一个val[505][505]
		}
	}

	for (int i = 0; i <  citynum; i++)
	{
		in >> city[i];
		dis[i] = kInitVal;
		visit[i] = false;
	}

	for (int i = 0; i < roadnum; i++)
	{
		int s, e, d;
		in >> s >> e >> d;
		graphic[s][e] = d;
		graphic[e][s] = d;
		//in >> d;
		//val[s][e] = d;
		//val[e][s] = d;
	}

	ComputeSP(curpos,citynum);

	cout << path[dest] << " " << teamnum[dest] << endl;

	return 0;
}
