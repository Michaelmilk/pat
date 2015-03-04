// #include<cstdio>
// #include<iostream>
// #include<cstring>
// #include<cmath>
// #include<string>
// #include<vector>
// #include<algorithm>
// using namespace std;
// #define MAX 100005
// struct stu
// {
//     string id;
//     int d;
//     int c;
//     int summ;
// };
//  stu stu[4][MAX];
// bool cmp(const struct stu &a,const struct stu &b)
// {
//     if(a.summ>b.summ) return true;
//     else if(a.summ==b.summ)
//     {
//         if(a.d>b.d) return true;
//         else if(a.d==b.d) return a.id<b.id;
//         else return false;
//     }
//     else return false;
// }
// int main()
// {
//     int n,l,h;
//     int len[4];
//     memset(len,0,sizeof(len));
//     string id;
//     char ch[10];
//     int d,c;
//     scanf("%d%d%d",&n,&l,&h);
  
 
//     for(int i=0;i<n;++i)
//     {
//         scanf("%s%d%d",ch,&d,&c);
//         id=string(ch);
//         if(d<l||c<l) continue;
//       struct stu person;
//       person.id = id;
//       person.d = d;
//       person.c = c;
//       person.summ = d + c;
//         if(d>=h&&c>=h)
//         {
//             stu[0][len[0]]= person;
           
//             ++len[0];
//         }
//         else if(d>=h)
//         {
//             stu[1][len[1]]= person;
         
//             ++len[1];
//         }
//         else if(d<h&&d>=c)
//         {
//             stu[2][len[2]]= person;
            
//             ++len[2];
//         }
//         else
//         {
//             stu[3][len[3]]= person;
  
//             ++len[3];
//         }
//     }
//     for(int i=0;i<4;++i)
//         sort(stu[i],stu[i]+len[i],cmp);
//     printf("%d\n",len[0]+len[1]+len[2]+len[3]);
//     for(int i=0;i<4;++i)
//         for(int j=0;j<len[i];++j)
//             printf("%s %d %d\n",stu[i][j].id.c_str(),stu[i][j].d,stu[i][j].c);
//     return 0;
// }

//ok
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 100005
struct node
{
	char id[10];
	int v,t,c;
}s[N];
int cmp(const void *a,const void *b)
{
	struct node *x=(struct node *)a;
	struct node *y=(struct node *)b;
	if(x->c!=y->c)return x->c-y->c;
	if(y->v+y->t!=(x->v+x->t))return y->v+y->t-(x->v+x->t);
	if(y->v!=x->v)return y->v-x->v;
	return strcmp(x->id,y->id);
}
int main()
{
	int n,i,l,h;
	while(scanf("%d%d%d",&n,&l,&h)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s%d%d",s[i].id,&s[i].v,&s[i].t);
			if(s[i].v>=h&&s[i].t>=h)s[i].c=1;
			else
				if(s[i].v>=h&&s[i].t>=l&&s[i].t<h)s[i].c=2;
				else
					if(s[i].v>=l&&s[i].v<h&&s[i].t>=l&&s[i].t<h&&s[i].v>=s[i].t)s[i].c=3;
					else
						if(s[i].v>=l&&s[i].t>=l)s[i].c=4;
						else
							s[i].c=0;
		}
		qsort(s,n,sizeof(struct node),cmp);
		for(i=0;i<n;i++)
			if(s[i].c!=0)break;
			printf("%d\n",n-i);
		for(;i<n;i++)
			printf("%s %d %d\n",s[i].id,s[i].v,s[i].t);

	}
}

