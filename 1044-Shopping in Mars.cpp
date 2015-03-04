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

void BinSearch(int s, int &e, int &count, int &pay, vector<int> &sum)
{
	int l = s;
	int r = sum.size() - 1;
	while(l < r)
	{
		int mid = (l + r) / 2;
		if(sum[mid] - sum[s - 1] >= pay)
		{
			r = mid;//把r作为返回值
		}
		else
		{
			l = mid + 1;//sum[mid] - sum[s - 1]<pay所以mid不可能是相等的点
		}
	}
	e = r;
	count = sum[e] - sum[s - 1];
}

int main()
{
	int chain_len, pay;
	cin >> chain_len >> pay;
	//scanf("%d%d", &chain_len, &pay);

	vector<int> diamond(chain_len + 1);
	vector<int> sum(chain_len + 1, 0);
	for(int i = 1; i <= chain_len; i++)
	{
		cin >> diamond[i];
		//scanf("%d", &diamond[i]);
		sum[i] = sum[i - 1] + diamond[i];
	}
	vector<pair<int, int> > equal_range;
	bool has_equal_range = false;
	int count = 0;
	int diff = INT_MAX;
	int best = -1;
	for(int i = 1; i <= chain_len; i++)
	{
		int end;
		BinSearch(i, end, count, pay, sum);
		//当第一次返回或者返回的值比之前的数距离pay更近同时大于等于pay
		if(best == -1 || (count < best && count >= pay))
		{
			best = count;
			equal_range.clear();
			equal_range.push_back(pair<int, int>(i, end));
		}
		else if(best != -1 && count == best)//多个最优值的情况
		{
			equal_range.push_back(pair<int, int>(i, end));
		}
		// if(count == pay)
		// {
		// 	if(!has_equal_range)//不能每次都clear，只有当第一次找到相等的区间时才能clear
		// 	{
		// 		equal_range.clear();
		// 	}
		// 	equal_range.push_back(pair<int, int>(i, end));
		// 	has_equal_range = true;
		// }
		// else if(!has_equal_range && count > pay)
		// {
		// 	if(diff > count - pay)
		// 	{
		// 		diff = count - pay;
		// 		equal_range.clear();
		// 		equal_range.push_back(pair<int, int>(i, end));
		// 	}
		// 	else if(diff == count - pay)
		// 	{
		// 		equal_range.push_back(pair<int, int>(i, end));
		// 	}
		// }
	}

	int size = equal_range.size();
	for(int i = 0; i < size; i++)
	{
          printf("%d-%d\n", equal_range[i].first, equal_range[i].second);
		//cout << equal_range[i].first + 1 << "-" << equal_range[i].second + 1 << endl;
	}

	system("pause");
	return 0;
}


//one case TLE
// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <climits>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <fstream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>


// using namespace std;

// ifstream in("in.in");
// #define cin in

// int main()
// {
// 	int chain_len, pay;
// 	//cin >> chain_len >> pay;
// 	scanf("%d%d", &chain_len, &pay);

// 	vector<int> diamond(chain_len);
// 	for(int i = 0; i < chain_len; i++)
// 	{
// 		//cin >> diamond[i];
// 		scanf("%d", &diamond[i]);
// 	}

// 	vector<pair<int, int> > equal_range;
// 	bool has_equal_range = false;
// 	int count = 0;
// 	int diff = INT_MAX;
// 	int jmp = 0;
// 	for(int i = 0; i < chain_len; i++)
// 	{
// 		count = jmp == 0 ? 0 : count - diamond[i - 1];
// 		for(int j = i + jmp; j < chain_len; j++)
// 		{
// 			jmp = 0;
// 			count += diamond[j];
// 			if(count == pay)
// 			{
// 				if(!has_equal_range)//不能每次都clear，只有当第一次找到相等的区间时才能clear
// 				{
// 					equal_range.clear();
// 				}
// 				equal_range.push_back(pair<int, int>(i, j));
// 				has_equal_range = true;
// 				jmp = j - i;
// 				break;
// 			}
// 			else if(!has_equal_range && count > pay)
// 			{
// 				if(diff > count - pay)
// 				{
// 					diff = count - pay;
// 					equal_range.clear();
// 					equal_range.push_back(pair<int, int>(i, j));
// 				}
// 				else if(diff == count - pay)
// 				{
// 					equal_range.push_back(pair<int, int>(i, j));
// 				}
// 			}
// 		}
// 	}

// 	int size = equal_range.size();
// 	for(int i = 0; i < size; i++)
// 	{
// 		printf("%d-%d\n", equal_range[i].first + 1, equal_range[i].second + 1);
// 		//cout << equal_range[i].first + 1 << "-" << equal_range[i].second + 1 << endl;
// 	}

// 	system("pause");
// 	return 0;
// }


//TLE
// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <climits>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <fstream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>


// using namespace std;

// ifstream in("in.in");
// #define cin in

// int main()
// {
// 	int chain_len, pay;
// 	cin >> chain_len >> pay;

// 	vector<int> diamond(chain_len);
// 	for(int i = 0; i < chain_len; i++)
// 	{
// 		cin >> diamond[i];
// 	}

