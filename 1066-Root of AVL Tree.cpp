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

struct Node
{
	Node *left;
	Node *right;
	int val;
	int height;
	Node(int v) : val(v), left(NULL), right(NULL), height(0){}
};

int GetHeight(Node *root)
{
	return root == NULL ? -1 : root->height;
}

Node* LL(Node *root)
{
	Node *t = root->left;
	root->left = t->right;
	t->right = root;

	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;//加1是因为根节点本身还有一层
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	return t;
}

Node* RR(Node *root)
{
	Node *t = root->right;
	root->right = t->left;
	t->left = root;

	t->height = max(GetHeight(t->left), GetHeight(t->right)) + 1;
	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	return t;
}

Node* LR(Node *root)
{
	root->left = RR(root->left);
	return LL(root);
}

Node* RL(Node *root)
{
	root->right = LL(root->right);
	return RR(root);
}

Node* InsertNode(Node* root, int v)
{
	if(NULL == root)
	{
		root = new Node(v);
	}
	else
	{
		if(root->val > v)
		{
			root->left = InsertNode(root->left, v);
			if(GetHeight(root->left) - GetHeight(root->right) > 1)
			{
				if(GetHeight(root->left->left) > GetHeight(root->left->right))
				{
					root = LL(root);
				}
				else
				{
					root = LR(root);
				}
			}
		}
		else
		{
			root->right = InsertNode(root->right, v);
			if(GetHeight(root->right) - GetHeight(root->left) > 1)
			{
				if(GetHeight(root->right->right) > GetHeight(root->right->left))
				{
					root = RR(root);
				}
				else
				{
					root = RL(root);
				}
			}
		}
	}

	root->height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
	return root;
}

int main()
{
	ifstream in("in.in");
	int num;
	in >> num;
	Node *root = NULL;
	for(int i = 0; i < num; i++)
	{
		int v;
		in >> v;
		root = InsertNode(root, v);
	}
	cout << root->val << endl;
	system("pause");
	return 0;
}