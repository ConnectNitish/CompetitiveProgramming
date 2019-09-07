/******************************************************************************

https://www.interviewbit.com/problems/permutations/

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution
{
    public : 
    //int solve(vector<int> &A);
    vector<vector<int>> permute(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

vector<vector<int>> result;

void getAllSubsequences(int Input[],int Output[],int i,int j)
{
    if(Input[i]=='\0')
    {
        vector<int> d;
        for(int k=0;k<j;k++)
            d.push_back(Output[k]);
        result.push_back(d);
        return;
    }
    
    Output[j]=Input[i];
    getAllSubsequences(Input,Output,i+1,j+1);
    getAllSubsequences(Input,Output,i+1,j);
}

// Using DFS 
void getAllPermutations(vector<int> &D,
vector<int> &visited,int index,vector<int> &actualData)
{
    D.push_back(actualData[index]);
    visited[index]=1;
    bool isAllVisited=true;
    for(int i=0;i<actualData.size();i++)
    {
        if(visited[i]==0)
        {
            isAllVisited=false;
            getAllPermutations(D,visited,i,actualData);
        }
    }
    
    if(isAllVisited==true)
        result.push_back(D);
    
    D.pop_back();
    visited[index]=0;
}

void genAllThroughRecursion(vector<int> &Input,int levelnumber)
{
    if(levelnumber == Input.size())
    {
        result.push_back(Input);
        return;
    }
    
    for(int i=levelnumber;i<Input.size();i++)
    {
        swap(Input[i],Input[levelnumber]);
        genAllThroughRecursion(Input,levelnumber+1);
        swap(Input[i],Input[levelnumber]);
    }
}


vector<vector<int> > Solution::permute(vector<int> &A) 
{
    result.clear();
    
    /*
    
    // Method 1 
    
    vector<int> D;
    vector<int> VS(A.size(),0);
    for(int i=0;i<A.size();i++)
    {
        for(int k=0;k<A.size();k++) VS[k]=0;
        getAllPermutations(D,VS,i,A);
    }
    */
    
    // Method 2 
    genAllThroughRecursion(A,0);
    
    return result;
}



int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    vector<vector<int> > res = s.permute(ID);
    
    cout << "Print using For Each Iterator " << endl;
    for(auto ID : res)
    {
        for_each(ID.begin(),ID.end(),print<int>);
        cout << endl;
    }
}






