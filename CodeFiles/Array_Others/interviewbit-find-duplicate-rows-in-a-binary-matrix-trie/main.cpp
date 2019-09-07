// https://www.interviewbit.com/problems/find-duplicate-rows-in-a-binary-matrix/
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

template<typename T>
void print(T v)
{
    cout << v << " ";
}

class Solution
{
    public : 
    vector<int> solve(vector<vector<int> > &A);
};

vector<int> solve_TLE(vector<vector<int> > &A) 
{
    set<int> r;
    
    for(int i=0;i<A.size();i++)
    {
        vector<int> r1 = A[i];
        for(int j=i+1;j<A.size();j++)
        {
            vector<int> r2 = A[j];
            bool equal;
            for(int k=0;k<r2.size();k++)
            {
                if(r1[k]!=r2[k])
                {
                    equal = false;
                    break;
                }
                equal = true;
            }
            
            if(equal==true)
            {
                r.insert(j+1);
                //A[j].clear();
            }
        }
    }
    
    vector<int> r1;
    
    for(auto a:r)
        r1.push_back(a);
    
    return r1;
}

vector<int> solve_wrongApproach(vector<vector<int> > &A) 
{
    set<int> r;
    
    vector<vector<int>> B = A;
    
    for(int i=0;i<A.size();i++)
    {
        vector<int> r1 = A[i];
        int sum = 0;
        for(int j=0;j<r1.size();j++)
        {
            if(j==0)
            {
                sum += (r1.size()*r1[j]);
            }
            else
            {
                sum += (j*r1[j]);                
            }
        }
        A[i].clear();
        A[i].push_back(sum);
    }
    
    for(int i=0;i<A.size();i++)
    {
        // cout << i << " : " << A[i][0] << endl;
    }
    
    for(int i=0;i<A.size();i++)
    {
        vector<int> r1 = A[i];
        for(int j=i+1;j<A.size();j++)
        {
            vector<int> r2 = A[j];
            if(r1.size()>0 && r2.size()>0)
            {
                
                if(r1[0] == r2[0])
                {
                    
                    // for_each(B[i].begin(),B[i].end(),print<int>);
                    // cout << endl;
                    // for_each(B[j].begin(),B[j].end(),print<int>);
                    // cout << endl;
                    
                    // cout << "i:" << i << " j:" << j << ":" << r1[0] << ":" << r2[0] << ":" << (r1[0]==r2[0]) << endl;
                    
                    r.insert(j+1);
                }
            }
        }
    }
    
    vector<int> r1;
    
    for(auto a:r)
        r1.push_back(a);
    
    return r1;
}



struct TrieNode
{
    bool endofword;
    TrieNode* ref[2];
};

class TrieStructure
{

public : 

TrieNode* createNode()
{
    TrieNode* node = new TrieNode;
    node->endofword=false;
    node->ref[0] = node->ref[1] = NULL;
    return node;
}

TrieNode* insert_debug(vector<int> d,int size,TrieNode* root)
{
    
    cout << " For vector " << endl;
    for_each(d.begin(),d.end(),print<int>);
    cout << endl;
    
    TrieNode* head = root;
    
    for(int i=0;i<size;i++)
    {
        int number = d[i];
        
        if(head==NULL)
        {
            cout << " Head is NULL " << endl;
            head = createNode();
            root = head;
        }
        
        if(head->ref[number]==NULL)
        {
            cout << " Head is NOT NULL CREATING  " << number << endl;
            head->ref[number] = createNode();
        }
        
        cout << " End of Word " << head->endofword << endl;
        
        head = head->ref[number];
    }
    
    cout << " End of Word Final  " << head->endofword << endl;
    
    head->endofword = true;
    
    cout << " End of Word Final " << head->endofword << endl;
    
    
    return root;
}

bool search_debug(vector<int> d,int size,TrieNode* root)
{
    TrieNode* head = root;
    
    for(int i=0;i<size;i++)
    {
        // cout << " Search Test " << endl;
        int number = d[i];
        if(head==NULL)
            return false;
        head = head->ref[number];
    }
    return head->endofword;
    
}

TrieNode* insert(vector<int> d,int size,TrieNode* root)
{
    TrieNode* head = root;
    
    for(int i=0;i<size;i++)
    {
        int number = d[i];
        
        if(head==NULL)
        {
            head = createNode();
            root = head;
        }
        
        if(head->ref[number]==NULL)
        {
            head->ref[number] = createNode();
        }
        head = head->ref[number];
    }

    head->endofword = true;
    return root;
}

bool search(vector<int> d,int size,TrieNode* root)
{
    TrieNode* head = root;
    
    for(int i=0;i<size;i++)
    {
        int number = d[i];
        if(head==NULL)
            return false;
        head = head->ref[number];
    }
    return head->endofword;
    
}

};

