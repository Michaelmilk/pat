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
#include <cstdio>
#include <cstdlib>
#include <functional>

using namespace std;
 

//AC
// struct InventoryProduct
// {
//  double price;
//  double aver_price;
//  double inventory;
//  bool operator<(const InventoryProduct &p) const
//  {
//   return aver_price > p.aver_price;
//  }
// };
 
// int main()
// {
//  //ifstream in("in.in");
 
//  int kinds;
//   int demand;
//  cin >> kinds >> demand;
 
//  vector<InventoryProduct> price(kinds);
//  for(int i = 0; i < kinds; i++)
//  {
//   cin >> price[i].inventory;
//  }
 
//  for(int i = 0; i < kinds; i++)
//  {
//   cin >> price[i].price;
//   price[i].aver_price = price[i].price / price[i].inventory;
//  }
 
//  sort(price.begin(), price.end());
 
//  double profile = 0;
//  for(int i = 0; i < kinds; i++)
//  {
//    if(price[i].inventory > demand)
//    {
//     profile += (double)demand * price[i].aver_price;
//     break;
//    }
//    profile += price[i].price;
//    demand -= price[i].inventory;
//  }
  
//  cout << setiosflags(ios::fixed);
//  cout << setprecision(2) << profile << endl;
//  cout << setprecision(6);
 
//  system("pause");
//  return 0;
// }


struct InventoryProduct
{
	double price;
	double aver_price;
	double inventory;
	bool operator<(const InventoryProduct &p) const
	{
		return aver_price > p.aver_price;
	}
};

int main()
{
	ifstream in("in.in");

	int kinds;
	double demand;
	in >> kinds >> demand;

	vector<InventoryProduct> price(kinds);
	for(int i = 0; i < kinds; i++)
	{
		in >> price[i].inventory;
	}
	
	for(int i = 0; i < kinds; i++)
	{
		in >> price[i].price;
		price[i].aver_price = price[i].inventory == 0 ? 0 : price[i].price / price[i].inventory;
	}

	sort(price.begin(), price.end());

	double profile = 0;
	for(int i = 0; i < kinds && demand != 0; i++)
	{
		// if(price[i].inventory > demand)
		// {
		// 	profile += (double)demand * price[i].aver_price;
		// 	break;
		// }
		// profile += price[i].inventory == 0 ? 0 : price[i].price;
		// demand -= price[i].inventory == 0 ? 0 : price[i].inventory;
		if(price[i].inventory > demand)
		{
			profile += demand * price[i].aver_price;
			demand = 0;
		}
		else
		{
			profile += price[i].inventory == 0 ? 0 : price[i].price;
			demand -= price[i].inventory == 0 ? 0 : price[i].inventory;
		}
		
	}
		
	cout << setiosflags(ios::fixed);
	cout << setprecision(2) << profile << endl;
	cout << setprecision(6);

	system("pause");
	return 0;
}