#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

string mp[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main()
{
	char ch[1000];

	cin >> ch;

	int size = strlen(ch);

	int sum = 0;
	for(int i = 0; i < size; i++)
	{
		sum += ch[i] - '0';
	}

	vector<string> ans;
	do
	{
		int c = sum % 10;
		sum = sum / 10;
		ans.push_back(mp[c]);
	}while(sum > 0);

	size = ans.size();
	int i = 0;
	for(i = size - 1; i >= 0; i--)
	{
		cout << ans[i];
		if(0 != i)
		{
			cout << " ";
		}
	}

	
	//system("pause");
	return 0;
}