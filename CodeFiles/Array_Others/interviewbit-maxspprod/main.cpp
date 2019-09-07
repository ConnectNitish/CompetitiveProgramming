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
#include <stack>
using namespace std;

class Solution
{
    public : 
    int maxSpecialProduct(vector<int> &A);
    //vector<int> solve(vector<int> &A);
};

int debug=0;

template<typename T>
void print(T value)
{
    cout << value << " ";
}

int Solution::maxSpecialProduct(vector<int> &A) 
{
    vector<long long> left(A.size()+1,0);
    vector<long long> right(A.size()+1,0);
    stack<long long> s;
    
    // traversing for right array 
    for(long long i=0;i<A.size();i++)
    {
        while(s.empty()==false
        && A[i]>A[s.top()-1])
        {
            long long rightpart = s.top();
            s.pop();
            
            // with the help of stack 
            // update index wrt to all element 
            // which is lesser than this element 
            // from left side 
            right[rightpart-1]=i+1;
        }
        // stack will keep all indexes 
        s.push(i+1);
    }
    
    s=stack<long long>();
    
    for(long long i=A.size()-1;i>=0;i--)
    {
        while(s.empty()==false
        && A[i]>A[s.top()-1])
        {
            long long leftpart = s.top();
            s.pop();
            
            // with the help of stack 
            // update index wrt to all element 
            // which is lesser than this element 
            // from right side 
            
            left[leftpart-1]=i+1;
        }
        s.push(i+1);
    }
    
    if(debug)
    {
        cout << "InPut " << endl;
        for_each(A.begin(),A.end(),print<long long>);
        cout << endl;
        
        cout << " Left Array " << endl;
        for_each(left.begin(),left.end(),print<long long>); 
        cout << endl;

        cout << " Right Array " << endl;
        for_each(right.begin(),right.end(),print<long long>);        
        cout << endl;
    }
    
    long long product = 0;
    
    for(long long i=0;i<left.size();i++)
    {
        long long temp=0;
        if(left[i]>0 && right[i]>0)
        {
            // because left and right vector are 1-based index 
            temp = ((left[i]-1) * (right[i]-1)); 
        }
        product = 
        product<(temp) ? (long long)(temp) : (long long)product ;
    }
    
    return product%1000000007;
}

int main()
{
    debug = 1;
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    cout << "Max Product " << s.maxSpecialProduct(ID) << endl;

}



