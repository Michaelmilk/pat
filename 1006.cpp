#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Person
{
	string id;
	string st;
	string et;
	//int hour;
	//int minute;
	//int second;
	Person() : id("") , st(""), et(""){}
};

int main()
{
	ifstream in("in.in");
	int n;
	in >> n;

	Person *pPerson = new Person[n];
	for(int i = 0; i < n; i++)
	{
		//string buf1;
		//string buf2;
		//string buf3;
		//sscanf(info.c_str(),"%s%s%s",buf1, buf2, buf3);
		in >> pPerson[i].id;
		in >> pPerson[i].st;
		in >> pPerson[i].et;
	}

	string early = pPerson[0].st, last = pPerson[0].et;
	string ename = pPerson[0].id, lname = pPerson[0].id;
	for(int i = 1; i < n; i++)
	{
		if(pPerson[i].st < early)
		{
			early = pPerson[i].st;
			ename = pPerson[i].id;
		}

		if(pPerson[i].et > last)
		{
			last = pPerson[i].et;
			lname = pPerson[i].id;
		}
	}

	cout << ename << " " << lname;
	system("pause");
	return 0;
}