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

int LCS(vector<int> &favor_color, vector<int> &stripe)
{
	int fav_size = favor_color.size();
	int stripe_size = stripe.size();
	vector<vector<int> > dp(fav_size + 1, vector<int>(stripe_size + 1, 0));

	for(int i = 1; i <= fav_size; i++)
	{
		for(int j = 1; j <= stripe_size; j++)
		{
			int maxval = dp[i - 1][j - 1];
			maxval = maxval < dp[i - 1][j] ? dp[i - 1][j] : maxval;
			maxval = maxval < dp[i][j - 1] ? dp[i][j - 1] : maxval;

			if(favor_color[i - 1] == stripe[j - 1])
			{
				dp[i][j] = maxval + 1;
			}
			else
			{
				dp[i][j] = maxval;
			}
		}
	}

	return dp[fav_size][stripe_size];
}


int main()
{
	ifstream in("in.in");

	int color_num;
	in >> color_num;

	int favor_color_num;
	in >> favor_color_num;
	vector<int> favor_color(favor_color_num);
	for(int i = 0; i < favor_color_num; i++)
	{
		in >> favor_color[i];
	}

	int stripe_color_num;
	in >> stripe_color_num;
	vector<int> stripe(stripe_color_num);
	for(int i = 0; i < stripe_color_num; i++)
	{
		in >> stripe[i];
	}

	cout << LCS(favor_color, stripe) << endl;

	system("pause");
	return 0;
}