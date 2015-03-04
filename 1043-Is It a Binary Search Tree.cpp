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

TreeNode * NormalInsert(TreeNode *root, int v)
{
	if(NULL == root)
	{
		root = new TreeNode(v);
		return root;
	}

	if(v < root->val)
	{
		root->left = NormalInsert(root->left, v);
	}
	else
	{
		root->right = NormalInsert(root->right, v);
	}

	return root;
}

TreeNode *MirrorInsert(TreeNode *root, int v)
{
	if(NULL == root)
	{
		root = new TreeNode(v);
		return root;
	}

	if(v < root->val)
	{
		root->right = MirrorInsert(root->right, v);
	}
	else
	{
		root->left = MirrorInsert(root->left, v);
	}

	return root;
}

void PreOrder(TreeNode *root, vector<int> &preorder)
{
	if(NULL == root)
	{
		return;
	}
	preorder.push_back(root->val);

	if(root->left)
	{
		PreOrder(root->left, preorder);
	}

	if(root->right)
	{
		PreOrder(root->right, preorder);
	}
}

void PostOrder(TreeNode *root, vector<int> &postorder)
{
	if(NULL == root)
	{
		return;
	}

	if(root->left)
	{
		PostOrder(root->left, postorder);
	}

	if(root->right)
	{
		PostOrder(root->right, postorder);
	}

	postorder.push_back(root->val);
}

int main()
{
	ifstream in("in.in");

	int node_num;
	in >> node_num;

	vector<int> nodes_preorder;
	for(int i = 0; i < node_num; i++)
	{
		int v;
		in >> v;
		nodes_preorder.push_back(v);
	}

	TreeNode *mirror_tree = NULL;
	TreeNode *normal_tree = NULL;
	if(nodes_preorder[0] <= nodes_preorder[1])
	{
		for(int i = 0; i < node_num; i++)
		{
			mirror_tree = MirrorInsert(mirror_tree, nodes_preorder[i]);
		}
	}
	else
	{
		for(int i = 0; i < node_num; i++)
		{
			normal_tree = NormalInsert(normal_tree, nodes_preorder[i]);
		}
	}

	vector<int> mirror_preorder;
	vector<int> normal_preorder;
	PreOrder(mirror_tree, mirror_preorder);
	PreOrder(normal_tree, normal_preorder);

	if(mirror_preorder != nodes_preorder && normal_preorder != nodes_preorder)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout<< "YES" << endl;
		vector<int> postorder;
		if(mirror_preorder == nodes_preorder)
		{
			PostOrder(mirror_tree, postorder);
		}
		else
		{
			PostOrder(normal_tree, postorder);
		}

		int size = postorder.size();
		cout << postorder[0];
		for(int i = 1; i < size; i++)
		{
			cout << " " << postorder[i];
		}
	}
	system("pause");
	return 0;
}