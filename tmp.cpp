#include <string.h>  
#include <iostream>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
#define max(a, b) ((a) > (b) ? (a) : (b))  
const int N = 10003;  
int coin[N], dp[103];  
vector<int> ans[N];   
  
int main()  
{  
    int n, total;  
    cin >> n >> total;  
    for(int i = 1; i <= n; i++)  
        cin >> coin[i];  
    coin[0] = 0;  
    sort(coin + 1, coin + 1 + n, greater<int>());  
    memset(dp, 0, sizeof(dp));  
    for(int i = 1; i <= n; i++){  
        for(int j = total; j >= coin[i]; j--){  
            if(dp[j] <= dp[j - coin[i]] + coin[i]){  
                dp[j] = dp[j - coin[i]] + coin[i];  
                ans[j].clear();  
              ans[j] = ans[j - coin[i]];
                ans[j].push_back(coin[i]);  
            }  
        }  
    }  
    if(dp[total] != total)  
        cout << "No Solution" << endl;  
    else{  
       int size = ans[total].size();
        for(int i = size - 1; i >= 0; i--)
        {
            cout << ans[total][i] << (i == 0 ? "\n" : " ");  
        }
    }  
    return 0;  
}  
