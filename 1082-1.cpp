#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <cstdio>

using namespace std;

struct Elem
{
	double coefficient;
	int exponent;
};


int main()
{
	ifstream in("in.in");
	Elem v1[12];
	Elem v2[12];
	Elem ans[30];

	int item1, item2;
	double coeffi;
	int exp;
	in >> item1;
	for (int i = 0; i < item1; i++)
	{

		in >> exp >> coeffi;
		v1[i].coefficient = coeffi;
		v1[i].exponent = exp;
	}

	in >> item2;
	for (int j = 0; j < item2; j++)
	{
		in >> exp >> coeffi;
		v2[j].coefficient = coeffi;
		v2[j].exponent = exp;
	}

	int items = 0;
	int idx1 = 0;
	int idx2 = 0;
	for (; idx1 < item1 && idx2 < item2;)
	{
		if (v1[idx1].exponent > v2[idx2].exponent)
		{
			//if (v1[idx1].coefficient != 0)
			//{
				ans[items].coefficient = v1[idx1].coefficient;
				ans[items].exponent = v1[idx1].exponent;
				items++;
			//}
			idx1++;
		}
		else if (v1[idx1].exponent < v2[idx2].exponent)
		{
			//if (v2[idx2].coefficient != 0)
			//{
				ans[items].coefficient = v2[idx2].coefficient;
				ans[items].exponent = v2[idx2].exponent;
				items++;
			//}
			idx2++;
		}
		else
		{
			double c = v1[idx1].coefficient + v2[idx2].coefficient;
			if (c != 0)
			{
				ans[items].coefficient = c;
				ans[items].exponent = v2[idx2].exponent;
				items++;
			}

			idx1++;
			idx2++;
		}

	}

	//cout << items << endl;

	if (idx1 < item1)
	{
		while (idx1 < item1)
		{
			//if (v1[idx1].coefficient != 0)
			//{
				ans[items].coefficient = v1[idx1].coefficient;
				ans[items].exponent = v1[idx1].exponent;
				items++;
			//}
			idx1++;
		}
	}
	else if (idx2 < item2)
	{
		while (idx2 < item2)
		{
			//if (v2[idx2].coefficient != 0)
			//{
				ans[items].coefficient = v2[idx2].coefficient;
				ans[items].exponent = v2[idx2].exponent;
				items++;
			//}
			idx2++;
		}
	}

	cout << items;

	for (int k = 0; k < items; k++)
	{
		cout << ' ' << ans[k].exponent << ' ';
		//printf("%.1lf", ans[k].coefficient);
		cout << setiosflags(ios::fixed);
		cout << setprecision(1) << ans[k].coefficient;
		cout << setprecision(6);
	}

	return 0;
}