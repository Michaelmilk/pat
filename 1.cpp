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


int main()
{
	int a = 93;
	printf("%04d\n", a);
	cout << setw(4) << setfill('0') << a << endl;
	stringstream ss;
	ss << setw(4) << setfill('0') << a;
	string str;
	ss >> str;
	cout << str << endl;
	
	string str1;
	ss >> str1;
	cout << str1 << endl;

	system("pause");
	return 0;
}