//ok
// #include<cstdio>
// #include<iostream>
// #include<cstring>
// #include<cmath>
// #include<string>
// #include<vector>
// #include<algorithm>
// using namespace std;
// #define MAX 100005
// struct stu
// {
//     string id;
//     int d;
//     int c;
//     int summ;
// }stu[4][MAX];
// bool cmp(const struct stu &a,const struct stu &b)
// {
//     if(a.summ>b.summ) return true;
//     else if(a.summ==b.summ)
//     {
//         if(a.d>b.d) return true;
//         else if(a.d==b.d) return a.id<b.id;
//         else return false;
//     }
//     else return false;
// }
// int main()
// {
//     int n,l,h;
//     int len[4];
//     memset(len,0,sizeof(len));
//     string id;
//     char ch[10];
//     int d,c;
//     scanf("%d%d%d",&n,&l,&h);
//     for(int i=0;i<n;++i)
//     {
//         scanf("%s%d%d",ch,&d,&c);
//         id=string(ch);
//         if(d<l||c<l) continue;
//         if(d>=h&&c>=h)
//         {
//             stu[0][len[0]].id=id;
//             stu[0][len[0]].d=d;
//             stu[0][len[0]].c=c;
//             stu[0][len[0]].summ=d+c;
//             ++len[0];
//         }
//         else if(d>=h)
//         {
//             stu[1][len[1]].id=id;
//             stu[1][len[1]].d=d;
//             stu[1][len[1]].c=c;
//             stu[1][len[1]].summ=d+c;
//             ++len[1];
//         }
//         else if(d<h&&d>=c)
//         {
//             stu[2][len[2]].id=id;
//             stu[2][len[2]].d=d;
//             stu[2][len[2]].c=c;
//             stu[2][len[2]].summ=d+c;
//             ++len[2];
//         }
//         else
//         {
//             stu[3][len[3]].id=id;
//             stu[3][len[3]].d=d;
//             stu[3][len[3]].c=c;
//             stu[3][len[3]].summ=d+c;
//             ++len[3];
//         }
//     }
//     for(int i=0;i<4;++i)
//         sort(stu[i],stu[i]+len[i],cmp);
//     printf("%d\n",len[0]+len[1]+len[2]+len[3]);
//     for(int i=0;i<4;++i)
//         for(int j=0;j<len[i];++j)
//             printf("%s %d %d\n",stu[i][j].id.c_str(),stu[i][j].d,stu[i][j].c);
//     return 0;
// }


//TLE
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

// const int k_max = 100005;

// struct Person
// {
// 	string id;
// 	int virtue;
// 	int talent;
// 	int total;
// 	// bool operator<(const Person &p) const
// 	// {
// 	// 	if(total > p.total)
// 	// 	{
// 	// 		return true;
// 	// 	}
// 	// 	else if(total == p.total)
// 	// 	{
// 	// 		if(virtue > p.virtue)
// 	// 		{
// 	// 			return true;
// 	// 		}
// 	// 		else if(virtue == p.virtue)
// 	// 		{
// 	// 			return id < p.id;
// 	// 		}
// 	// 		else
// 	// 		{
// 	// 			return false;
// 	// 		}
// 	// 	}
// 	// 	else
// 	// 	{
// 	// 		return false;
// 	// 	}
// 	// }
// };

// Person sage[k_max];
// Person nobleman[k_max];
// Person foolman[k_max];
// Person smallman[k_max];

// bool cmp(const Person &a,const Person &b)  
// {  
//     if(a.total > b.total) return true;  
//     else if(a.total == b.total)  
//     {  
//         if(a.virtue > b.virtue) return true;  
//         else if(a.virtue == b.virtue) return a.id < b.id;  
// 	    else return false;  
//     }  
//    else return false;  
// }  


// void PrintPerson(int size, Person p[])
// {
// 	for(int i = 0; i < size; i++)
// 	{
// 		cout << p[i].id << " " << p[i].virtue << " " << p[i].talent << endl;
// 	}
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int num, high, low;
// 	in >> num >> low >> high;
	
// 	int len[4];
// 	memset(len, 0, 4 * sizeof(int));
// 	int count = 0;

// 	for(int i = 0; i < num; i++)
// 	{
// 		Person person;
// 		in >> person.id >> person.virtue >> person.talent;
// 		person.total = person.virtue + person.talent;
// 		if(person.virtue >= low && person.talent >= low)
// 		{
// 			if(person.virtue >= high && person.talent >= high)
// 			{
// 				sage[len[0]] = person;
// 				len[0]++;
// 			}
// 			else if(person.virtue >= high && person.talent < high)
// 			{
// 				nobleman[len[1]] = person;
// 				len[1]++;
// 			}
// 			else if(person.virtue < high && person.talent < high && person.virtue >= person.talent)
// 			{
// 				foolman[len[2]] = person;
// 				len[2]++;
// 			}
// 			else
// 			{
// 				smallman[len[3]] = person;
// 				len[3]++;
// 			}
			
// 			count++;
// 		}
// 	}

// 	sort(sage, sage + len[0], cmp);
// 	sort(nobleman, nobleman + len[1], cmp);
// 	sort(foolman, foolman + len[2], cmp);
// 	sort(smallman, smallman + len[3], cmp);

