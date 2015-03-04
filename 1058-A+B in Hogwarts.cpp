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
#include <cstdio>

using namespace std;


int main()
{
	int a1, a2, a3;
	scanf("%d.%d.%d", &a3, &a2, &a1);
	int b1, b2, b3;
	scanf("%d.%d.%d", &b3, &b2, &b1);

	int c = 0;
	int c1, c2, c3;
	c1 = a1 + b1;
	c = c1 / 29;
	c1 %= 29;
	c2 = a2 + b2 + c;
	c = c2 / 17;
	c2 %= 17;
	c3 = a3 + b3 + c;
	//c3 %= 10000001;

	cout << c3 << "." << c2 << "." << c1 << endl;
	system("pause");
	return 0;
}