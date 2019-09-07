/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

class Solution
{
    public : vector<int> solve(vector<int> &A);
};

vector<int> Solution::solve(vector<int> &A) 
{
    int max1= INT_MIN;
    int max1index = -1;
    int max2 = INT_MIN;
    int max2index = -2;
    
    for(int i=0;i<A.size();i++)
    {
        int V = A[i];
        if(V>=max1)
        {
            if(max1!=INT_MIN && max1>=max2)
            {
                max2 = max1;
                max2index = max1index;
            }
            max1 = V;
            max1index = i;
        }
        else if(max2<V)
        {
            max2 = V;
            max2index = i;
        }
    }
    
    /*
    if(max1index!=-1)
        A.erase(A.begin()+max1index);
    
    if(max2index!=-1)
        A.erase(A.begin()+max2index-1);
    */
    
    vector<int> r;
    for(int i=0;i<A.size();i++)
    {
        if(i!=max1index && i!=max2index)
            r.push_back(A[i]);
    }
        
    return r;
}

template<typename T>
void print(T v)
{
    cout << v << " ";
}

int main()
{
    vector<int> D;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(D));
    
    cout << "Input" << endl;
    for_each(D.begin(),D.end(),print<int>);
    
    Solution s;
    D = s.solve(D);
    
    cout << endl << "Output" << endl;
    for_each(D.begin(),D.end(),print<int>);
    
}
