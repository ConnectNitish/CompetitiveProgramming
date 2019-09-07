/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<vector>
using namespace std;

int bSearchrec(vector<int> d,int s,int e,int k)
{
    if(s<=e)
    {
        int m = e + ( s-e )/2;
        if(d[m]==k)
            return m;
        else if(d[m]>k)
            return bSearchrec(d,s,m-1,k);
        else 
            return bSearchrec(d,m+1,e,k);
    }
    return -1;
}

int bSearchIterative(vector<int> d,int k)
{
    int s=0;
    int e=d.size()-1;
    int m;
    while(s<=e)
    {
        m = e + (s-e)/2;
        if(d[m]==k)
            return m;
        else if(d[m]>k)
            e = m-1;
        else
            s = m+1;
    }
    return -1;
}

int bSearchFirstOcc(vector<int> d,int k)
{
    int s=0;
    int e=d.size()-1;
    
    while(s<=e)
    {
        int m=e+((s-e)/2);
        if(d[m]==k)
        {
            if((m-1)>=0 && d[m-1]==k)
                e = m-1;
            else
                return m;
        }
        else if(d[m]<k)
            s= m+1;
        else
            e = m-1;
    }
    return -1;
}

int bSearchLastOcc(vector<int> d,int k)
{
    int s=0;
    int e=d.size()-1;
    
    while(s<=e)
    {
        int m=e+((s-e)/2);
        if(d[m]==k)
        {
            if((m+1)<d.size() && d[m+1]==k)
                s = m+1;
            else
                return m;
        }
        else if(d[m]<k)
            s= m+1;
        else
            e = m-1;
    }
    return -1;
}

int noofOcc(vector<int> d,int k)
{
    int left = bSearchFirstOcc(d,k);
    int right = bSearchLastOcc(d,k);
    if(left ==-1 || right == -1)
        return 0;
    return (right-left+1);
}

int main()
{
    int count=0;
    vector<int> d;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        d.push_back(n);
        count++;
    }
    
    // input 1 2 2 2 2 2 2 2 10
    int tofind = 2;
    
    printf("Recursion Index of Element %d is : %d\n",tofind,bSearchrec(d,0,count-1,tofind));
    printf("Iterative Index of Element %d is : %d\n",tofind,bSearchIterative(d,tofind));
    printf("Iterative First Index of Element %d is : %d\n",tofind,bSearchFirstOcc(d,tofind));
    printf("Iterative Last Index of Element %d is : %d\n",tofind,bSearchLastOcc(d,tofind));
    printf("Total no of Occurence of Element %d is : %d\n",tofind,noofOcc(d,tofind));

    return 0;
}

