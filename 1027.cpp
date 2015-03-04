#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

char ch[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C'};


string ConvertColors(int color)
{
	string ans = "";

	ans += ch[color / 13];
	ans += ch[color % 13];

	return ans;
}

string GenerateColor(int red, int green, int blue)
{
	string ans = "#";
	
	ans += ConvertColors(red);
	ans += ConvertColors(green);
	ans += ConvertColors(blue);

	return ans;
}

int main()
{
	int red, green, blue;
	cin >> red >> green >> blue;

	string ans = GenerateColor(red, green, blue);
	cout << ans << endl;
	system("pause");
	return 0;
}