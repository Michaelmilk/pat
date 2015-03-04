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

using namespace std;

struct User
{
	string name;
	string passwd;
};

int main()
{
	ifstream in("in.in");

	map<char, char> mp;
	mp['1'] = '@';
	mp['0'] = '%';
	mp['l'] = 'L';
	mp['O'] = 'o';

	int user_num;
	in >> user_num;

	vector<User> modi_users;
	for(int i = 0; i < user_num; i++)
	{
		bool sign = false;
		User user;
		in >> user.name >> user.passwd;

		int len = user.passwd.length();
		for(int j = 0; j < len; j++)
		{
			if(mp.find(user.passwd[j]) != mp.end())
			{
				sign = true;
				user.passwd[j] = mp[user.passwd[j]];
			}
		}
		if(sign)
		{
			modi_users.push_back(user);
		}
	}

	if(modi_users.empty())
	{
		cout << "There " << (user_num == 1 ? "is " : "are ")
		<< user_num << (user_num == 1 ? " account " : " accounts ")
		<< "and no account is modified" << endl;
	}
	else
	{
		int size = modi_users.size();
		cout << size << endl;
		for(int i = 0; i < size; i++)
		{
			cout << modi_users[i].name << " " << modi_users[i].passwd << endl;
		}
	}

	system("pause");
	return 0;
}