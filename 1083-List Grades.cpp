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

struct Student
{
	string name;
	string id;
	int grade;
	bool operator<(const Student &s) const
	{
		return grade > s.grade;
	}
};


int main()
{
	ifstream in("in.in");

	int stu_num;
	in >> stu_num;
	vector<Student> student(stu_num);
	for(int i = 0; i < stu_num; i++)
	{
		in >> student[i].name >> student[i].id >> student[i].grade;
	}

	sort(student.begin(), student.end());

	int left;
	int right;
	in >> left >> right;
	bool flag = false;
	for(int i =0; i < stu_num; i++)
	{
		if(student[i].grade >= left && student[i].grade <= right)
		{
			cout << student[i].name << " " << student[i].id << endl;
			flag = true;
		}
	}

	if(!flag)
	{
		cout << "NONE" << endl;
	}

	system("pause");
	return 0;
}