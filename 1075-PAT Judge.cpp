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

ifstream in("in.in");
#define cin in

struct User
{
	string id;
	int score[6];
	int solved_num;//通过编译的的题目数，决定是否显示
	int perfect_slove_num;
	int rank;
	int total;
	User() : total(0), solved_num(0), perfect_slove_num(0), rank(1)
	{
		//memset(score, 0, 6 * sizeof(int));
		for(int i = 0; i < 6; i++)
		{
			score[i] = -2;
		}
	}

	bool operator<(const User &u) const
	{
		if(total != u.total)
		{
			return total > u.total;
		}
		else if(perfect_slove_num != u.perfect_slove_num)
		{
			return perfect_slove_num > u.perfect_slove_num;
		}
		else
		{
			return id < u.id;
		}
	}
};



int main()
{
	int user_num, problem_num, sub_num;
	cin >> user_num >> problem_num >> sub_num;

	vector<int> problem_score(problem_num + 1);
	for(int i = 1; i <= problem_num; i++)
	{
		cin >> problem_score[i];
	}

	vector<User> users(user_num + 1);
	for(int i = 0; i < sub_num; i++)
	{
		int id, problem_id, score;
		string str_id;
		cin >> str_id >> problem_id >> score;
		stringstream ss;
		ss << str_id;
		ss >> id;
		users[id].id = str_id;
		users[id].solved_num += (users[id].score[problem_id] <= -1 && score != -1) ? 1 : 0;//现在有大于-1的分数，并且之前没有大于-1的分数
		//case：某个user可能已经AC了，但是再次提交时，不能增加perfect_slove_num值
		if(users[id].score[problem_id] < score)
		{
			users[id].score[problem_id]= score;
			if(users[id].score[problem_id] == problem_score[problem_id])
			{
				users[id].perfect_slove_num++;
			}
		}
	}

	vector<User> ans;
	for(int i = 1; i <= user_num; i++)
	{
		if(users[i].solved_num > 0)
		{
			for(int j = 1; j <= problem_num; j++)
			{
				if(users[i].solved_num > 0)//如果用户解决的题数不为0，且有题目编译没过，这时编译没过的题目分数应为0，而不是-1
				{
					users[i].total += (users[i].score[j] == -1 || users[i].score[j] == -2) ? 0 : users[i].score[j];
				} 
			}
			//cout << i << " " << users[i].total << endl;
			ans.push_back(users[i]);
		}
	}

	sort(ans.begin(), ans.end());
	int size = ans.size();
	for(int i = 1; i < size; i++)
	{
		ans[i].rank = ans[i].total == ans[i - 1].total ? ans[i - 1].rank : i + 1;
	}

	for(int i = 0; i < size; i++)
	{
		cout << ans[i].rank << " " << ans[i].id << " " << ans[i].total;
		for(int j = 1; j <= problem_num; j++)
		{
			if(ans[i].score[j] == -1)
			{
				cout << " 0";
			}
			else if(ans[i].score[j] == -2)
			{
				cout << " -";
			}
			else
			{
				cout << " " << ans[i].score[j];
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}