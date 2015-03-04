#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <climits>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>

using namespace std;

struct Student
{
	string id;
	int c;
	int m;
	int e;
	int ave;
	int rank;
	char bestcourse;
	Student(){}
};

struct Cmp_c{
	bool operator ()(Student *a, Student *b){
		return a->c < b->c;//最大值优先  
	}
};

struct Cmp_m{
	bool operator ()(Student *a, Student *b){
		return a->m < b->m;//最大值优先  
	}
};

struct Cmp_e{
	bool operator ()(Student *a, Student *b){
		return a->e < b->e;//最大值优先  
	}
};

struct Cmp_ave{
	bool operator ()(Student *a, Student *b){
		return a->ave < b->ave;//最大值优先  
	}
};

Student stu[2005];
string checkname[2005];

int main()
{
	ifstream in("in.in");
	
	int stu_num, check_num;
	in >> stu_num >> check_num;

	//Student *pStu = new Student[stu_num];
	priority_queue <Student*, vector<Student*>, Cmp_c> c_que;
	priority_queue <Student*, vector<Student*>, Cmp_m> m_que;
	priority_queue <Student*, vector<Student*>, Cmp_e> e_que;
	priority_queue <Student*, vector<Student*>, Cmp_ave> ave_que;
	
	for (int i = 0; i < stu_num; i++)
	{
		in >> stu[i].id >> stu[i].c >> stu[i].m >> stu[i].e;
		stu[i].ave = (stu[i].c + stu[i].m + stu[i].e) / 3;
		c_que.push(&stu[i]);
		m_que.push(&stu[i]);
		e_que.push(&stu[i]);
		ave_que.push(&stu[i]);
	}

	for (int i = 0; i < check_num; i++)
	{
		in >> checkname[i];
	}

	int r = 1, num = 1;
	while (!e_que.empty())
	{
		Student *tmp = e_que.top();
		e_que.pop();
		tmp->rank = r;
		tmp->bestcourse = 'E';
		if (!e_que.empty())
		{
			num++;
			r = (e_que.top())->e == tmp->e ? r : num;
		}
	}
	r = 1;
	num = 1;
	while (!m_que.empty())
	{
		Student *tmp = m_que.top();
		m_que.pop();
		//tmp->rank = tmp->rank < r ? tmp->rank : r;
		if (tmp->rank >= r)
		{
			tmp->rank = r;
			tmp->bestcourse = 'M';
		}
		if (!m_que.empty())
		{
			num++;
			r = (m_que.top())->m == tmp->m ? r : num;
		}
		
	}
	r = 1;
	num = 1;
	while (!c_que.empty())
	{
		Student *tmp = c_que.top();
		c_que.pop();
		//tmp->rank = tmp->rank < r ? tmp->rank : r;
		if (tmp->rank >= r)
		{
			tmp->rank = r;
			tmp->bestcourse = 'C';
		}
		if (!c_que.empty())
		{
			num++;
			r = (c_que.top())->c == tmp->c ? r : num;
		}
	}
	r = 1;
	num = 1;
	while (!ave_que.empty())
	{
		Student *tmp = ave_que.top();
		ave_que.pop();
		//tmp->rank = tmp->rank < r ? tmp->rank : r;
		if (tmp->rank >= r)
		{
			tmp->rank = r;
			tmp->bestcourse = 'A';
		}
		if (!ave_que.empty())
		{
			num++;
			r = (ave_que.top())->ave == tmp->ave ? r : num;
		}
	}

	int i, j;
	for (i = 0; i < check_num; i++)
	{
		for (j = 0; j < stu_num; j++)
		{
			if (checkname[i] == stu[j].id)
			{
				cout << stu[j].rank << " " << stu[j].bestcourse << endl;
				break;
			}
		}
		if (j == stu_num)
		{
			cout << "N/A" << endl;
		}
	}
	return 0;
}
