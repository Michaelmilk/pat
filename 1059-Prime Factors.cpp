#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <climits>
#include <fstream>
#include <iomanip>

using namespace std;

bool IsPrime(int factor)
{
	for(int i = 2; i <= sqrt(factor); i++)
	{
		if(factor % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	long long int n;
	cin >> n;

	int k = sqrt(n);
	int num = n;
	map<int, int> fac_mp;
	for(int i = 2; i <= k; i++)
	{
		if(num % i == 0 && IsPrime(i))
		{
			if(fac_mp.find(i) == fac_mp.end())
			{
				fac_mp[i] = 1;
			}
			else
			{
				fac_mp[i]++;
			}

			k = sqrt(num / i);
			num /= i;
			if(IsPrime(num))
			{
				if(fac_mp.find(num) == fac_mp.end())
				{
					fac_mp[num] = 1;
				}
				else
				{
					fac_mp[num]++;
				}
				break;
			}
			i = 1;
		}
	}

	cout << n << "=";
	map<int, int>::iterator it = fac_mp.begin();
	if(!fac_mp.empty())
	{
		cout << it->first;
		if(it->second > 1)
		{
			cout << "^" << it->second;
		}
	}
	else
	{
		cout << n << endl;
		return 0;
	}
	for(it++; it != fac_mp.end(); it++)
	{
		cout << "*";
		cout << it->first;
		if(it->second > 1)
		{
			cout << "^" << it->second;
		}
	}

	system("pause");
	return 0;
}