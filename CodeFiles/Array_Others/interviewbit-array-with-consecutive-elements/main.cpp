/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/array-with-consecutive-elements/

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits.h>

using namespace std;

class Solution
{
  public :   
  int solve(vector<int> &A);
};



int Solution::solve(vector<int> &A) 
{
    int l = A.size();
    if(l==0) return 0;
    
    int i=0;
    int minElement = INT_MAX;
    int xorofall = A[0];
    for(int i=0;i<l;i++)
    {
        minElement = min(minElement,A[i]);
        if(i>0)
        {
            xorofall ^= A[i];    
        }
    }    
    
    int allXor = minElement;
    
    for(int i=minElement+1;i<minElement+l;i++)
    {
        allXor ^= i;
    }
    
    if(allXor == xorofall)
        return 1;
    
    return 0;
}


int main()
{
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    cout << s.solve(ID) << endl;

    return 0;
}
