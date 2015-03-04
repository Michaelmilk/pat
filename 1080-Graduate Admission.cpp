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

struct Applicant
{
	int ge;
	int gi;
	int final;
	int chioce[8];
	int rank;
	bool be_exceed;
	int id;//
	bool operator<(const Applicant &a) const
	{
		if(final != a.final)
		{
			return final > a.final;
		}
		else if(ge != a.ge)
		{
			return ge > a.ge;
		}
		else
		{
			return false;
		}
	}
};

void RankApplicants(int size, vector<Applicant> &applicants)
{
	int rank = 1;
	int count = 2;
	for(int i = 1; i < size; i++)
	{
		if (applicants[i].final == applicants[i - 1].final && applicants[i].ge == applicants[i - 1].ge)
		{
			applicants[i].rank = rank;
			count++;
		}
		else
		{
			rank = count;
			applicants[i].rank = rank;
			count++;
		}
	}
}

void PrintAdmissionLists(int size, int school_num, int choice_num, vector<int> &quota, vector<Applicant> &applicants)
{

	vector<vector<int> > ans(school_num, vector<int>());
	vector<int> last_rank(school_num);//表示学校i当前最后一名学生的排名
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < choice_num; j++)
		{
			int school_id = applicants[i].chioce[j];
			//if(quota[school_id] > 0)//ok
			if (quota[school_id] > ans[school_id].size())
			{
				ans[school_id].push_back(applicants[i].id);
				//记录学校当前的最后一位学生的排名(当前学生的排名，不是applicants[i].id）
				//因为ans[school_id]中存放的是applicants[i].id，即元素原始的id，
				//然而下面对比排名是否相同的时候，需要的是当前的排名applicants[i].rank，
				//而不是applicants[applicants[i].id].rank！！！
				last_rank[school_id] = applicants[i].rank;
				//applicants[i].be_exceed = true;
				//quota[school_id]--;
				break;//
			}
			else if (ans[school_id].size() > 0)
			{
				//int idx = ans[school_id].back();
				if (last_rank[school_id] == applicants[i].rank)
				{
					ans[school_id].push_back(applicants[i].id);
					break;//
				}
			}
		}
	}

	for(int i = 0; i < school_num; i++)
	{
		int s = ans[i].size();
		if(0 == s)
		{
			cout << endl;
		}
		else
		{
			sort(ans[i].begin(), ans[i].end());
			for (int j = 0; j < s; j++)
			{
				cout << ans[i][j] << (j == s - 1 ? "\n" : " ");
			}
		}
	}
}

int main()
{
	ifstream in("in.in");

	int applicant_num, school_num, choice_num;
	in >> applicant_num >> school_num >> choice_num;

	if (0 == school_num)
	{
		return 0;
	}

	vector<int> quota(school_num);
	for(int i = 0; i < school_num; i++)
	{
		in >> quota[i];
	}

	vector<Applicant> applicants(applicant_num);
	for(int i = 0; i < applicant_num; i++)
	{
		in >> applicants[i].ge >> applicants[i].gi;
		applicants[i].final = (applicants[i].ge + applicants[i].gi) / 2;
		applicants[i].be_exceed = false;
		applicants[i].rank = 1;
		applicants[i].id = i;
		for(int j = 0; j < choice_num; j++)
		{
			in >> applicants[i].chioce[j];
		}
	}

	sort(applicants.begin(), applicants.end());

	RankApplicants(applicant_num, applicants);

	PrintAdmissionLists(applicant_num, school_num, choice_num, quota, applicants);

	system("pause");
	return 0;
}