// 	vector<pair<int, int> > equal_range;
// 	bool has_equal_range = false;
// 	int count = 0;
// 	int diff = INT_MAX;
// 	for(int i = 0; i < chain_len; i++)
// 	{
// 		count = 0;
// 		for(int j = i; j < chain_len; j++)
// 		{
// 			count += diamond[j];
// 			if(count == pay)
// 			{
// 				if(!has_equal_range)//不能每次都clear，只有当第一次找到相等的区间时才能clear
// 				{
// 					equal_range.clear();
// 				}
// 				equal_range.push_back(pair<int, int>(i, j));
// 				has_equal_range = true;
// 			}
// 			else if(!has_equal_range && count > pay)
// 			{
// 				if(diff > count - pay)
// 				{
// 					diff = count - pay;
// 					equal_range.clear();
// 					equal_range.push_back(pair<int, int>(i, j));
// 				}
// 				else if(diff == count - pay)
// 				{
// 					equal_range.push_back(pair<int, int>(i, j));
// 				}
// 			}
// 		}
// 	}

// 	int size = equal_range.size();
// 	for(int i = 0; i < size; i++)
// 	{
// 		cout << equal_range[i].first + 1 << "-" << equal_range[i].second + 1 << endl;
// 	}

// 	system("pause");
// 	return 0;
// }


//one case TLE
// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <climits>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <fstream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>


// using namespace std;

// ifstream in("in.in");
// #define cin in

// int main()
// {
// 	int chain_len, pay;
// 	cin >> chain_len >> pay;

// 	vector<int> diamond(chain_len);
// 	for(int i = 0; i < chain_len; i++)
// 	{
// 		cin >> diamond[i];
// 	}

// 	vector<pair<int, int> > equal_range;
// 	bool has_equal_range = false;
// 	int count = 0;
// 	int diff = INT_MAX;
// 	int jmp = 0;
// 	for(int i = 0; i < chain_len; i++)
// 	{
// 		count = jmp == 0 ? 0 : count - diamond[i - 1];
// 		for(int j = i + jmp; j < chain_len; j++)
// 		{
// 			jmp = 0;
// 			count += diamond[j];
// 			if(count == pay)
// 			{
// 				if(!has_equal_range)//不能每次都clear，只有当第一次找到相等的区间时才能clear
// 				{
// 					equal_range.clear();
// 				}
// 				equal_range.push_back(pair<int, int>(i, j));
// 				has_equal_range = true;
// 				jmp = j - i;
// 				break;
// 			}
// 			else if(!has_equal_range && count > pay)
// 			{
// 				if(diff > count - pay)
// 				{
// 					diff = count - pay;
// 					equal_range.clear();
// 					equal_range.push_back(pair<int, int>(i, j));
// 				}
// 				else if(diff == count - pay)
// 				{
// 					equal_range.push_back(pair<int, int>(i, j));
// 				}
// 			}
// 		}
// 	}

// 	int size = equal_range.size();
// 	for(int i = 0; i < size; i++)
// 	{
// 		cout << equal_range[i].first + 1 << "-" << equal_range[i].second + 1 << endl;
// 	}

// 	system("pause");
// 	return 0;
// }


// //TLE
// // #include <iostream>
// // #include <vector>
// // #include <string>
// // #include <iterator>
// // #include <cmath>
// // #include <map>
// // #include <algorithm>
// // #include <climits>
// // #include <iomanip>
// // #include <queue>
// // #include <stack>
// // #include <deque>
// // #include <sstream>
// // #include <set>
// // #include <fstream>
// // #include <cstring>
// // #include <cstdio>
// // #include <cstdlib>


// // using namespace std;

// // ifstream in("in.in");
// // #define cin in

// // int main()
// // {
// // 	int chain_len, pay;
// // 	cin >> chain_len >> pay;

// // 	vector<int> diamond(chain_len);
// // 	for(int i = 0; i < chain_len; i++)
// // 	{
// // 		cin >> diamond[i];
// // 	}

// // 	vector<pair<int, int> > equal_range;
// // 	bool has_equal_range = false;
// // 	int count = 0;
// // 	int diff = INT_MAX;
// // 	for(int i = 0; i < chain_len; i++)
// // 	{
// // 		count = 0;
// // 		for(int j = i; j < chain_len; j++)
// // 		{
// // 			count += diamond[j];
// // 			if(count == pay)
// // 			{
// // 				if(!has_equal_range)//不能每次都clear，只有当第一次找到相等的区间时才能clear
// // 				{
// // 					equal_range.clear();
// // 				}
// // 				equal_range.push_back(pair<int, int>(i, j));
// // 				has_equal_range = true;
// // 			}
// // 			else if(!has_equal_range && count > pay)
// // 			{
// // 				if(diff > count - pay)
// // 				{
// // 					diff = count - pay;
// // 					equal_range.clear();
// // 					equal_range.push_back(pair<int, int>(i, j));
// // 				}
// // 				else if(diff == count - pay)
// // 				{
// // 					equal_range.push_back(pair<int, int>(i, j));
// // 				}
// // 			}
// // 		}
// // 	}

// // 	int size = equal_range.size();
// // 	for(int i = 0; i < size; i++)
// // 	{
// // 		cout << equal_range[i].first + 1 << "-" << equal_range[i].second + 1 << endl;
// // 	}

// // 	system("pause");
// // 	return 0;
// // }