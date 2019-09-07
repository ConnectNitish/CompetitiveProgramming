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
    //int solve(vector<int> &A);
    //vector<int> solve(vector<int> &A);
    vector<int> grayCode(int A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int debug=0;


void genGrayCode(vector<int> &res,bool zerothenone,string value,int maxLength)
{
    if(value.length() == maxLength)
    {
        int intvalue = 0;
        reverse(value.begin(),value.end());
        for(int i=0;i<value.length();i++)
        {
            intvalue = (intvalue) | ((value[i]-'0')<<i);
        }
        res.push_back(intvalue);
        return;
    }
    
    if(value=="")
    {
        genGrayCode(res,zerothenone,value+'0',maxLength);
        genGrayCode(res,!zerothenone,value+'1',maxLength);
        return;
    }
    
    if(zerothenone==true)
    {
        genGrayCode(res,zerothenone,value+'0',maxLength);
        genGrayCode(res,!zerothenone,value+'1',maxLength);
    }
    else
    {
        genGrayCode(res,!zerothenone,value+'1',maxLength);
        genGrayCode(res,zerothenone,value+'0',maxLength);
    }
}
vector<int> Solution::grayCode(int A) 
{
    vector<int> result;
    // vector<int> res;
    string str="";
    genGrayCode(result,true,str,A);
    return result;
}


int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    
   int N;
   cin >> N;
   Solution s;
   vector<int> data = s.grayCode(N);
   
   for_each(data.begin(),data.end(),print<int>);
}





