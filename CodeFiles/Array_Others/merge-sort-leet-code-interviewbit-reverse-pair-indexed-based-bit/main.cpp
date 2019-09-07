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

int merge(vector<int> &A,int l,int m,int h)
{
    int index=0;
    vector<int> newData(h-l+1,0);
    
    int x=l;
    // used for counting 
    // condition 
    int y=m+1;
    
    // used for sorting the array
    int z=m+1;
    // consider the count of variables 
    int res = 0;
    
    while(x<=m)
    {
        while(y<=h && (long)(A[x])>(2*(long)A[y]))
            y++;
        // because all the elements 
        // post index y will also 
        // satisfy this condition 
        res += (y-m-1);    
        
        while(z<=h && A[x]>A[z])
            newData[index++] = A[z++];
        
        newData[index++] = A[x++];
    }
    
    while(z<=h)
        newData[index++] = A[z++];
        
    for(int i=0;i<newData.size();i++)
        A[l+i] = newData[i];
    
    return res;
    
}

int mergeSort(vector<int> &A,int l,int h)
{
    if(l>=h) return 0;
    int count = 0;
    int m = l + (h-l)/2;
    count += mergeSort(A,l,m);
    count += mergeSort(A,m+1,h);
    count += merge(A,l,m,h);
    return count;
}

int Solution::solve(vector<int> &A) 
{
    return mergeSort(A,0,A.size()-1);
}


int main()
{
    // for getting faster input 
    ios_base::sync_with_stdio(false);
    
    vector<int> ID;
    copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(ID));
    Solution s;
    s.solve(ID);
    
    cout << "Print using For Each Iterator " << endl;
    for_each(ID.begin(),ID.end(),print<int>);
}




