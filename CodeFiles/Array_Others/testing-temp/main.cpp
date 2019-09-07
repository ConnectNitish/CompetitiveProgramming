/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

https://www.interviewbit.com/problems/inversion-count-in-an-array/

*******************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<math.h>
#include<iterator>
#include<limits.h>
#include<algorithm>
#include<string.h>
#include<numeric>
using namespace std;
int debug=0;

typedef long long llong;

const int MAXN = 200010;
llong data[MAXN]={0};
llong temp[MAXN]={0};
llong arr[MAXN]={0};
llong BIT[MAXN]={0};

int next(int i)
{
    i += (i&(-i));
    return i;
}

int prev(int i)
{
    i -= (i&(-i));
    return i;
}

llong res(llong arr[],int i)
{
    llong s=0;
    while(i>0)
    {
        s+=arr[i];
        i = prev(i);
    }
    return s;
}

void update(llong arr[],int i,int n)
{
    while(i<=n)
    {
        arr[i]++;
        i = next(i);
    }
}

class Solution
{
  public : 
  llong solve(llong A[],int size,llong arr[]);
};

llong Solution::solve(llong A[],int size,llong arr[]) 
{
    // processing of converting 
    // number to indexes which 
    // it should be in proper sorting 
    // format 
    // eg : temp = input = { 5,2,-100,1 } converts to 
    //      final arr = { 4,3,1,2 } 
    int length = size;
    
    
    // Creating till max Size of BIT array
    // not till max element 
    // because max Element is 10^9
    
    memset(BIT,0,sizeof(BIT));
    
    
    long long count=0;
    for(int i=length-1;i>=0;i--)
    // for(int i=0;i<A.size();i++)
    {
        // seeing what are lower indexes seen
        // so far from the current index
        int r =  res(BIT,arr[i]-1);
        count += r;
        // update all the next possible indexes
        // in BIT array as per index present in arr
        update(BIT,arr[i],length+1);
    }
    
    return count;
}



int main()
{
    int x = ceil(log(4761+1)/log(8));
    cout << x << endl;
}

/*
Input 1 : 
45 10 15 25 50
Output 1 :

*/