vector<int> Solution::solve(vector<vector<int> > &d) 
{
    vector<int> rs;
    TrieStructure ts;
    TrieNode * root = NULL;
    for(int i=0;i<d.size();i++)
    {
        
        if(ts.search(d[i],d[i].size(),root)==false)
        {
            root = ts.insert(d[i],d[i].size(),root);
        }
        else
        {
            rs.push_back(i+1);
        }
    }
    
    return rs;
}

int main()
{
    int r,c;
    cin >> r >> c;
    
    vector<vector<int>> d(r,vector<int>(c,0));
    
    for(int i=0;i<r;i++)
    {
        
        for(int j=0;j<c;j++)
        {
            int v;
            cin >> v;
            d[i][j] = v;
        }
    }
    
    Solution s;
    vector<int> re = s.solve(d);
    
    cout << "Output" << endl;
    for_each(re.begin(),re.end(),print<int>);
    
}

/*

47 38 1 0 0 0 1 1 0 1 1 0 0 1 0 0 1 0 1 0 1 1 0 0 1 1 1 1 0 0 0 1 1 0 0 0 1 1 0 0 1 1 0 1 0 0 1 1 1 0 1 1 1 0 0 1 1 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 1 1 0 0 0 0 0 0 1 1 0 0 1 1 1 1 0 0 1 1 1 1 1 1 0 1 0 1 1 1 1 1 1 1 0 0 1 0 1 0 0 1 1 0 1 0 0 1 1 1 0 1 1 1 0 0 1 1 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 1 1 0 0 1 0 0 0 1 0 0 1 0 0 0 1 1 1 0 0 1 1 1 0 0 1 1 1 0 1 1 0 1 1 1 0 0 1 1 0 0 1 1 1 1 1 1 0 0 0 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 1 0 1 1 0 1 0 1 1 1 0 0 0 1 1 0 1 0 0 1 1 1 0 1 1 1 0 0 1 1 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 1 1 0 0 1 1 0 0 1 1 1 0 1 1 0 1 0 1 0 0 0 1 0 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 1 1 1 1 1 1 0 1 1 0 0 1 0 1 0 0 1 0 1 1 0 0 0 1 0 0 1 0 1 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0 1 0 0 0 0 1 0 1 1 1 0 0 0 1 1 0 0 1 1 1 0 1 0 0 0 0 0 0 1 1 1 0 0 1 0 1 0 0 0 0 1 0 0 1 1 0 1 1 0 1 1 0 1 0 0 1 0 0 1 1 0 0 0 1 0 1 0 0 1 0 0 1 1 0 1 1 1 0 1 1 1 0 1 0 0 0 0 1 0 0 0 1 1 1 0 0 0 1 1 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 1 1 1 0 1 1 1 1 0 1 0 0 0 1 0 1 1 0 0 1 0 0 1 0 0 1 0 1 1 0 1 1 1 0 0 1 1 0 0 0 0 0 1 0 1 1 1 0 1 1 0 1 1 1 1 0 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 0 1 1 0 1 0 0 0 0 0 1 1 0 1 0 0 0 0 0 0 0 0 0 1 1 0 1 0 0 0 1 0 1 0 0 0 0 1 1 1 1 1 1 1 0 1 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 0 0 0 0 1 1 1 0 1 0 0 0 1 1 0 1 1 1 0 0 0 1 0 0 0 0 0 1 1 1 0 1 1 1 1 1 1 1 0 1 1 1 0 0 0 0 1 0 1 1 1 1 0 1 0 1 0 1 1 0 0 0 0 0 1 1 1 1 0 0 0 1 1 0 0 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 0 0 1 0 0 1 0 1 1 1 0 1 1 0 1 1 0 1 0 0 1 0 0 1 1 0 1 0 0 1 1 1 1 0 0 1 1 1 1 1 0 1 0 0 0 1 0 0 0 0 0 1 1 1 1 1 0 0 1 0 1 1 1 0 1 1 1 1 0 1 1 1 1 1 1 0 1 0 1 0 1 0 0 0 1 0 0 1 1 0 1 0 0 1 1 1 1 1 1 1 0 1 1 1 0 0 0 0 1 0 1 1 1 1 0 1 0 1 0 1 1 0 0 0 0 0 1 1 1 1 0 0 1 0 1 0 1 1 0 1 1 0 1 1 1 1 1 1 0 1 0 0 1 0 0 0 1 1 0 1 0 1 1 1 1 1 1 0 0 0 1 1 0 1 0 0 1 1 1 0 1 1 1 0 0 1 1 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 1 1 0 0 1 1 0 0 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 0 0 1 0 0 1 0 1 1 1 0 1 1 0 1 1 0 1 0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 1 0 0 1 1 1 1 0 1 1 0 1 1 1 0 1 1 0 1 0 0 1 1 1 1 0 0 0 1 1 1 0 1 0 0 0 1 0 0 1 1 0 1 1 0 1 0 0 0 0 0 1 1 0 1 0 0 0 1 1 0 0 0 1 0 0 1 0 1 1 1 1 0 0 1 0 1 0 0 1 0 1 1 1 1 1 0 0 1 0 1 0 0 0 1 0 0 0 1 0 1 0 0 1 0 1 0 0 1 0 0 0 0 0 0 1 1 1 0 1 0 1 0 1 1 1 1 0 0 1 0 1 0 0 1 0 1 0 1 0 0 0 0 1 0 1 0 1 1 0 1 0 1 0 1 0 0 1 1 1 1 0 1 1 0 1 0 1 0 1 1 1 0 0 1 0 0 1 0 1 0 0 1 0 1 0 1 1 0 0 0 0 0 1 0 0 0 0 0 0 1 1 1 0 0 1 0 1 0 1 1 1 0 0 1 1 1 1 0 1 0 1 0 0 0 1 1 0 1 0 1 1 1 0 1 1 1 1 1 0 1 1 1 1 0 0 1 0 0 0 1 0 0 1 1 0 1 0 0 1 1 1 1 0 0 1 1 1 1 1 0 1 0 0 0 1 0 0 0 0 0 1 1 1 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 0 1 1 0 1 1 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 1 1 0 1 0 1 0 0 1 0 0 1 1 0 0 0 1 0 1 0 0 1 0 0 1 1 0 1 1 1 0 1 1 1 0 1 0 0 0 0 1 0 0 1 0 1 0 0 1 1 0 0 0 0 0 1 1 0 1 0 1 1 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 1 1 0 0 1 1 1 1 1 1 0 1 1 0 0 0 1 0 1 0 1 0 0 0 0 0 0 1 0 1 0 1 0 1 0 0 0 0 1 1 1 0 0 0 1 0 0 1 0 1 1 1 0 1 1 1 1 1 1 1 0 0 0 0 0 1 0 0 0 0 1 0 1 1 1 0 0 1 1 1 0 1 0 1 0 1 0 0 0 1 0 1 0 1 0 1 0 0 1 0 1 0 1 1 0 1 0 1 0 0 0 1 1 0 1 1 0 1 0 0 1 0 1 0 1 1 1 1 1 0 1 0 0 0 0 1 1 0 1 1 0 0 0 0 0 0 1 0 1 0 0 1 1 0 1 1 0 0 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 0 0 1 0 0 1 0 1 1 1 0 1 1 0 1 1 0 1 0 0 0 1 1 0 1 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 1 0 1 0 0 1 1 0 1 1 1 1 1 0 1 0 0 1 1 0 0 0 1 0 0 0 1 0 1 1 1 1 1 0 1 0 0 0 1 0 0 1 0 1 1 1 0 1 1 0 1 1 0 1 1 1 0 0 0 1 0 0 1 0 1 1 1 1 0 0 1 0 1 0 0 1 0 1 1 1 1 1 0 0 1 0 1 0 0 0 1 0 0 0 0 0 0 1 1 0 0 1 1 1 1 0 0 1 1 1 1 1 1 0 1 0 1 1 1 1 1 1 1 0 0 1 0 1 0 0 0 1 1 0 1 0 1 1 1 0 0 1 0 1 1 1 0 1 0 1 1 1 0 1 0 0 1 0 1 1 1 0 0 0 0 1 1 1 0 0 1 0 1 0 1 0 0 1 1 0 1 1 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 



*/


