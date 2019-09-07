/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits.h>
// to include function like floor ceil etc.
#include <math.h>
using namespace std;

class Solution
{
public:
int maximumGap (const vector < int >&A);

};

int Solution::maximumGap (const vector < int >&A)
{

    int mx = INT_MIN;
    int mn = INT_MAX;

    if (A.size () <= 1)
        return 0;

    for (int i = 0; i < A.size (); i++)
    {
        mx = max (A[i], mx);
        mn = min (A[i], mn);
    }

    int n=A.size();
    
    int max_b[n-1];
    int min_b[n-1];
    fill_n(max_b,n-1,INT_MIN);
    fill_n(min_b,n-1,INT_MAX);
    
    float delta = (float) (mx-mn) / (n-1); 
    
    for(int i=0;i<n;i++)
    {
        if(A[i]==mx || A[i]==mn)
            continue;
        
        int index = (float) floor((A[i]-mn) / delta);
        
        if(max_b[index]==INT_MIN)
            max_b[index] = A[i];
        else
            max_b[index] = max(max_b[index],A[i]);
            
        if(min_b[index]==INT_MAX)
            min_b[index] = A[i];
        else
            min_b[index] = min(min_b[index],A[i]);
    }

    // Finding maximum difference between maximum value 
    // of previous bucket minus minimum of current bucket. 
    int prev_val = mn; 
    int max_gap = 0; 
    for (int i = 0; i < n - 1; i++) { 
        if (min_b[i] == INT_MAX) 
            continue; 
        max_gap = max(max_gap, min_b[i] - prev_val); 
        prev_val = max_b[i]; 
    } 
    max_gap = max(max_gap, mx - prev_val); 
  
    return max_gap;

}

int main ()
{
    //taking input from cin 
    vector<int> _ID;

    //istream_iterator present in iterator
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(_ID));
    
    Solution s;
    
    cout << s.maximumGap(_ID) << endl;

    return 0;   
}
