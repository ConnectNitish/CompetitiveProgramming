/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/find-the-next/

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution
{
    public : 
    vector<int> solve(vector<int> &A, vector<int> &B);
};

template<typename T>
void print(T v)
{
    cout << v << " ";
}

void for_each_loop(vector<int> v)
{
    for_each(v.begin(),v.end(),print<int>);
    cout << endl;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    
    sort(A.begin(),A.end());
    vector<int> T(A.size(),0);
    
    int maxVa = INT_MIN;
    int minVa = INT_MAX;
    
    for(int i=A.size()-1;i>=0;i--)
    {
        if(i == A.size()-1)
        {
            T[i]= A[i]+1;
        }
        else
        {
            if(A[i+1]-A[i]>1)
                T[i] = A[i]+1;
            else 
                T[i] = T[i+1];
        }
        
        maxVa = max(maxVa,A[i]);
        minVa = min(minVa,A[i]);
    }
    
    cout << " IP " << endl;
    for_each_loop(A);
    
    cout << " T " << endl;
    for_each_loop(T);
    
    cout << " Q " << endl;
    for_each_loop(B);
    
    vector<int> r;
    
    for(int i=0;i<B.size();i++)
    {
        
        if(B[i]>maxVa)
        {
            r.push_back(B[i]+1);
        }
        else if(B[i]<minVa && minVa-B[i]>1)
        {
            r.push_back(B[i]+1);
        }
        else
        {
            auto it = lower_bound(A.begin(),A.end(),B[i]);
            int index = it - A.begin();
            
            // cout << " index " << index << " B[i] "  << B[i] << endl;
            if(A[index]-B[i]>1)
            {
                r.push_back(B[i]+1);
            }
            else if(A[index]-B[i]<=1)
            {
                r.push_back(T[index]);
            }
        }
    }
    
    return r;
    
}

int main()
{
    int n1;
     int V;
    int n2;
    
    cin >> n1;
    vector<int> A;
    for(int i=0;i<n1;i++)
    {
        cin >> V;
        A.push_back(V);
    }
    
    cin >> n2;
    vector<int> B;
    for(int i=0;i<n2;i++)
    {
        cin >> V;
        B.push_back(V);
    }
    
    Solution s;
    A = s.solve(A,B);
    
    cout << " Output " << endl;
    for_each(A.begin(),A.end(),print<int>);
    
    return 0;
}

/*
Input 2 
9 15 18 15 20 10 8 5 19 2 
13 5 2 11 8 15 6 13 19 15 15 1 15 8 
Output 2 
6 3 12 9 16 7 14 21 16 16 3 16 9 
*/

/*
Input 1
7 7 14 9 6 11 12 14
7 18 14 2 18 16 2 10
Output 1 
19 15 3 19 17 3 13 
*/
