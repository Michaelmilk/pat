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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int v) : val(v), left(NULL), right(NULL){}
};

int node_num;
//the number of operation,the max value is 2 * node_num,
//push operations is node_num times, pop operations is node_num times
int idx = 0;
bool space_flag = false;
ifstream in("in.in");

TreeNode* BuildTree()
{
	TreeNode *root = NULL;

	if(idx++ < 2 * node_num)
	{
		string operation;
		in >> operation;
		if(operation == "Push")
		{
			int val;
			in >> val;
			//cout << val << endl;
			root = new TreeNode(val);
			root->left = BuildTree();
			root->right = BuildTree();
		}
	}
	
	return root;
}

void PostOrderTraveral(TreeNode *root)
{
	if(!root)
	{
		return;
	}

	PostOrderTraveral(root->left);
	PostOrderTraveral(root->right);
	if(!space_flag)
	{
		cout << root->val;
		space_flag = true;
	}
	else
	{
		cout << " " << root->val;
	}
}


int main()
{
	in >> node_num;

	TreeNode *root = BuildTree();

	PostOrderTraveral(root);

	system("pause");
	return 0;
}