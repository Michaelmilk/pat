#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	string in;
	cin >> in;
	int len = in.length() + 2;
	int part_len = len / 3;
	int remain = len % 3;

	int side = part_len;
	int mid = part_len + remain;
	int interval = mid - 2;

	int i  = 0, j = len - 3;
	for(; i < part_len - 1; i++, j--)
	{
		cout << in[i];
		for(int k = 0; k < interval; k++)
		{
			cout << " ";
		}
		cout << in[j] << endl;
	}

	for(int k = i; k <= j; k++)
	{
		cout << in[k];
	}


	system("pause");
	return 0;
}