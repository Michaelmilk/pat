#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct Student
{
	string name;
	char gender;
	string id;
	int grader;
	/*bool operator<(Student s)
	{
		return grade > s.grade;
	}*/
};

int main()
{
	ifstream in("in.in");

	int n;
	in >> n;
	vector<Student> student(n);
	for(int i = 0; i < n; i++)
	{
		in >> student[i].name >> student[i].gender >> student[i].id >> student[i].grader;
	}

	// sort(student.begin(), student.end());

	Student f_grade;
	f_grade.grader = -1;
	Student m_grade;
	m_grade.grader = 101;
	for(int i = 0; i < n; i++)
	{
		if(student[i].gender == 'F' && student[i].grader > f_grade.grader)
		{
			f_grade = student[i];
		}

		if(student[i].gender == 'M' && student[i].grader < m_grade.grader)
		{
			m_grade = student[i];
		}
	}

	int sign = false;
	if(f_grade.grader == -1)
	{
		sign = true;
		cout << "Absent" << endl;
	}
	else
	{
		cout << f_grade.name << " " << f_grade.id << endl;
	}

	if(m_grade.grader == -1)
	{
		sign = true;
		cout << "Absent" << endl;
	}
	else
	{
		cout << m_grade.name << " " << m_grade.id << endl;
	}

	if(sign)
	{
		cout << "NA" << endl;
	}
	else
	{
		cout << f_grade.grader - m_grade.grader << endl;
	}


	system("pause");
	return 0;
}
