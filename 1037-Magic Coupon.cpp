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


int main()
{
	ifstream in("in.in");

	int coupon_num, product_num;
	in >> coupon_num;

	vector<int> coupon(coupon_num);
	for(int i = 0; i < coupon_num; i++)
	{
		in >> coupon[i];
	}

	in >> product_num;
	vector<int> product(product_num);
	for(int i = 0; i < product_num; i++)
	{
		in >> product[i];
	}

	sort(coupon.begin(), coupon.end());
	sort(product.begin(), product.end());

	int idx1 = 0;
	int idx2 = 0;
	int sum = 0;
	while(idx1 < coupon_num && idx2 < product_num &&
		coupon[idx1] < 0 && product[idx2] < 0)
	{
		sum += coupon[idx1] * product[idx2];
		idx1++;
		idx2++;
	}

	idx1 = coupon_num - 1;
	idx2 = product_num - 1;
	while(idx1 >=0 && idx2 >= 0 &&
		coupon[idx1] > 0 && product[idx2] > 0)
	{
		sum += coupon[idx1] * product[idx2];
		idx1--;
		idx2--;
	}

	cout << sum << endl;

	system("pause");
	return 0;
}