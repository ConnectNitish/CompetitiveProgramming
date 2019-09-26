// https://leetcode.com/problems/delete-nodes-and-return-forest/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ll long long
#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

class Solution {
public:


	map<long long,long long> counts;
	map<long long,TreeNode*> parent;
	map<long long,set<pair<TreeNode*,bool>>> reverseparent;
	map<long long,bool> input;
	map<long long,TreeNode*> actual_input_node;

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

		newNode = createNewNode(6);
		root->right->left = newNode;

		newNode=createNewNode(7);
		root->right->right = newNode;

		return root;
	}

	struct TreeNode * addNodesTestCase2(struct TreeNode * root)
	{
		struct TreeNode * newNode = createNewNode(2);
		root->left = newNode;

		newNode=createNewNode(3);
		root->right = newNode;

		newNode = createNewNode(4);
		root->right->right = newNode;

		return root;
	}

	ll Traverse(TreeNode* node,TreeNode* parent_node,bool left)
	{
		if(node == NULL) return 0;
		parent[node->val] = parent_node;
		actual_input_node[node->val] = node;
		if(reverseparent.find(node->val) == reverseparent.end())
		{
			set<pair<TreeNode*,bool>> empty_value;
			reverseparent[node->val] = empty_value;
		}

		if(parent_node!=NULL)
			reverseparent[parent_node->val].insert({node,left});
		if(node->left==NULL && node->right==NULL)
		{ 
			counts[node->val] = 1;	
			return 1;
		}
		ll leftCount = Traverse(node->left,node,true);
		ll rightCount = Traverse(node->right,node,false);
		counts[node->val] = 1 + leftCount + rightCount;
		return counts[node->val]; 
	}

	int debug=1;

	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		counts.clear();
		parent.clear();
		input.clear();

		std::vector<TreeNode *> result;

		if(root->left!=NULL)
		{
			Traverse(root,NULL,true);
		}
		else if(root->right!=NULL)
		{
			if(debug)
			{
				cout << " Master : Root right is NOT NULL " << endl;
			}
			Traverse(root,NULL,false);
		}
		else if(root!=NULL)
		{
			// only one node in Tree
			int value_of_root = root->val;
			if(find(to_delete.begin(),
				to_delete.end(),value_of_root)==to_delete.end())
			{
				// not prersent;
				result.push_back(root);
				return result;
			}
		}
		else
		{
			return result;
		}

		

		for(auto item : to_delete)
		{
			input[item] = true;

			TreeNode* parent_node = parent[item];
			ll countofitembyNode = counts[item];

			if(debug)
			{
				cout << " Node to Remove: " << item ;
				cout << " Parent  Node " << ((parent_node == NULL) ? "NO Parent" : to_string(parent_node->val)) << endl; 
			}

        	// removing the Node From the Count
			// counts.erase(item);
			counts[item] = 0;
			parent.erase(item);

        	// Decreamenting all the parents with the current Value 
			TreeNode* temp_parent_node = parent_node;
			while(temp_parent_node!=NULL)
			{
				if(debug)
				{
					cout << " Loop : " << temp_parent_node->val << endl;
				}
				counts[temp_parent_node->val] -= countofitembyNode;
				temp_parent_node = parent[temp_parent_node->val];
			}

        	// performing all below Childs parent as NULL
			for(auto neighbours:reverseparent[item])
			{
				parent[neighbours.first->val] = NULL;
			}
		}

		// for(auto node_with_root:parent)
		// {
		// 	if(node_with_root.second == NULL)
		// 		cout << node_with_root.first << " $ ";
		// }

		// Get Tree 
		for(auto a:parent)
		{
			

			if(a.second == NULL)
			{

				if(input.find(a.first) != input.end())
					continue;

				if(debug)
				{
					cout << " Started Forest at " << endl;
					cout << a.first << endl;
				}

				vector<TreeNode*> nestedTree; 
				TreeNode* root_node = actual_input_node[a.first];
				TreeNode* root_temp_Node = root_node;
				nestedTree.push_back(root_node);

				queue<TreeNode*> nodes_tra;
				nodes_tra.push(root_node);

				while(nodes_tra.empty()==false)
				{
					root_node = nodes_tra.front();
					nodes_tra.pop();

					TreeNode* node_left = NULL;
					TreeNode* node_right = NULL;

					for(auto child : reverseparent[root_node->val])
					{
						if(debug)
						{
							cout << " Child " << child.first->val << " ";
							cout << child.second << endl;
						}

						if(child.second==1)
						{
							if(input.find(child.first->val) == input.end())
							{
								node_left = child.first;
							}
						}

						if(child.second==0)
						{
							if(input.find(child.first->val) == input.end())
							{
								node_right = child.first;
							}
						}
					}

					if(node_left != NULL || node_right!=NULL)
					{
						if(node_left==NULL)
						{
							// nestedTree.push_back(NULL);
							root_node->left = NULL;
						}
						else
						{
							// nestedTree.push_back(node_left);
							root_node->left = node_left;
							nodes_tra.push(node_left);
						}

						if(node_right==NULL)
						{
							// nestedTree.push_back(NULL);
							root_node->right = NULL;
						}
						else
						{
							// nestedTree.push_back(node_right);
							root_node->right = node_right;
							nodes_tra.push(node_right);
						}
					}
					else
					{
						root_node->left = NULL;
						root_node->right = NULL;
					}
				}

				actual_input_node[a.first] = root_temp_Node; 

				if(debug)
				{
					cout << " Forest Are :" << endl;
					inorder(actual_input_node[a.first]);
					cout << endl;
				}

				if(root_temp_Node!=NULL)
					result.push_back(root_temp_Node);
			}
		}


		return result;
	}
};

int main()
{
	Solution s;
	struct TreeNode *root = NULL;
	root = s.createTree(root);
	root->val=1;
	root = s.addNodes(root);
	vector<int> del_nodes = {3,5};
	
	// root = s.addNodesTestCase2(root);
	// vector<int> del_nodes = {2,1};

	s.inorder(root);
	cout << endl;


	s.delNodes(root,del_nodes);

	if(s.debug)
	{
		cout << " Parent Details" << endl;
		for(auto a:s.parent)
		{	
			if(a.second==NULL)
				cout << a.first << " : " << -1 << endl;
			else
				cout << a.first << " : " << a.second->val << endl;
		}

		cout << " Child Details" << endl;
		for(auto a:s.reverseparent)
		{	
			cout << a.first << " : ";
			for(auto ab:a.second)
			{
				cout << ab.first->val << ":";
				cout << ab.second << " ";
			}
			cout << endl;
		}

		cout << endl;

		cout << " Count Details" << endl;
		for(auto a:s.counts)
		{	
			cout << a.first << " : ";
			cout << a.second << " ";
			cout << endl;
		}

		cout << endl;
	}




	return 0;
}

