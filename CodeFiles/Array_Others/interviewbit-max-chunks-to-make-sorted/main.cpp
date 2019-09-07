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
#include <limits.h>
using namespace std;

class Solution
{
    public : 
    int solve(vector<int> &A);
};

template<typename T>
void print(T value)
{
    cout << value << " ";
}
int debug = 0;

int maxPre(vector<int> &A)
{
    int max_so_far = INT_MIN;
    int count=0;
    for(int i=0;i<A.size();i++)
    {
        max_so_far = max(max_so_far,A[i]);
        if(max_so_far==i)
            count++;
    }
    return count;
}

int Solution::solve(vector<int> &A) 
{
    return maxPre(A);
}

int main()
{
    debug =1;
    
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    
    Solution s;
    cout << "Answer " << s.solve(ID) << endl;
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}


