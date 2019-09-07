/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/count-pairs-in-array-whose-sum-is-divisible-by-the-given-number/

*******************************************************************************/
#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int mod = 1000000007;

class Solution
{
    public : 
    int solve(vector<int> &A, int B); 
};

int Solution::solve(vector<int> &A, int B) 
{
    int size = B/2;
    bool odd = ((B&1)==0) ? false : true;
    
    //unordered_map<int,vector<int>> m;
    long long int cm[B];
    for(int i=0;i<B;i++)
        cm[i]=0;
    //memset(cm,0,sizeof(cm));
    
    for(int i=0;i<A.size();i++)
    {
        int mod1 = (A[i]%B);
        //m[mod1].push_back(A[i]);
        cm[mod1]++;
        //cm[mod1] = cm[mod1]%mod;
    }
    
    long long int count=0;
    /*
    for(auto a:m)
    {
        int index = a.first;
        if(index==0 && a.second.size()>0)
        {
            int n = a.second.size();
            count += ((n%mod * (n-1)%mod)%mod/2)%mod;    
        }
        else if(B-index == index)
        {
            int n = a.second.size();
            count += ((n%mod * (n-1)%mod)%mod/2)%mod; 
        }
        else if(m[B-index].size()>0 && a.second.size()>0)
        {
            count += (a.second.size()%mod * m[B-index].size()%mod)%mod;
            m[B-index].clear();
        }
        a.second.clear();
    }
    */
    // if(count%2==1)
    //     return (count/2)+1;
    
    bool TLE = false;
    
    if(cm[0]>0)
    {
        if(TLE)
            count = (count + (((long long)( cm[0] * (cm[0]-1) ) % mod) / 2)%mod)%mod;
        else
            count += ((cm[0] * (cm[0]-1))/2);
    }
    
    for(int i=1;i<=(B/2) && i!=(B-i);i++)
    {
        if(TLE)
            count = (count + (((long long)( cm[i] * (cm[B-i]) ) % mod))%mod)%mod;
        else
            count += ((cm[i] * (cm[B-i])));
    }
    
    if(B%2==0)
    {
        if(TLE)
            count = (count + (((long long)( cm[B/2] * (cm[B/2]-1) ) % mod) / 2)%mod)%mod;
        else
            count += ((cm[B/2] * (cm[B/2]-1))/2);
    }
    
    return (count%mod);
    
}


int main()
{
    int V;
    cin >> V;
    
    int i=0;
    vector<int> ID;
    while(i<V)
    {
        int value;
        cin >> value;
        ID.push_back(value);
        i++;
    }
    int B;
    cin >> B;
    
    Solution s;
    cout << s.solve(ID,B) << endl;
    return 0;
}
