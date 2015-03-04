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

ifstream in("in.in");
#define cin in

int main()
{
	long int num1, num2;
	//cin >> num1;
	scanf("%ld", &num1);
	vector<long int> v1(num1);
	for(int i = 0; i < num1; i++)
	{
		//cin >> v1[i];
		scanf("%ld", &v1[i]);
	}

	//cin >> num2;
	scanf("%ld", &num2);
	vector<long int> v2(num2);
	for(int i = 0; i < num2; i++)
	{
		//cin >> v2[i];
		scanf("%ld", &v2[i]);
	}
	int count = 0;
	//int bound = (num1 + num2) % 2 == 0 ? (num1 + num2) / 2 - 1 : (num1 + num2) / 2;
	int bound = (num1 + num2 - 1) / 2;//上面的代码，如果num1=0，num2=1，那么就会出现bound=-1的情况！！！
	//int idx;
	//int flag;
	int i, j;
	for(i = 0, j = 0; i < num1 && j < num2;)
	{
		//注意idx和flag的位置一记count与bound比较一定要放在if-else内部
		if(v1[i] < v2[j])
		{
			//idx = i;
			//flag = 1;
			if(count == bound)
			{
				//cout << (flag == 1 ? v1[idx] : v2[idx]) << endl;
				printf("%ld\n", v1[i]);
				break;
			}
			i++;
			count++;
		}
		else
		{
			//idx = j;
			//flag = 2;
			if(count == bound)
			{
				//cout << (flag == 1 ? v1[idx] : v2[idx]) << endl;
				printf("%ld\n", v2[j]);
				break;
			}
			j++;
			count++;
		}
	}

	if(i == num1)
	{
		//cout << v2[j + (bound - count)] << endl;
		printf("%ld\n", v2[j + (bound - count)]);
	}
	if(j == num2)
	{
		//cout << v1[i + (bound - count)] << endl;
		printf("%ld\n", v1[i + (bound - count)]);
	}
	system("pause");
	return 0;
}