/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/palindromic-substrings-count/

*******************************************************************************/
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
 public:
 int solve(string A);
};

bool checkPalindrome(string A,int s,int e)
{
    while(s>=0 && e<A.length() && s<=e)
    {
        if(A[s]!=A[e])
            return false;
        s++;
        e--;
    }
    return true;
}

int count1=0;

void getAllpalindrome(string A,int index,vector<string> &res
,vector<vector<string>> &f)
{

    if(index==A.length())
    {
        f.push_back(res);
        return;
    }
    
    for(int i=index;i<A.length();i++)
    {
        if(checkPalindrome(A,index,i))
        {
            res.push_back(A.substr(index,i-index+1));
            getAllpalindrome(A,i+1,res,f);
            res.pop_back();
        }
    }
}

template<typename T>
void print(T v)
{
    cout << v << " ";
}

int Solution::solve(string A) 
{
    vector<string> test;
    vector<vector<string>> ans;
    getAllpalindrome(A,0,test,ans);
    
    cout << " Output " << endl;
    for_each(test.begin(),test.end(),print<string>);
    cout << endl;
    
    int count=0;
    
    for(auto a:ans)
    {
        count+=a.size();    
    }
    
    return count;
}

int main()
{
    string str;
    getline(cin,str);
    Solution s;
    cout << "Count of Palindromes " << s.solve(str) << endl;
    return 0;
}