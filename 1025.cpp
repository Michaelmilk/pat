#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

struct Testee
{
	string reg_id;
	int score;
	int final_rank;
	int local_id;
	int local_rank;
	bool operator<(const Testee &tst) const
	{
		if(score == tst.score)
		{
			return reg_id < tst.reg_id;
		}
		return score > tst.score;
	}
};

void LocalRank(int localtions, vector<Testee> num[])
{
	for(int i = 0; i < localtions; i++)
	{
		sort(num[i].begin(), num[i].end());
	}

	for(int i = 0; i < localtions; i++)
	{
		int size = num[i].size();
		int rank = 1;
		int count = 1;
		num[i][0].local_rank = rank;
		for(int j = 1; j < size; j++)
		{
			count++;
			rank = num[i][j].score < num[i][j - 1].score ? count : rank;
			num[i][j].local_rank = rank;
		}
	}

}

void  FinalRank(int localtions, vector<Testee> num[], vector<Testee> &result_list)
{
	for(int i = 0; i < localtions; i++)
	{
		result_list.insert(result_list.end(), num[i].begin(), num[i].end());
	}

	sort(result_list.begin(), result_list.end());

	int size = result_list.size();
	int rank = 1;
	int count = 1;
	result_list[0].final_rank = rank;
	for(int i = 1; i < size; i++)
	{
		count++;
		rank = result_list[i].score < result_list[i - 1].score ? count : rank;
		result_list[i].final_rank = rank;
	}
}

void PrintList(vector<Testee> result_list)
{
	int size = result_list.size();
	for(int i = 0; i < size; i++)
	{
		cout << result_list[i].reg_id << " " << result_list[i].final_rank << 
		" " << result_list[i].local_id  << " " << result_list[i].local_rank << endl;
	}
}

int main()
{
	ifstream in("in.in");

	int localtions;
	in >> localtions;

	int testee_num;
	int total_testee_num = 0;
	vector<Testee> num[localtions];
	for(int i = 1; i <= localtions; i++)
	{
		in >> testee_num;
		total_testee_num += testee_num;
		for(int j = 0; j < testee_num; j++)
		{
			Testee tst;
			tst.local_id = i;
			in >> tst.reg_id >> tst.score;
			num[i - 1].push_back(tst);
		}
	}

	LocalRank(localtions, num);

	vector<Testee> result_list;
	FinalRank(localtions, num, result_list);

	cout << total_testee_num << endl;
	PrintList(result_list);

	system("pause");
	return 0;
}