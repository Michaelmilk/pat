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

using namespace std;

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	int sum = a + b;
	if(sum < 0)
	{
		cout << "-";
		sum = -sum;
	}

	stringstream ss;
	ss << sum;
	string s;
	ss >> s;

	int len = s.length();
	string ans = "";
	int count = 0;
	for(int i = len - 1; i >= 0; i--)
	{
		ans += s[i];
		count++;
		if(count == 3 && i != 0)
		{
			ans += ",";
			count = 0;
		}
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	system("pause");
	return 0;
}