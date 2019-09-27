#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

// template<typename T> 
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

class S 
{

public:
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
		root->val=1;

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

	map<int,vector<pair<int,int>>> values;
    
    static bool _sort_function(const pair<int,int> &p1,const pair<int,int> &p2)
    {
        if(p1.first<p2.first) return true;
        if(p1.first==p2.first)
            if(p1.second<=p2.second) return true;
        return false;
    }
    
    void traverse(TreeNode* root,long long level_value,long long vertical_level)
    {
        if(root==NULL) return;
        values[level_value].push_back({vertical_level,root->val});
        traverse(root->left,level_value-1,vertical_level+1);
        traverse(root->right,level_value+1,vertical_level+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        values.clear();
        vector<vector<int>> data;
        
        traverse(root,0,0);
        
        for(auto a:values)
        {
            vector<int> res;
            // if two nodes are at same level then lower value 
            // node will be first node 
            sort(a.second.begin(),a.second.end(),_sort_function);
            for(auto b:a.second)
            {
                res.push_back(b.second);
            }
            data.push_back(res);
        }
        
        return data;
        
    }

};

int main()
{
	S s;

	struct TreeNode *root = NULL;
	root = s.createTree(root);
	
	root = s.addNodes(root);
	s.inorder(root);
	cout << endl;

	vector<vector<int>> result = s.verticalTraversal(root);

	for(auto a:result)
	{
		for(auto b:a)
		{
			cout << b << " ";
		}
		cout << endl;
	}

	return 0;
}