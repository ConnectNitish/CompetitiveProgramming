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

    int debug = 0;
    
    bool isValid(TreeNode* root,long long small,long long large)
    {
        if(root==NULL) return true;
        
        if(small>=root->val || root->val>=large)
        {
            if(debug)
            {
                cout << " Root-> val " << root->val << " ";
                cout << small << endl;
                cout << large << endl;
            }
            return false;
        }
            
        
        bool validate_left = isValid(root->left,small,root->val);
        
        if(validate_left == false)
            return validate_left;
        
        bool validate_right = isValid(root->right,root->val,large);
        
        return validate_right;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        return isValid(root,LONG_MIN,LONG_MAX);
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