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
    int solve(vector<vector<int>> &A,int B);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int Solution::solve(vector<vector<int> > &A, int B) 
{
    int r = A.size();
    
    if(r<=0)
        return 0;
        
    if(to_string(B)=="")
        return 0;
    
    int c = A[0].size();
    int arr[r*c];
    
    // it may increse the range from int 
    // hence long long need to be taken 
    // int temp = (INT_MAX/B)*B;
    long long temp = (INT_MAX/B)*B;
    
    // this will not work 
    // because in the input constraint 
    // max negative number is -1000
    // so while taking mod it is problem 
    // int modvalue = (A[0][0]) % B;
    
    // hence scaling to long long level then taking 
    // in range with help of mod 
    int modvalue = (temp + A[0][0]) % B;
    
    
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i*c+j] = A[i][j];
            
            // this will not work because of 
            // reason explained above 
            // if(A[i][j]%B != modvalue)
            
            // scaling with a particular value 
            if((temp + A[i][j])%B != modvalue)
                return -1;
        }
    }
    
    sort(arr,arr+(r*c));
    
    // if we are reaching to the average value 
    // then no of operations will be very less 
    // average here refers to median of the 
    // entire elements 
    int medianValue = arr[(r*c)/2];
    
    int steps = 0;
    for(int i=0;i<(r*c);i++)
        steps += (abs(arr[i]-medianValue) / B);
     
    // if the no of element in array is even 
    // there can be two median 
    // now we need to get min operations 
    // of the two medians 
    if((r*c)%2==0)
    {
        int stepsforpreviousmedian = 0;
        medianValue = arr[((r*c)/2)-1];
        for(int i=0;i<(r*c);i++)
            stepsforpreviousmedian += (abs(arr[i]-medianValue) / B);
        
        if(steps>stepsforpreviousmedian)
            steps = stepsforpreviousmedian;
    }
    
    return steps;
}

int main()
{
    vector<vector<int>> ID;
    int r;
    int c;
    cin >> r >> c;
    for(int i=0;i<r;i++)
    {
        vector<int> d;
        for(int j=0;j<c;j++)
        {
            int V;
            cin >> V;
            d.push_back(V);
        }
        ID.push_back(d);
    }
    int B;
    cin >> B;
    
    Solution s;
    cout << " Minimum Operations " << s.solve(ID,B) << endl;
    
    return 0;
}



