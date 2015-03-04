#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <cstdlib>

using namespace std;

int ReverseNum(int n, int d)
{
	int ans = 0;
	while(n)
	{
		ans = ans * d + n % d;
		n /= d;
	}
	return ans;
}

bool IsPrime(int num)
{
	if(0 == num || 1 == num)
	{
		return false;
	}

	for(int i = 2; i <= sqrt((double)num); i++)
	{
		if(num % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	while(true)
	{
		int num, radix;
		cin >> num;
		if(num < 0)
		{
			break;
		}
		cin >> radix;

		if(IsPrime(num) && IsPrime(ReverseNum(num, radix)))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}

	system("pause");
	return 0;
}