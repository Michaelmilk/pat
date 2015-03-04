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


using namespace std;

struct Book
{
	char id[8];
	char title[85];
	char author[85];
	char key_words[55];
	char publisher[85];
	char publisher_year[4];
};

map<string, vector<string> > title_map;
map<string, vector<string> > author_map;
map<string, vector<string> > key_words_map;
map<string, vector<string> > publisher_map;
map<string, vector<string> > publisher_year_map;

void PrintRes(vector<string> ans)
{
	int size = ans.size();
	if(0 == size)
	{
		//cout << "Not Found" << endl;
		printf("Not Found\n");
		return;
	}
	sort(ans.begin(), ans.end());
	for(int i = 0; i < size; i++)
	{
		//cout << ans[i];// << endl;

		printf("%s\n", ans[i].c_str());
	}
}

int main()
{
	//FILE *fin = fopen("in.in", "r");
	int book_num;
	scanf("%d", &book_num);
	//cout << book_num << endl;
	for(int i = 0; i < book_num; i++)
	{
		Book book;
		//scanf("%s\n", book.id);
		//cout << book.id << endl;
		getchar();
		gets(book.id);
		gets(book.title);
		gets(book.author);
		//cout << book.author << endl;
		//cout << book.id << endl;
		gets(book.key_words);
		//cout << book.key_words << endl;
		gets(book.publisher);
		//cout << book.publisher << endl;
		scanf("%s", book.publisher_year);
		//cout << book.publisher_year << endl;
		string id = book.id;
		title_map[book.title].push_back(id);
		author_map[book.author].push_back(id);
		string keys = book.key_words;
		//cout << keys << endl;
		int pos;
		while(true)
		{
			pos = keys.find(" ");
			if(pos == string::npos)
			{
				break;
			}
			string tmp = keys.substr(0, pos);
			//cout << tmp << "----" << pos << endl;
			key_words_map[tmp].push_back(id);
			keys = keys.substr(pos + 1);
		}
		key_words_map[keys].push_back(id);
		publisher_map[book.publisher].push_back(id);
		publisher_year_map[book.publisher_year].push_back(id);
	}

	int query_num;
	scanf("%d", &query_num);
	//cout << query_num << endl;
	for(int i = 0; i < query_num; i++)
	{
		int item;
		char query_str[100];
		scanf("%d: ", &item);
		gets(query_str);
		//cout << item << ": " << query_str << endl;
		printf("%d: %s\n", item, query_str);
		switch(item)
		{
			case 1:
			{
				PrintRes(title_map[query_str]);
				break;
			}
			case 2:
			{
				PrintRes(author_map[query_str]);
				break;
			}
			case 3:
			{
				PrintRes(key_words_map[query_str]);
				break;
			}
			case 4:
			{
				PrintRes(publisher_map[query_str]);
				break;
			}
			case 5:
			{
				PrintRes(publisher_year_map[query_str]);
				break;
			}
		}
	}

	system("pause");
	return 0;
}



// #include <iostream>
// #include <vector>
// #include <string>
// #include <iterator>
// #include <cmath>
// #include <map>
// #include <algorithm>
// #include <climits>
// #include <iomanip>
// #include <queue>
// #include <stack>
// #include <deque>
// #include <sstream>
// #include <set>
// #include <fstream>
// #include <cstring>
// #include <cstdio>
// #include <cstdlib>


// using namespace std;

// struct Book
// {
// 	char id[7] ;
// 	char title[85];
// 	char author[85];
// 	char key_words[55];
// 	char publisher[85];
// 	char publisher_year[4];
// };

// map<string, vector<string> > title_map;
// map<string, vector<string> > author_map;
// map<string, vector<string> > key_words_map;
// map<string, vector<string> > publisher_map;
// map<string, vector<string> > publisher_year_map;

// void PrintRes(vector<string> ans)
// {
// 	int size = ans.size();
// 	if(0 == size)
// 	{
// 		cout << "Not Found" << endl;
// 		return;
// 	}
// 	for(int i = 0; i < size; i++)
// 	{
// 		cout << ans[i];// << endl;
// 	}
// }

// int main()
// {
// 	FILE *fin = fopen("in.in", "r");
// 	int book_num;
// 	fscanf(fin, "%d", &book_num);
// 	//cout << book_num << endl;
// 	for(int i = 0; i < book_num; i++)
// 	{
// 		Book book;
// 		fscanf(fin, "%s", book.id);
// 		//cout << book.id << endl;
// 		//getchar();
// 		fgetc(fin);
// 		fgets(book.title, sizeof(book.title), fin);
// 		//cout << book.title << endl;
// 		fgets(book.author, sizeof(book.author), fin);
// 		//cout << book.author << endl;
// 		fgets(book.key_words, sizeof(book.key_words), fin);
// 		//cout << book.key_words << endl;
// 		fgets(book.publisher, sizeof(book.publisher), fin);
// 		//cout << book.publisher << endl;
// 		fscanf(fin, "%s", book.publisher_year);
// 		//cout << book.publisher_year << endl;
// 		title_map[book.title].push_back(book.id);
// 		author_map[book.author].push_back(book.id);
// 		string keys = book.key_words;
// 		int pos;
// 		while(pos = keys.find(" ") != string::npos)
// 		{
// 			string tmp = keys.substr(0, pos);
// 			key_words_map[tmp].push_back(book.id);
// 			keys = keys.substr(pos);
// 		}
// 		key_words_map[keys].push_back(book.id);
// 		publisher_map[book.publisher].push_back(book.id);
// 		publisher_year_map[book.publisher_year].push_back(book.id);
// 	}

// 	int query_num;
// 	fscanf(fin, "%d", &query_num);
// 	//cout << query_num << endl;
// 	for(int i = 0; i < query_num; i++)
// 	{
// 		int item;
// 		char query_str[100];
// 		fscanf(fin, "%d: ", &item);
// 		fgets(query_str, 100, fin);
// 		//cout << item << ": " << query_str << endl;
// 		printf("%d: %s", item, query_str);
// 		switch(item)
// 		{
// 			case 1:
// 			{
// 				PrintRes(title_map[query_str]);
// 				break;
// 			}
// 			case 2:
// 			{
// 				PrintRes(author_map[query_str]);
// 				break;
// 			}
// 			case 3:
// 			{
// 				PrintRes(key_words_map[query_str]);
// 				break;
// 			}
// 			case 4:
// 			{
// 				PrintRes(publisher_map[query_str]);
// 				break;
// 			}
// 			case 5:
// 			{
// 				PrintRes(publisher_year_map[query_str]);
// 				break;
// 			}
// 		}
// 	}

// 	system("pause");
// 	return 0;
// }