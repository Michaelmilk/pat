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

int main()
{
    ifstream in("in.in");

    int coin_num, money;
    in >> coin_num >> money;

    vector<int> coins(coin_num);
    for(int i = 0; i < coin_num; i++)
    {
        in >> coins[i];
    }

    sort(coins.begin(), coins.end());
    int left = 0;
    int right = coin_num - 1;
    while(left < right)
    {
    	if(coins[left] + coins[right] == money)
    	{
    		cout << coins[left] << " " << coins[right] << endl;
    		return 0;
    	}
    	else if(coins[left] + coins[right] > money)
    	{
    		right--;
    	}
    	else
    	{
    		left++;
    	}
    }

    cout << "No Solution" << endl;
    system("pause");
    return 0;
}