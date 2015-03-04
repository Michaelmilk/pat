#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int now = 0;
	int next;
	int total = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> next;
		if(next > now)
		{
			total += (next - now) * 6 + 5;
		}
		else
		{
			total += (now - next) * 4 + 5;
		}
		now = next;
	}

	cout << total << endl;

	system("pause");
	return 0;
}