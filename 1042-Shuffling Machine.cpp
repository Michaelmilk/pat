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

string card[] = {"S", "H", "C", "D", "J"};

void ShuffleCard(vector<int> &ori_card, vector<int> &shuffle_order)
{
	vector<int>  tmp(54, 0);
	for(int i = 0; i < 54; i++)
	{
		tmp[shuffle_order[i]] = ori_card[i];
	}
	ori_card = tmp;
}

void PrintCard(vector<int> &ori_card)
{
	for(int i = 0; i < 53; i++)
	{
		cout << card[ori_card[i] / 13] << ori_card[i] % 13 + 1 << " ";
	}
	cout << card[ori_card[53] / 13] << ori_card[53] % 13 + 1;
}

int main()
{
	ifstream in("in.in");

	vector<int> ori_card(54, 0);
	for(int i = 0; i < 54; i++)
	{
		ori_card[i] = i;
	}

	vector<int> shuffle_order(54, 0);
	int repeat_times;
	in >> repeat_times;

	for(int i = 0; i < 54; i++)
	{
		int id;
		in >> id;
		shuffle_order[i] = id - 1;
	}

	for(int i = 0; i < repeat_times; i++)
	{
		ShuffleCard(ori_card, shuffle_order);
	}

	PrintCard(ori_card);

	system("pause");
	return 0;
}