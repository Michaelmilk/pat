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

// 1. 一定都要用Long long int，不然会错很多case;

// 2. 注意计算radix的值时，有可能会发生溢出，得到的result结果为负数，此时应该减少radix的值;

// 3. 不能使用简单的顺序搜索算法，应该使用二分法搜索；

// 除了只有一位数时候可能出现多个解，其余情况均只有一个解。

// 二分法搜索能够保证得到的结果唯一并且正确。

int CharToInt(char ch)
{
	if(ch >= '0' && ch <= '9')
	{
		return ch - '0';
	}
	else
	{
		return ch - 'a' + 10;
	}
}

long long ConvertToDecimal(char *c, long long radix)
{
	long long ans = 0;
	int len = strlen(c);
	for(int i = 0; i < len; i++)
	{
		ans *= radix;
		ans += CharToInt(c[i]);
		if(ans < -1)//注意计算radix的值时，有可能会发生溢出，得到的result结果为负数，此时应该减少radix的值;
		{
			return -1;
		}
	}
	return ans;
}

int main()
{
	char a[15], b[15], t[15];
	long long tag, radix, num;
	scanf("%s %s %lld %lld", a, b, &tag, &radix);

	if(tag == 1)//之后的处理无需再去判断radix是哪个值的radix值
	{
		strcpy(t, a);
		strcpy(a, b);
		strcpy(b, t);
	}

	long long radix_val = ConvertToDecimal(b, radix);//将已知的数和进制转换成十进制数
	int len_a = strlen(a);
	long long lower_radix = 2;//进制的下限
	for(int i = 0; i < len_a; i++)
	{
		int r = CharToInt(a[i]);
		if(r > lower_radix)
		{
			lower_radix = r + 1;//因为进制肯定至少比当前的数值中的最大数字大1
		}
	}

	long long high_radix = radix_val + 1;//一个数的最大进制就是进制等于当前值加1，如果第二个数超过这数那么，它肯定比第一个数大
	long long mid_radix;
	long long t_val;
	bool flag = false;
	while(lower_radix <= high_radix)
	{
		mid_radix = (lower_radix + high_radix) / 2;
		t_val = ConvertToDecimal(a, mid_radix);
		if(t_val == -1 || t_val > radix_val)
		{
			high_radix = mid_radix - 1;
		}
		else if(t_val < radix_val)
		{
			lower_radix = mid_radix + 1;
		}
		else
		{
			flag = true;
			break;
		}
	}

	if(flag)
	{
		printf("%lld\n", mid_radix);
	}
	else
	{
		printf("Impossible\n");
	}

	system("pause");
	return 0;
}