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
	vector<int> vec;
	for (int i = 0; i < n; i++)
	{
		int elem;
		in >> elem;
		vec.push_back(elem);
	}

	int sum = 0;
	int start = 0;
	int end = -1;
	int maxval = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum < 0 ? vec[i] : sum + vec[i];
	
		if (sum > maxval)
		{
			maxval = sum;
			end = i;
		}
		else if(sum == maxval)
		{
			end = (end == -1) ? i : end;
		}
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
		if(flag && count == maxval)
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
/*
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream in("in.in");

    int k;
    int *data;
    int i;

    int start, end, sum, temp, tempi, tempj;

    //while(scanf("%d", &k) != EOF)
    while(in >> k)
    {
        data = (int *)malloc(k * sizeof(int));
        for(i = 0; i < k; i ++)
        {
            //scanf("%d", &data[i]);
            in >> data[i];
        }
        sum = 0;
        start = 0;
        end = k - 1;
        temp = 0;
        tempi = 0;
        tempj = 0;
        for(i = 0; i < k; i ++)
        {
            if(temp >= 0)
            {
                temp += data[i];
                tempj = i;
            }
            else
            {
                temp = data[i];
                tempi = i;
                tempj = i;
            }
            if(temp > sum || (temp == 0 && end == k - 1))//temp确实比sum大, 或者, sum依然是初始状态(end == k-1即表示)而且temp==0, 需要替换
            {
                sum = temp;
                start = tempi;
                end = tempj;
            }
        }
        printf("%d %d %d\n", sum, data[start], data[end]);
    }

    system("pause");
    return 0;
}*/