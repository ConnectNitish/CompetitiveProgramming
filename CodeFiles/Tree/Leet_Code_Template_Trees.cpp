#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

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
	struct TreeNode * newNode = createNewNode(2);
	root->left = newNode;

	newNode=createNewNode(3);
	root->right = newNode;

	newNode = createNewNode(4);
	root->left->left = newNode;

	newNode=createNewNode(5);
	root->left->right = newNode;

	return root;
}

int main()
{
	struct TreeNode *root = NULL;
	root = createTree(root);
	root->val=1;
	root = addNodes(root);
	inorder(root);
	cout << endl;

	

	return 0;
}