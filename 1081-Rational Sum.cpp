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

struct Fractional
{
	long long int numerator;
	long long int denominator;
};

long long int GCD(long long int a, long long int b)
{
	long long int t;
	while(t = a % b)
	{
		a = b;
		b = t;
	}
	return b;
}

long long int LCM(long long int a, long long int b)
{
	return a * (b / GCD(a, b));
}

int main()
{
	//ifstream in("in.in");
	FILE *fin = freopen("in.in", "r", stdin);
	int n;
	fscanf(fin, "%d", &n);
	if(0 == n)
	{
		cout << 0 << endl;
		return 0;
	}

	vector<Fractional> fraction;
	for(int i = 0; i < n; i++)
	{
		Fractional f;
		fscanf(fin, "%lld/%lld", &f.numerator , &f.denominator);
		fraction.push_back(f);
	}

	int size = fraction.size();
	long long int lcm = fraction[0].denominator;
	for(int i = 1; i < size; i++)
	{
		lcm = LCM(lcm, fraction[i].denominator);
	}
	
	long long int sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum += fraction[i].numerator * (lcm / fraction[i].denominator);
	}
	long long int mul = sum / lcm;
	if(mul != 0)
	{
		cout << mul;
		sum %= lcm;
	}
	if(sum != 0)
	{
		if(mul != 0)
		{
			cout << " ";
			sum = abs(sum);
		}
		long long int gcd = GCD(abs(sum), lcm);
		cout << sum / gcd << "/" << lcm / gcd;
	}
	if(mul == 0 && sum == 0)
	{
		cout << 0 << endl;
	}

	system("pause");
	return 0;
}

// #include <cstdio>
// #include <cstdlib>

// using namespace std;

// long long gcd(long long a, long long b) {
//     long long r;
//     while (r = (a % b)) {
//         a = b;
//         b = r;
//     }
//     return b;
// }

// int main() {

//     int N;
//     scanf("%d", &N);
//     long long sa = 0, sb = 1, a, b;
    
//     for (int i=0; i<N; i++) {
//         scanf("%lld/%lld", &a, &b);
//         long long newb = b * sb / gcd(b, sb);
//         long long sf =  newb / sb;
//         long long cf =  newb / b;
//         sa = sa * sf + a * cf;
//         sb = newb;
//         long long c = gcd(sa < 0 ? -sa : sa, sb);
//         sa = sa/c;
//         sb = sb/c;
//     }
    
//     if (sa < 0) {
//         printf("-");
//         sa = -sa;
//     }
//     long long r = sa % sb;
//     long long q = sa / sb;
//     if (r == 0) {
//         printf("%lld\n", q);
//     } else {
//         if (q != 0) {
//             printf("%lld ", q);
//         }
//         printf("%lld/%lld\n", r, sb);
//     }
//     system("pause");
//     return 0;
// }