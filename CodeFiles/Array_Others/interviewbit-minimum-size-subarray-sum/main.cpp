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
    int solve(vector<int> &A,int B);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int Solution::solve(vector<int> &A, int B) 
{
    int maxElement = INT_MIN;
    long long sumofAllE = 0;
    for(int i=0;i<A.size();i++)
    {
        maxElement = max(maxElement,A[i]);
        sumofAllE += A[i];
    }
    
    int l = A.size();
    
    if(maxElement>=B)   return 1;
    if(sumofAllE<B) return 0;
    if(sumofAllE==B) return l;
    
    int s=0;
    int e=0;
    long long sumTemp = 0;
    int minLength=INT_MAX;

    sumTemp += A[s];
    
    while(s<l && e<l && s<=e)
    {

        if(sumTemp>=B)
            minLength = min(minLength,abs(e-s+1));
        
        if(sumTemp>=B)
        {
            sumTemp -= A[s];
            s++;
        }
        else
        {
            e++;
            if(e<l)
                sumTemp += A[e];
        }
    }
    
    return minLength;
}

int main()
{
    vector<int> ID;
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        int V;
        cin >> V;
        ID.push_back(V);
    }
    
    int B;
    cin >> B;
    
    Solution s;
    cout << " minimal length of a contiguous subarray is " << s.solve(ID,B);
}



