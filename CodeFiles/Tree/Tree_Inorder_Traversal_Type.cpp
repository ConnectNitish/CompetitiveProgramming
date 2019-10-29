#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<climits>
using namespace std;

// https://leetcode.com/problems/validate-binary-search-tree/submissions/

// template<typename T> 
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

// template<typename T>
struct TreeNode* createTree(struct TreeNode *root)
{
	if(root==NULL)
	{
		root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
		if(root==NULL)
		{
			printf("Problem In Creating Tree");
			return NULL;
		}
	}
	return root;
}

struct TreeNode* createNewNode(int value)
{
	struct TreeNode * newNode = 
	(struct TreeNode *)malloc(sizeof(struct TreeNode));
	newNode->val = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void inorder(struct TreeNode * root)
{
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->val);
	inorder(root->right);
}

struct TreeNode * addNodes(struct TreeNode * root)
{
	root->val=2;

	struct TreeNode * newNode = createNewNode(1);
	root->left = newNode;

	newNode=createNewNode(3);
	root->right = newNode;

	return root;
}

void InorderIterative(TreeNode* root)
{
	if(root==NULL) return;
	stack<TreeNode*> stck;

	stck.push(root);

	vector<int> inorder_traversal;

	while(stck.empty()==false)
	{
		TreeNode* stack_top = stck.top();

		while(stack_top->left!=NULL)
		{
			stck.push(stack_top->left);
			stack_top = stack_top->left;
		}

		inorder_traversal.push_back(stck.top()->val);

		stack_top.pop();
	}
}

int main()
{
	struct TreeNode *root = NULL;
	root = createTree(root);
	root = addNodes(root);
	inorder(root);
	cout << endl;

	cout << isValidBST(root) << endl;

	return 0;
}