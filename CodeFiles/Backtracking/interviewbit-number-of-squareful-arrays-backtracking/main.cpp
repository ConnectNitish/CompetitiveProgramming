/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution
{
    public : 
    int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

void getAllPermutationWithDFS(
    set<vector<int>> &setdata,
    vector<int> &data,
    int index,
    vector<bool> &visited,vector<int> &originalArray,
    int &count)
{
    data.push_back(originalArray[index]);
    visited[index]=true;
    
    bool alltrue=true;
    
    for(int i=0;i<originalArray.size();i++)
    {
        if(visited[i]==false)
        {
            alltrue=false;
            int k=1;
            for(;k<data.size();k++)
            {
                double sum = sqrt(data[k]+data[k-1]);
                // int verification = sqrt(sum)
                if((sum-(int)sum)!=0)
                {
                    break;
                }
            }
            
            if(k!=data.size())
                continue;
            
            // cout << " Caling at " << i << endl;
            getAllPermutationWithDFS(setdata,data,i,visited,originalArray,count);
        }
    }
    
    
    if(alltrue==true)
    {
        // for(auto a:data)
        //     cout << a << " ";
        // cout << endl;
        
        int i=1;
        for(;i<data.size();i++)
        {
            double sum = sqrt(data[i]+data[i-1]);
            // int verification = sqrt(sum)
            if((sum-(int)sum)!=0)
            {
                break;
            }
        }
        if(i==data.size())
        {
            // for(auto a:data)
            //     cout << a << " ";
            // cout << endl;
            setdata.insert(data);
            count++;
        }
        // return;
    }
    
    data.pop_back();
    visited[index]=false;
}

int invokedfs(vector<int> &A)
{
    set<vector<int>> setdata;
    vector<int> D;
    vector<bool> visited(A.size(),false);
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        for(int i=0;i<A.size();i++) visited[i]=false;
        getAllPermutationWithDFS(setdata,D,i,visited,A,count);
    }
    return setdata.size();
}

int Solution::solve(vector<int> &A) 
{
    vector<vector<int>> res;
    // vector<int> data;
    // int index=0;
    // int indexy=0;
    // int maxLength=A.size();
    // getAllwithRecusrion(res,A,index,indexy,maxLength,A);
    if(A.size()<=1)
        return 0;
        
    return invokedfs(A);
    
    // return res.size();
}


int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    s.solve(ID);
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}

/*
Input 1:
3 2 2 2 
Output1:

*/


