#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// template<typename T> 
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

// template<typename T>
struct Node* createTree(struct Node *root)
{
	if(root==NULL)
	{
		root = (struct Node *)malloc(sizeof(struct Node));
		if(root==NULL)
		{
			printf("Problem In Creating Tree");
			return NULL;
		}
	}
	return root;
}

struct Node* createNewNode(int value)
{
	struct Node * newNode = 
	(struct Node *)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void inorder(struct Node * root)
{
	if(root==NULL) return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

bool checkTwoTreeIdentical
(struct Node * root1,struct Node * root2)
{
	// if noth are NULL 
	if(root1 == root2 && root2 == NULL)
		return true;

	// if either of the tree is problem 
	if(root1==NULL || root2==NULL)
		return false;

	// if data of the Node is not equal
	if(root1->data!=root2->data)
		return false;

	// recur for left 
	bool checkLeft = 
	checkTwoTreeIdentical(root1->left,root2->left);

	// NO need to go to right 
	// if left itself is not identical 
	if(checkLeft==false)
		return false;

	// check right is not 
	// identical or not  
	bool checkRight = 
	checkTwoTreeIdentical(root1->right,root2->right);

	// if right tree is true 
	// then it will return true
	// else false 
	return checkRight;
}

struct Node * addNodes(struct Node * root)
{
	struct Node * newNode = createNewNode(2);
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
	struct Node *root = NULL;
	root = createTree(root);
	root->data=1;
	root = addNodes(root);
	inorder(root);
	cout << endl;

	struct Node *root2 = NULL;
	root2 = createTree(root2);
	root2->data=1;
	root2 = addNodes(root2);
	inorder(root2);
	
	cout << endl;

	cout << checkTwoTreeIdentical(root,root2) << endl;

	return 0;
}