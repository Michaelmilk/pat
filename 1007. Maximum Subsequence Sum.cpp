#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
	ifstream in("in.in");

	int n;
	in >> n;
	/*vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int elem;
		in >> elem;
		vec.push_back(elem);
	}*/

	vector<int> vec(n, 0);
	for (int i = 0; i < n; i++)
	{
		in >> vec[i];
	}

	int sum = 0;
	int start = 0;
	int end = -1;
	int maxval = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum < 0 ? vec[i] : sum + vec[i];

		if (sum > maxval ||(sum == 0 && end == -1))//!!!!!!!! 0 0 -1
		{
			maxval = sum;
			end = i;
		}
		//else if(sum == maxval)
		//{
		//	end = (end == -1) ? i : end;
		//}
	}

	int count = 0;
	bool flag = false;
	for (int i = end; i >= 0; i--)
	{
		count += vec[i];
		if (!flag && count == maxval)
		{
			flag = true;
		}

		if (flag && count != maxval)
		{
			break;
		}
		if (flag && count == maxval)
		{
			start = i;
		}
	}

	if (end == -1)
	{
		cout << 0 << " " << vec[0] << " " << vec[n - 1] << endl;
	}
	else
	{
		cout << maxval << " " << vec[start] << " " << vec[end] << endl;
	}

	system("pause");
	return 0;
}