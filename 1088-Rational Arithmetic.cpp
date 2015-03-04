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

long int GCD(long int d1, long int d2)
{
	while(d2)
	{
		long int t = d1 % d2;
		d1 = d2;
		d2 = t;
	}
	return d1;
}

string GenerateFormat(long int numerator, long int denominator)
{
	long int num = abs(numerator);
	long int denom = abs(denominator);
	long int gcd = GCD(num, denom);
	num /= gcd;
	denom /= gcd;
	//cout << numerator << " " << denominator << endl;
	//int num = abs(numerator);
	if(numerator == 0)
	{
		return "0";
	}
	string format = "";
	stringstream ss;
	if(!(numerator < 0 && denominator < 0) && (numerator < 0 || denominator < 0))
	{
		format += "(-";
	}
	if(num >= denom)
	{
		ss << (num / denom);
		string ts;
		ss >> ts;
		format += ts;
		//format += (num / denom) + '0';
		num %= denom;
		format += num == 0 ? "" : " ";
	}

	if(num != 0)
	{
		ss.clear();
		ss << num;
		string ts;
		ss >> ts;
		format += ts;
		//format += num + '0';
		format += '/';
		ss.clear();
		ss << denom;
		ss >> ts;
		format += ts;
		//format += denom + '0';
	}
	
	if(format[0] == '(')
	{
		format += ')';
	}

	return format;
}

long int LCM(long int d1, long int d2)
{
	return d1 * d2 / GCD(d1, d2);
}

int main()
{
	long int numerator1, denominator1;
	long int numerator2, denominator2;
	scanf("%ld/%ld", &numerator1, &denominator1);
	scanf("%ld/%ld", &numerator2, &denominator2);

	string format1 = GenerateFormat(numerator1, denominator1);
	string format2 = GenerateFormat(numerator2, denominator2);

	cout << format1 << " + " << format2 << " = ";
	long int denominator = LCM(denominator1, denominator2);
	long int numerator = numerator1 * (denominator / denominator1) + numerator2 *(denominator / denominator2);
	//cout << numerator << " " << denominator << endl;
	string format3 = GenerateFormat(numerator, denominator);
	cout << format3 << endl;
	
	cout << format1 << " - " << format2 << " = ";
	denominator = LCM(denominator1, denominator2);
	numerator = numerator1 * (denominator / denominator1) - numerator2 *(denominator / denominator2);
	format3 = GenerateFormat(numerator, denominator);
	cout << format3 << endl;

	cout << format1 << " * " << format2 << " = ";
	denominator = denominator1 * denominator2;
	numerator = numerator1 * numerator2;
	format3 = GenerateFormat(numerator, denominator);
	cout << format3 << endl;

	cout << format1 << " / " << format2 << " = ";
	if(numerator2 == 0)
	{
		cout << "Inf" << endl;
	}
	else
	{
		denominator = denominator1 * numerator2;
		numerator = numerator1 * denominator2;
		//cout << numerator << " " << denominator << endl;
		format3 = GenerateFormat(numerator, denominator);
		cout << format3 << endl;
	}
	

	system("pause");
	return 0;
}