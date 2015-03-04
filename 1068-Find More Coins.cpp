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

//DP ok背包二位数组
void FindMoreCoins(int money, int coin_num, vector<vector<bool> > &in, vector<int> &coins, vector<vector<int> > &dp)
{
    for(int i = 1; i <= coin_num; i++)
    {
        for(int j = coins[i]; j <= money; j++)
        {
            if(dp[i - 1][j] <= dp[i - 1][j - coins[i]] + coins[i])//<=是因为之后找出来的序列肯定更小，可以覆盖之前较大的序列！
            {
                dp[i][j] = dp[i - 1][j - coins[i]] + coins[i];
                in[i][j] = true;//表示前i个硬币中，得出最接近j时，是否用到第i个coin
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
}

int main()
{
    ifstream in1("in.in");

    int coin_num, money;
    in1 >> coin_num >> money;

    vector<int> coins(coin_num + 1);
    for(int i = 1; i <= coin_num; i++)
    {
        in1 >> coins[i];
    }

    sort(coins.begin() + 1, coins.end(), greater<int>());
    vector<vector<bool> > in(coin_num + 1, vector<bool>(money + 1, false));
    vector<vector<int> > dp(coin_num + 1, vector<int>(money + 1, 0));
    FindMoreCoins(money, coin_num, in, coins, dp);

    vector<int> ans;
    if(dp[coin_num][money] == money)
    {
        while(money)
        {
            while(!in[coin_num][money])
            {
                coin_num--;
            }
            // cout << coin_num << endl;
            // cout << coins[coin_num] << endl;
            ans.push_back(coins[coin_num]);
            money -= coins[coin_num];
            coin_num--;
        }
        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
        }
    }
    else
    {
        cout << "No Solution" << endl;
    }
    system("pause");
    return 0;
}

//DP ok背包一位数组
// void FindMoreCoins(int money, int coin_num, vector<int> &dp, vector<int> &coins, vector<vector<int> > &ans)
// {
//     for(int i = 0; i < coin_num; i++)
//     {
//         for(int j = money; j >= coins[i]; j--)
//         {
//             if(dp[j] <= dp[j - coins[i]] + coins[i])//<=是因为之后找出来的序列肯定更小，可以覆盖之前较大的序列！
//             {
//                 dp[j] = dp[j - coins[i]] + coins[i];
//                 ans[j].clear();
//                 for(int k = 0; k < ans[j - coins[i]].size(); k++)
//                 {
//                     ans[j].push_back(ans[j - coins[i]][k]);
//                 }
//                 ans[j].push_back(coins[i]);//ans[j]中保存的元素之和为j的最小序列
//             }
//         }
//     }
// }

// int main()
// {
//     ifstream in("in.in");

//     int coin_num, money;
//     in >> coin_num >> money;

//     vector<int> coins(coin_num);
//     for(int i = 0; i < coin_num; i++)
//     {
//         in >> coins[i];
//     }

//     sort(coins.begin(), coins.end(), greater<int>());
//     vector<int> dp(money + 1, 0);
//     vector<vector<int> > ans(money + 1, vector<int>());
//     FindMoreCoins(money, coin_num, dp, coins, ans);

//     if(dp[money] == money)
//     {
//         int size = ans[money].size(); 
//         for(int i = size - 1; i >= 0; i--)
//         {
//             cout << ans[money][i] << (i == 0 ? "\n" : " ");
//         }
//     }
//     else
//     {
//         cout << "No Solution" << endl;
//     }
//     system("pause");
//     return 0;
// }

//ok
// #include <string.h>  
// #include <iostream>  
// #include <vector>  
// #include <algorithm>  
// using namespace std;  
  
// #define max(a, b) ((a) > (b) ? (a) : (b))  
// const int N = 10003;  
// int coin[N], dp[103];  
// vector<int> ans[N];  
// typedef vector<int>::iterator IT;  
// typedef vector<int>::reverse_iterator RIT;  
  
// bool cmp(int m1, int m2){  
//     return m1 > m2;  
// }  
  
// int main()  
// {  
//     int n, total;  
//     cin >> n >> total;  
//     for(int i = 1; i <= n; i++)  
//         cin >> coin[i];  
//     coin[0] = 0;  
//     sort(coin + 1, coin + 1 + n, cmp);  
//     memset(dp, 0, sizeof(dp));  
//     for(int i = 1; i <= n; i++){  
//         for(int j = total; j >= coin[i]; j--){  
//             if(dp[j] <= dp[j - coin[i]] + coin[i]){  //<=是因为后面出现相等的情况时，序列一定比之前要小，可以替换之前的序列
//                 dp[j] = dp[j - coin[i]] + coin[i];  
//                 ans[j].clear();  
//                 for(IT ite = ans[j - coin[i]].begin(); ite != ans[j - coin[i]].end(); ite++)  
//                     ans[j].push_back(*ite);  
//                 ans[j].push_back(coin[i]);  
//             }  
//         }  
//     }  
//     if(dp[total] != total)  
//         cout << "No Solution" << endl;  
//     else{  
//     	int size = ans[total].size();
//         for(int i = size - 1; i >= 0; i--)
//         {
//             cout << ans[total][i] << (i == 0 ? "\n" : " ");  
//         }
//         // bool flag = true;  
//         // for(RIT ite = ans[total].rbegin(); ite != ans[total].rend(); ite++){  
//         //     if(flag){  
//         //         flag = false;  
//         //         cout << *ite;  
//         //     }  
//         //     else  
//         //         cout << " " << *ite;  
//         // }  
//         // cout << endl;  
//     }  
//     return 0;  
// }  



//TLE 最后一个case超时
// bool sign = false;
// void FindMoreCoins(int idx, int coin_num, int money, vector<int> &tmp, vector<int> &coins)
// {
// 	if(money <= 0)
// 	{
// 		if(0 == money)
// 		{
// 			int size = tmp.size();
// 			for(int i = 0; i < size; i++)
// 			{
// 				cout << tmp[i] << (i == size - 1 ? "\n" : " ");
// 			}
// 			sign = true;
// 		}
// 		return;
// 	}
	
// 	for(int i = idx; i < coin_num && !sign; i++)
// 	{
// 		tmp.push_back(coins[i]);
// 		FindMoreCoins(i + 1, coin_num, money - coins[i], tmp, coins);
// 		tmp.pop_back();
// 	}
	
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int coin_num, money;
// 	in >> coin_num >> money;

// 	vector<int> coins(coin_num);
// 	for(int i = 0; i < coin_num; i++)
// 	{
// 		in >> coins[i];
// 	}

// 	sort(coins.begin(), coins.end());
// 	vector<int> tmp;
// 	FindMoreCoins(0, coin_num, money, tmp, coins);

// 	if(!sign)
// 	{
// 		cout << "No Solution" << endl;
// 	}

// 	system("pause");
// 	return 0;
// }


//recursive -TLE

// bool sign = false;
// void FindMoreCoins(int idx, int coin_num, int money, vector<int> &tmp, vector<int> &coins)
// {
// 	int size = tmp.size();
// 	int count = 0;
// 	for(int i = 0; i < size; i++)
// 	{
// 		count += tmp[i];
// 	}

// 	if(count == money)
// 	{
// 		for(int i = 0; i < size; i++)
// 		{
// 			cout << tmp[i] << (i == size - 1 ? "\n" : " ");
// 		}
// 		sign = true;
// 		return;
// 	}
// 	else
// 	{
// 		for(int i = idx; i < coin_num && !sign; i++)
// 		{
// 			tmp.push_back(coins[i]);
// 			FindMoreCoins(i + 1, coin_num, money, tmp, coins);
// 			tmp.pop_back();
// 		}
// 	}
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int coin_num, money;
// 	in >> coin_num >> money;

// 	vector<int> coins(coin_num);
// 	for(int i = 0; i < coin_num; i++)
// 	{
// 		in >> coins[i];
// 	}

// 	sort(coins.begin(), coins.end());
// 	vector<int> tmp;
// 	FindMoreCoins(0, coin_num, money, tmp, coins);

// 	if(!sign)
// 	{
// 		cout << "No Solution" << endl;
// 	}

// 	system("pause");
// 	return 0;
// }