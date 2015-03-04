// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <queue>
// #include <climits>
// #include <fstream>
// #include <iomanip>
// #include <sstream>

// using namespace std;


// int main()
// {
// 	ifstream in("in.in");

// 	int case_num;
// 	in >> case_num;
// 	int idx = 1;

// 	while(idx <= case_num)
// 	{
// 		long long int a;
// 		long long int b;
// 		long long int c;
// 		in >> a >> b >> c;

// 		long long int ans = a + b;
// 		bool flag;
// 		if(a > 0 && b > 0 && ans <= 0)
// 		{
// 			flag = true;
// 		}
// 		else if(a < 0 && b < 0 && ans >= 0)
// 		{
// 			flag = false;
// 		}
// 		else
// 		{
// 			flag = (ans > c);
// 		}
// 		cout << "Case #" << idx << ": ";
// 		if(flag)
// 		{
// 			cout << "true" << endl;
// 		}
// 		else
// 		{
// 			cout << "false" << endl;
// 		}
// 		idx++;
// 	}
// 	system("pause");
// 	return 0;
// }





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
#include <sstream>

using namespace std;


int main()
{
	ifstream in("in.in");

	int case_num;
	in >> case_num;
	int idx = 1;

	while(idx <= case_num)
	{
		long long int a;
		long long int b;
		long long int c;
		in >> a >> b >> c;

		bool sign = (a >> 63) ^ (b >> 63);
		cout << "Case #" << idx << ": ";

		if(sign)
		{
			long long int d = a + b;
			if(d > c)
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}
		}
		else
		{
			if((a > 0 || b > 0) && c < 0)
			{
				cout << "true" << endl;
				idx++;
				continue;
			}
			if((a < 0 || b < 0) && c > 0)
			{
				cout << "false" << endl;
				idx++;
				continue;
			}
			if(a == 0 && b == 0)
			{
				cout << (c < 0 ? "true" : "false") << endl;
				idx++;
				continue;
			}
			if(a == 0 || b == 0)
			{
				if(a == 0)
				{
					cout << (b > c ? "true" : "false") << endl;
				}
				else
				{
					cout << (a > c ? "true" : "false") << endl;
				}
				idx++;
				continue;
			}

			stringstream s;
			s << a;
			string sa = s.str();
			s.str("");
			s << b;
			string sb = s.str();
			s.str("");
			s << c;
			string sc = s.str();
			string sd = "";
			int alen = sa.length();
			int blen = sb.length();
			int c = 0;
			for(int i = alen - 1, j = blen - 1; i >= 0 || j >= 0; i--, j--)
			{
				int aval = i >= 0 ? sa[i] - '0' : 0;
				int bval = j >= 0 ? sb[j] - '0' : 0;
				int v = aval + bval + c;
				int t = v;
				v %= 10;
				sd = (char)(v + '0') + sd;
				c = t / 10;
			}

			if(c != 0)
			{
				sd = (char(c + '0')) + sd;
			}
			if(a < 0)
			{
				sd = "-" + sd;
			}

			if(sd.length() > sc.length())
			{
				cout << ((a > 0) ? "true" : "false") << endl;
			}
			else if(sd.length() < sc.length())
			{
				cout << ((a < 0) ? "true" : "false") << endl;
			}
			else
			{
				if(a > 0)
				{
					cout << (sc < sd ? "true" : "false") << endl;
				}
				else
				{
					cout << (sc > sd ? "true" : "false") << endl;
				}
				
			}
		}
		idx++;
	}

	system("pause");
	return 0;
}