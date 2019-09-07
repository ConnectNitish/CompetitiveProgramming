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

int Solution::solve(vector<int> &A) 
{
    sort(A.begin(),A.end());
    
    for(int i=A.size()-1;i>=0;i--)
    {
        int length = A.size()-i-1;
        
        length = A.end() - upper_bound(A.begin(),A.end(),A[i]);
        
        if(debug)
            cout <<  " A[i] " <<  A[i] << ":" << length << endl;
        
        if(A[i]==length)
        {
            if(debug)
                cout << A[i] << " ";
            return 1;
        }
    }
    
    return -1;
}



int main()
{
    debug = 1;
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    cout << " Answer " << s.solve(ID) << endl;
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}

/*
Input 1:
-4 7 5 3 5 -4 2 -1 -9 -8 -3 0 9 -7 -4 -10 -4 2 6 1 -2 -3 -1 -8 0 -8 -7 -3 5 -1 -8 -8 8 -1 -3 3 6 1 -8 -1 3 -9 9 -6 7 8 -6 5 0 3 -4 1 -10 6 3 -8 0 6 -9 -5 -5 -6 -3 6 -5 -4 -1 3 7 -6 5 -8 -5 4 -3 4 -6 -7 0 -3 -2 6 8 -2 -6 -7 1 4 9 2 -10 6 -2 9 2 -4 -4 4 9 5 0 4 8 -3 -9 7 -8 7 2 2 6 -9 -10 -4 -9 -5 -1 -6 9 -10 -1 1 7 7 1 -9 5 -1 -3 -3 6 7 3 -4 -5 -4 -7 9 -6 -2 1 2 -1 -7 9 0 -2 -2 5 -10 -1 6 -7 8 -5 -4 1 -9 5 9 -2 -6 -2 -9 0 3 -10 4 -6 -6 4 -3 6 -7 1 -3 -5 9 6 2 1 7 -2 5
Output 1:

Input 2:
5 6 2
Output 2:
1

*/