// 	cout << count << endl;
// 	PrintPerson(len[0], sage);
// 	PrintPerson(len[1], nobleman);
// 	PrintPerson(len[2], foolman);
// 	PrintPerson(len[3], smallman);

// 	system("pause");
// 	return 0;
// }


//TLE
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

// struct Person
// {
// 	string id;
// 	int virtue;
// 	int talent;
// 	bool operator<(const Person &p) const
// 	{
// 		if(virtue + talent != p.virtue + p.talent)
// 		{
// 			return (virtue + talent < p.virtue + p.talent);
// 		}
// 		else if(virtue != p.virtue)
// 		{
// 			return virtue < p.virtue;
// 		}
// 		else
// 		{
// 			return id > p.id;
// 		}
// 	}
// };

// void PrintPerson(priority_queue<Person> &que)
// {
// 	while(!que.empty())
// 	{
// 		Person p = que.top();
// 		que.pop();
// 		cout << p.id << " " << p.virtue << " " << p.talent << endl;
// 	}
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int num, high, low;
// 	in >> num >> low >> high;
// 	priority_queue<Person> sage;
// 	priority_queue<Person> nobleman;
// 	priority_queue<Person> foolman;
// 	priority_queue<Person> smallman;
// 	int count = 0;

// 	for(int i = 0; i < num; i++)
// 	{
// 		Person person;
// 		in >> person.id >> person.virtue >> person.talent;
// 		if(person.virtue >= low && person.talent >= low)
// 		{
// 			if(person.virtue >= high && person.talent >= high)
// 			{
// 				sage.push(person);
// 			}
// 			else if(person.virtue >= high && person.talent < high)
// 			{
// 				nobleman.push(person);
// 			}
// 			else if(person.virtue < high && person.talent < high && person.virtue >= person.talent)
// 			{
// 				foolman.push(person);
// 			}
// 			else
// 			{
// 				smallman.push(person);
// 			}
			
// 			count++;
// 		}
// 	}

// 	cout << count << endl;
// 	PrintPerson(sage);
// 	PrintPerson(nobleman);
// 	PrintPerson(foolman);
// 	PrintPerson(smallman);

// 	system("pause");
// 	return 0;
// }


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

// struct Person
// {
// 	string id;
// 	int virtue;
// 	int talent;
// 	bool operator<(const Person &p) const
// 	{
// 		if(virtue + talent > p.virtue + p.talent)
// 		{
// 			return true;
// 		}
// 		else if(virtue + talent == p.virtue + p.talent)
// 		{
// 			if(virtue > p.virtue)
// 			{
// 				return true;
// 			}
// 			else if(virtue == p.virtue)
// 			{
// 				return id < p.id;
// 			}
// 			else
// 			{
// 				return false;
// 			}
// 		}
// 		else
// 		{
// 			return false;
// 		}
// 	}
// };

// void PrintPerson(vector<Person> &p)
// {
// 	int size = p.size();
// 	for(int i = 0; i < size; i++)
// 	{
// 		cout << p[i].id << " " << p[i].virtue << " " << p[i].talent << endl;
// 	}
// }

// int main()
// {
// 	ifstream in("in.in");

// 	int num, high, low;
// 	in >> num >> low >> high;
// 	vector<Person> sage;
// 	vector<Person> nobleman;
// 	vector<Person> foolman;
// 	vector<Person> smallman;
// 	int count = 0;

// 	for(int i = 0; i < num; i++)
// 	{
// 		Person person;
// 		in >> person.id >> person.virtue >> person.talent;
// 		if(person.virtue >= low && person.talent >= low)
// 		{
// 			if(person.virtue >= high && person.talent >= high)
// 			{
// 				sage.push_back(person);
// 			}
// 			else if(person.virtue >= high && person.talent < high)
// 			{
// 				nobleman.push_back(person);
// 			}
// 			else if(person.virtue < high && person.talent < high && person.virtue >= person.talent)
// 			{
// 				foolman.push_back(person);
// 			}
// 			else
// 			{
// 				smallman.push_back(person);
// 			}
			
// 			count++;
// 		}
// 	}

// 	sort(sage.begin(), sage.end());
// 	sort(nobleman.begin(), nobleman.end());
// 	sort(foolman.begin(), foolman.end());
// 	sort(smallman.begin(), smallman.end());

// 	cout << count << endl;
// 	PrintPerson(sage);
// 	PrintPerson(nobleman);
// 	PrintPerson(foolman);
// 	PrintPerson(smallman);

// 	system("pause");
// 	return 0;
// }