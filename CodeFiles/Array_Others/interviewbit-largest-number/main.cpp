/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int getfirstChar(int n)
{
    int t=n;
    int last = 0;
    while(t>0)
    {
        last = t;
        t = t/10;
    }
    return last;
}

// true if n1n2 is bigger 
// false if n2n1 is bigger
bool c(int n1,int n2)
{
    string sn1 = to_string(n1);
    string sn2 = to_string(n2);
    
    string sn1n2 = sn1+sn2;
    string sn2n1 = sn2+sn1;
    
    for(int i=0;i<sn1n2.length();i++)
    {
        if(sn1n2[i]>sn2n1[i])
            return true;
        else if(sn1n2[i]<sn2n1[i])
            return false;
    }
    
    return true;
}

bool _sortf(const pair<int,int> p1,const pair<int,int> p2)
{
    if(p1.second>p2.second)
        return true;
    else if(p1.second==p2.second)
    {
        if(p1.first!=p2.first)
            return c(p1.first,p2.first);
        else if(p1.first==p2.first)
            return true;
    }
    return false;
}

class Solution
{
  public : 
    string largestNumber(const vector<int> &A); 
  
};

string Solution::largestNumber(const vector<int> &A) 
{
    vector<pair<int,int>> d;
    
    for(int i=0;i<A.size();i++)
    {
        d.push_back({A[i],getfirstChar(A[i])});    
    }
    sort(d.begin(),d.end(),_sortf);
    
    string s="";
    
    int count=0;
    
    for(auto a: d)
    {
        s += to_string(a.first);
        if(a.first==0)
            count++;
    }
    
    if(count==d.size())
        return "0";
        
    return s;
}

int main()
{
    vector<int> D;
    
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(D));
    
    Solution s;
    cout << s.largestNumber(D) << endl;
    
    return 0;
}
/*

Input 1 : 
5 9 30 34 5
Output 1: 
9553430
*/
