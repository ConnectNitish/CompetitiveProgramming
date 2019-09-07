/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/count-of-range-sum/

*******************************************************************************/
#include <stdlib.h>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;


class Solution
{
    public : 
    int solve_TLE(vector<int> &A, int B, int C);
    int solve(vector<int> &A, int B, int C);
};

// O(n2) complexity 
int Solution::solve_TLE(vector<int> &A, int B, int C) 
{
    for(int i=0;i<A.size();i++)
    {
        if(i>0)
            A[i] += A[i-1];
    }
    
    int count=0;
    
    for(int i=0;i<A.size();i++)
    {
        for(int j=i;j<A.size();j++)
        {
            int firstPart = A[j];
            
            if(i==0)
            {
                if(B <= firstPart && firstPart <= C)
                    count++;
            }
            else
            {
                firstPart = A[j];
                int secondPart = A[i-1];
                int totalValue = firstPart - secondPart;
                if(B <= totalValue && totalValue <= C)
                    count++;
            }
        }
    }
    return count;
}

int countSub(vector<int> arr, int n, int x) 
{ 
  
    // Starting index of sliding window. 
    int st = 0; 
  
    // Ending index of sliding window. 
    int end = 0; 
  
    // Sum of elements currently present 
    // in sliding window. 
    int sum = 0; 
  
    // To store required number of subarrays. 
    int cnt = 0; 
  
    // Increment ending index of sliding 
    // window one step at a time. 
    while (end < n) { 
  
        // Update sum of sliding window on 
        // adding a new element. 
        sum += arr[end]; 
  
        // Increment starting index of sliding 
        // window until sum is greater than x. 
        while (st <= end && sum > x) { 
            sum -= arr[st]; 
            st++; 
        } 
  
        // Update count of number of subarrays. 
        cout << "sum " << sum << "Index : start " << st << " end " << end << " CNT " << cnt << endl;
        cnt += (end - st + 1); 
        cout << " CNT " << cnt << endl;
        end++; 
    } 
  
    return cnt; 
} 
  
// Function to find number of subarrays having 
// sum in the range L to R. 
int findSubSumLtoR(vector<int> &arr, int n, int L, int R) 
{ 
  
    // Number of subarrays having sum less 
    // than or equal to R. 
    int Rcnt = countSub(arr, n, R); 
    cout << " --- GAP --- " << endl;
    // Number of subarrays having sum less 
    // than or equal to L-1. 
    int Lcnt = countSub(arr, n, L - 1); 
  
    return Rcnt - Lcnt; 
} 

template<typename T>
void print(T val)
{
    cout << val << " ";
}

int Solution::solve(vector<int> &A, int B, int C) 
{
    int minVa = INT_MAX;
    
    for(int i=0;i<A.size();i++)
        minVa = min(minVa,A[i]);
        
    cout << " INPUT " << endl;
    for_each(A.begin(),A.end(),print<int>);
    cout << endl;
    
    cout << " B " << B << " C " << C << endl;
    
    if(minVa<0)
        minVa = abs(minVa)+1;
    
    if(minVa>0)
    {
        for(int i=0;i<A.size();i++)
            A[i] += minVa;
        
        B += minVa;
        C += minVa;
    }
    
    cout << " INPUT " << endl;
    for_each(A.begin(),A.end(),print<int>);
    cout << endl;
    
    cout << " B " << B << " C " << C << endl;
    
    int n1 = findSubSumLtoR(A,A.size(),B,C);
    return n1;
}



int main()
{
    vector<int> D;
    // can't be applied because all text is not data 
    //copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(D));
    
    int l;
    scanf("%d",&l);
    int i=0;
    while(i<l)
    {
        int V;
        scanf("%d",&V);
        D.push_back(V);
        i++;
    }
    int leftrange,rightrange;
    scanf("%d",&leftrange);
    scanf("%d",&rightrange);
    
    Solution s;
    int countofsumSubRange = s.solve(D,leftrange,rightrange);
 
    printf(" Number of Element in Sum Range %d",countofsumSubRange);
    
    //for_each(D.begin(),D.end(),print<int>);
    
    // s.solve(D,leftrange,rightrange);
    
    return 0;
}

/*
Input 1 : 


Output 1 : 

*/

