// #include <iostream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>
// using namespace std;

// int c;
// //!!!!!!!!!!!!!!!!!!!!!超时的最大原因是因为  cin   和   cout   ！！！！！！！！！！！！！！！！！
// struct Student
// {
// 	char id[10];
// 	char name[10];
// 	int grade;
// }students[100005];

// int cmp(const void *a, const void *b)
// {
// 	Student *x = (Student*)a;
// 	Student *y = (Student*)b;
// 	if(c == 2 && strcmp(x->name, y->name) != 0)
//  	{
//  		return strcmp(x->name, y->name);
//  	}
//  	else if(c == 3 && x->grade != y->grade)
//  	{
//  		return x->grade - y->grade;
//  	}
//  	else
//  	{
//  		return strcmp(x->id, y->id);
//  	}
// }

// int cmp(const void *atmp,const void *btmp){//参数必须先写出const void *
// 	Student *a=(Student *)atmp;
// 	Student *b=(Student *)btmp;
// 	if(c==1){
// 		return strcmp(a->id,b->id);
// 	}
// 	else if(c==2){
// 		if(strcmp(a->name,b->name)==0) return strcmp(a->id,b->id);
// 		else return strcmp(a->name,b->name);
// 	}
// 	else if(c==3){
// 		if(a->grade==b->grade) return strcmp(a->id,b->id);
// 		else return a->grade-b->grade;
// 	}
// 	return 0;
// }


// int main()
// {
// 	int student_num;
// 	//cin >> student_num >> c;
//   scanf("%d %d", &student_num, &c);
  
// 	for(int i = 0; i < student_num; i++)
// 	{
// 		//cin >> students[i].id >> students[i].name >> students[i].grade;
//           scanf("%s %s %d",students[i].id,students[i].name,&students[i].grade);
// 	}

// 	qsort(students, student_num, sizeof(Student), cmp);

// 	for(int i = 0; i < student_num; i++)
// 	{
// 		//cout << students[i].id << " " << students[i].name << " " << students[i].grade << endl;
//           printf("%s %s %d\n",students[i].id,students[i].name,students[i].grade);  
// 	}
// 	return 0;
// }


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

int c;

struct Student
{
	//string id[10];
	//string name[10];
	char id[10];
	char name[10];
	int grade;
	bool operator<(const Student &s) const
	{
		if(c == 2 && strcmp(name, s.name) != 0)
	  	{
	  		return strcmp(name, s.name) < 0? true : false;
	  	}
	  	else if(c == 3 && grade != s.grade)
	  	{
	  		return grade < s.grade;
	  	}
	  	else
	  	{
	  		return strcmp(id, s.id)<0 ? true : false;
	  	}
	}
};//students[100005];


int main()
{
	//ifstream in("in.in");

	int student_num;
	scanf("%d %d", &student_num, &c);

	vector<Student> students(student_num);
	for(int i = 0; i < student_num; i++)
	{
		 scanf("%s %s %d",students[i].id,students[i].name,&students[i].grade);
	}

	sort(students.begin(), students.end());
	//sort(students, students + student_num, cmp);
	//qsort(students, student_num, sizeof(Student), cmp);

	for(int i = 0; i < student_num; i++)
	{
		printf("%s %s %d\n",students[i].id,students[i].name,students[i].grade); 
	}
	system("pause");
	return 0;
}


// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <climits>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <fstream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>


// using namespace std;

// int c;

// struct Student
// {
// 	// string id[10];
// 	// string name[10];
// 	char id[10];
// 	char name[10];
// 	int grade;
// 	// bool operator<(const Student &s) const
// 	// {
// 	// 	if(c == 2 && strcmp(name, s.name) != 0)
// 	// 	{
// 	// 		return strcmp(name, s.name) < 0;
// 	// 	}
// 	// 	else if(c == 3 && grade != s.grade)
// 	// 	{
// 	// 		return grade < s.grade;
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		return strcmp(id, s.id) < 0;
// 	// 	}
// 	// 	// if(c == 2 && name != s.name)
// 	// 	// {
// 	// 	// 	return name.compare(s.name) < 0 ? true : false;
// 	// 	// }
// 	// 	// else if(c == 3 && grade != s.grade)
// 	// 	// {
// 	// 	// 	return grade < s.grade;
// 	// 	// }
// 	// 	// else
// 	// 	// {
// 	// 	// 	return id.compare(s.id) < 0 ? true : false;
// 	// 	// }
// 	// 	// if(c == 2 && name != s.name)
// 	// 	// {
// 	// 	// 	return name < s.name;
// 	// 	// }
// 	// 	// else if(c == 3 && grade != s.grade)
// 	// 	// {
// 	// 	// 	return grade < s.grade;
// 	// 	// }
// 	// 	// else
// 	// 	// {
// 	// 	// 	return id < s.id;
// 	// 	// }
// 	// 	// if(c == 2)
// 	// 	// {
// 	// 	// 	if(name != s.name)
// 	// 	// 	{
// 	// 	// 		return name < s.name;
// 	// 	// 	}
// 	// 	// 	return id < s.id;
// 	// 	// }
// 	// 	// else if(c == 3)
// 	// 	// {
// 	// 	// 	if(grade != s.grade)
// 	// 	// 	{
// 	// 	// 		return grade < s.grade;
// 	// 	// 	}
// 	// 	// 	return id < s.id;
// 	// 	// }
// 	// 	// else if(c == 1)
// 	// 	// {
// 	// 	// 	return id < s.id;
// 	// 	// }
// 	// }
// }students[100005];

// // bool cmp(const Student &a, const Student &b)
// // {
// // 	if(c == 2 && strcmp(a.name, b.name) != 0)
// // 	{
// // 		return strcmp(a.name, b.name) < 0;
// // 	}
// // 	else if(c == 3 && a.grade != b.grade)
// // 	{
// // 		return a.grade < b.grade;
// // 	}
// // 	else
// // 	{
// // 		return strcmp(a.id, b.id) < 0;
// // 	}
// // }
// int cmp(const void *a, const void *b)
// {
// 	Student *x = (Student*)a;
// 	Student *y = (Student*)b;
// 	if(c == 2 && strcmp(x->name, y->name) != 0)
//  	{
//  		return strcmp(x->name, y->name);
//  	}
//  	else if(c == 3 && x->grade != y->grade)
//  	{
//  		return x->grade - y->grade;
//  	}
//  	else
//  	{
//  		return strcmp(x->id, y->id);
//  	}
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int student_num;
// 	in >> student_num >> c;

// 	//vector<Student> students(student_num);
// 	for(int i = 0; i < student_num; i++)
// 	{
// 		in >> students[i].id >> students[i].name >> students[i].grade;
// 	}

// 	//sort(students.begin(), students.end());
// 	//sort(students, students + student_num, cmp);
// 	qsort(students, student_num, sizeof(Student), cmp);

// 	for(int i = 0; i < student_num; i++)
// 	{
// 		cout << students[i].id << " " << students[i].name << " " << students[i].grade << endl;
// 	}
// 	system("pause");
// 	return 0;
// }