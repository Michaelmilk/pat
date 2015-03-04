#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int ReverseNum(int n, int d, vector<int> &s)
{
	int ans = 0;
	do
	{
		s.push_back(n % d);
		ans = ans * d + n % d;
		n /= d;
	}while(n);

	return ans;
}

int main()
{
	int num, radix;
	cin >> num >> radix;
	vector<int> s;
	if(num == ReverseNum(num, radix, s))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	int size = s.size();
	//int i = 0;
	for(int i = size - 1; i >= 0; i--)
	{
		cout << s[i];
		if(i != 0)
		{
			cout << " ";
		} 
	}
	//cout << s[0];
	system("pause");
	return 0;
}